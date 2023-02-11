/* Documentation
Name : Shreya Gupta
Date : 26/1/23
Description : Steganography
Sample Execution :
1. For Encoding
$ ./a.out -e beautiful.bmp secret.txt 
Choosen Encoding
Output file not mentioned . Created stego.bmp as deafult
Read and validate encode arguments is a success
##  ENCODING STARTED  ##
Open files is a success
width = 1024
height = 768
Check capacity is a success
Bmp header copied successfully
Success : Encoding magic string
Success : Encoding secret file extn size
Success : Encoding secret file extn
Success : Encoding secret file size
Success : Encoding secret file data
Success : Encoded remaining data
## ENCODING DONE ##

2. For Decoding
$ ./a.out -d stego.bmp 
Choosen Decoding
Output file not mentioned. Creating decode.txt as default
Read and validate decode arguments is a success
## DECODING STARTED ##
Open files is a success
Success : Decoding magic string
Success : Decoding file extension size
Success : Decoding Secret File Extension
Success : Decoding secret file size
Success :Decoding secret file data
## DECODING DONE ##
*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{

   //checking for the argc
   if (argc >= 3)
   {

    // Function call for check operation type
    if (check_operation_type(argv) == e_encode)
    {
        printf("Choosen Encoding\n");

        // Declare structure variable
        EncodeInfo encInfo;
        // Read and validate encode arguments 
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("Read and validate encode arguments is a success\n");
            printf("##  ENCODING STARTED  ##\n");

            // Function call for encoding
            if (do_encoding(&encInfo) == e_success)
            {
                printf("## ENCODING DONE ##\n");
            }
            else
            {
                printf("Failed to encode\n");
                return 1;
            }
        }
        else
        {
            printf("Read and validate encode arguments is a failure\n");
            return 1;
        }
    }
    // Function call for check operation type
    else if (check_operation_type(argv) == e_decode)
    {
        printf("Choosen Decoding\n");

        // Declare structure variables
        DecodeInfo decInfo;
        if (read_and_validate_decode_args(argv, &decInfo) == d_success)
        {
            printf("Read and validate decode arguments is a success\n");
            printf("## DECODING STARTED ##\n");

            // Function call for do decoding
            if (do_decoding(&decInfo) == d_success)
            {
                printf("## DECODING DONE ##\n");
            }
            else
            {
                printf("Failed to decode\n");
                return 1;
            }
        }  
        else
        {
            printf("Read and validate decode arguments is a failure\n");
            return 1;
        }
    } 
    else
    {
        printf("Invalid optionS\nPlease pass for\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp \n");
    }
  }
 else
 {
        printf("Error : Please pass for\nEncoding: 4 arguments\nDecoding: 3 arguments\n");
 }

    return 0;
}
			




