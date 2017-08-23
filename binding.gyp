{
  "targets": [
  {
    "target_name": "nodeh264ffmpeg",
      "sources": [  
        "node-h264-vaapi.cc", 
      "functions.cc" 
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"

      ],
      "cflags" : [
        "-Wall",
        "-g",
        "-O0"
      ],
      "link_settings": {
        "libraries": []
      }


  }

  ],

}
