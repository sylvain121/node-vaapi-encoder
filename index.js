var nodeH264vaapi = require('bindings')('nodeh264vaapi');

module.exports.YUV_420P = 1;
module.exports.YUV_444P = 2;


module.exports.initSync = function(options) {
    console.log(options.sample);
    nodeH264vaapi.init(options.inputWidth,
        options.inputHeight,
        options.outputWidth,
        options.outputHeight,
        options.bit_rate,
        options.fps,
        options.sample
    );

}

module.exports.encodeFrameSync = function(frameData) {
    return nodeH264vaapi.encodeFrame(frameData);
}
