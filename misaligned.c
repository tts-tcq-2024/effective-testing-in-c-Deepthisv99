#include <stdio.h>
#include <assert.h>
#include <string.h>

// Function to generate color mappings
int printColorMap(char *outputBuffer, size_t bufferSize) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    char tempBuffer[50];
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            snprintf(tempBuffer, sizeof(tempBuffer), "%2d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            strncat(outputBuffer, tempBuffer, bufferSize - strlen(outputBuffer) - 1);
        }
    }
    return i * j;
}

int main() {
    char buffer[1000] = {0};
    int result = printColorMap(buffer, sizeof(buffer));
    assert(result == 25);
    // Check alignment of numbers
    assert(strncmp(buffer, " 0 | White | Blue", 17) == 0); // This should fail due to misalignment
    printf("%s", buffer);
    printf("All is well (maybe!)\n");
    return 0;
}

