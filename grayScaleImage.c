#include <stdio.h>

// Function to calculate the size of a grayscale image
float grayScaleImage(int w, int h) {
    float sizeInBytes = (float)(w * h); // width * height * 1 byte per pixel
    return sizeInBytes;
}

