#include <string.h>

// Function to calculate the size of a colored Bitmap image
float coloredBitmap(int w, int h, char* unit) {
    // Each pixel in a colored image is typically encoded in 24 bits (3 bytes for RGB)
    float sizeInBits = (float)(w * h * 24); // Width * Height * 24 bits per pixel

    // Convert based on the specified unit
    if (strcmp(unit, "bt") == 0) { 
        return sizeInBits;
    } else if (strcmp(unit, "ko") == 0) { 
        return sizeInBits / 1024.0;
    } else if (strcmp(unit, "mo") == 0) { 
        return sizeInBits / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) { 
        return sizeInBits / (1024.0 * 1024.0 * 1024.0);
    } else {
        // Invalid unit
        return -1; // Return -1 to indicate an error
    }
}
