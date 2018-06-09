# photo_message_encryption
Accepts a JPEG image and message to be encrypted, encrypts the message into the JPEG image.

This is a photo steganographic encoder, in which the program will accept the name of an image and a message to be encoded. The message will then be entered into the image, reading two bits from each char in the message, and setting those bits as the two least significant bits (lsb's) of each byte in the image.

For more information on the topic, view this video by Numberphile: https://www.youtube.com/watch?v=TWEXCYQKyDc
