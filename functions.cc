#include "functions.h"
#include "encoder_vaapi.h"

NAN_METHOD(init) {

  if(info.Length() < 6){
    return Nan::ThrowError(Nan::TypeError("Too few arguments"));
  }
  int inputWidth = info[0]->NumberValue();
  int inputHeight = info[1]->NumberValue();
  int outputWidth= info[2]->NumberValue();
  int outputHeight = info[3]->NumberValue();
  int bit_rate = info[4]->NumberValue();
  int fps = info[5]->NumberValue();  
  int pix_fmt_int = info[6]->NumberValue();

  encoder_init(&inputWidth, &inputHeight, &outputWidth, &outputHeight, &bit_rate, &fps, pix_fmt_int);

}

NAN_METHOD(encodeFrame) {

  if(info.Length() < 1) {
    return Nan::ThrowError(Nan::TypeError("Too few arguments"));
  }
  v8::Local<v8::Object> srcObject = info[0].As<v8::Object>();
  if(!node::Buffer::HasInstance(srcObject)) {
    return Nan::ThrowError(Nan::TypeError("Invalid source buffer"));
  }

  unsigned char * srcData[1] = {(unsigned char*) node::Buffer::Data(srcObject)}; 
  //output buffer
  v8::Local<v8::Object>  dstObject;

  unsigned char * dstData = NULL;
  unsigned long frameSize = 0;

  encoder_encodeFrame( srcData, &dstData, &frameSize);

  if(frameSize > 0 && dstData != NULL ) {
    dstObject = Nan::CopyBuffer((char *) dstData, frameSize).ToLocalChecked();
    info.GetReturnValue().Set(dstObject);
    free_av_packet(); 
  }
}
