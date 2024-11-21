#include <string.h>

// Function to calculate the size of a video
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Constants for bits per pixel
    const int BITS_PER_PIXEL_COLOR = 24; // 24 bits for colored (RGB)
    const int BITS_PER_PIXEL_BW = 8;     // 8 bits for black and white (grayscale)

    // Calculate total number of frames
    int totalFramesMovie = durationMovie * fps;  // Total frames for the movie
    int totalFramesCredits = durationCredits * fps;  // Total frames for the credits

    // Calculate size in bits for each section
    float sizeMovieBits = (float)(w * h * BITS_PER_PIXEL_COLOR * totalFramesMovie);
    float sizeCreditsBits = (float)(w * h * BITS_PER_PIXEL_BW * totalFramesCredits);

    // Total size in bits
    float totalSizeBits = sizeMovieBits + sizeCreditsBits;

    // Convert to the requested unit
    if (strcmp(unit, "bt") == 0) { // Bytes
        return totalSizeBits / 8.0;
    } else if (strcmp(unit, "ko") == 0) { // Kilobytes
        return (totalSizeBits / 8.0) / 1024.0;
    } else if (strcmp(unit, "mo") == 0) { // Megabytes
        return (totalSizeBits / 8.0) / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) { // Gigabytes
        return (totalSizeBits / 8.0) / (1024.0 * 1024.0 * 1024.0);
    } else {
        // Invalid unit
        return -1.0; // Return -1 to indicate an error
    }
}
