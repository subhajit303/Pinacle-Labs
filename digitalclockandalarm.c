#include <stdio.h>
#include <time.h>
#include <unistd.h>  // for sleep() function

void display_clock() {
    time_t current_time;
    struct tm *time_info;

    current_time = time(NULL);
    time_info = localtime(&current_time);

    printf("\r%02d:%02d:%02d", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
    fflush(stdout);  // Force output to be displayed immediately
}

int main() {
    // Set an alarm time (modify this for testing)
    int alarm_hour = 8;
    int alarm_minute = 17;

    while (1) {
        display_clock();
        sleep(1);  // Update clock every second

        // Check for alarm
        time_t current_time = time(NULL);
        struct tm *time_info = localtime(&current_time);
        if (time_info->tm_hour == alarm_hour && time_info->tm_min == alarm_minute) {
            printf("\nAlarm! Wake up!\n");
            // Add code for alarm sound or visual notification
        }
    }

    return 0;
}
