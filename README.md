# photo_message_encryption
Accepts a JPEG image and message to be encrypted, encrypts the message into the JPEG image.

This is a photo steganographic encoder, in which the program will accept the name of an image and a message to be encoded. The message will then be entered into the image, reading two bits from each char in the message, and setting those bits as the two least significant bits (lsb's) of each byte in the image.

For more information on steganographic encoding, view [this video by Numberphile](https://www.youtube.com/watch?v=TWEXCYQKyDc)

### Accepts all modern image file types (the following have been tested):
  - all .jpg and .jpeg variants (.jpe/.jif/.jfif/.jfi)
  - .bmp
  - .png
  - .psd
  - .gif
  - .tiff
  - .heif
  
## Instructions
### To Compile:
  `$ make`
  
### To Encode:
  `$ ./pencode [ image filename ] [ message ]`
  
### To Decode:
  `$ ./pdecode [ image filename ]`

## Current Progress
- [x] Encode
- [ ] Decode
- [ ] stdin/files for message input
