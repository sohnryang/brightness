/*
 * Brightness -- Change the screen brightness
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    FILE* input =
        fopen("/sys/class/backlight/intel_backlight/brightness", "r");
    FILE* output =
        fopen("/sys/class/backlight/intel_backlight/brightness", "w");
    int current_brightness;
    fscanf(input, "%d", &current_brightness);
    if (strcmp(argv[1], "up") == 0) current_brightness += 500;
    else current_brightness -= 500;
    fprintf(output, "%d", current_brightness);
    fclose(input);
    fclose(output);
    return 0;
}
