#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define PORT_NAME "/dev/ttyXR6"
#define BAUD_RATE 1000000

int main() {
    FILE *serial_port = fopen(PORT_NAME, "w+");
    
    if (serial_port == NULL) {
        perror("Error opening serial port");
        return 1;
    }

    char command = 0x0F;
    char received_data[40];

    while (1) {
        struct timeval start_time, end_time;

        // Get start time
        gettimeofday(&start_time, NULL);

        fwrite(&command, sizeof(char), 1, serial_port);
        fflush(serial_port);

        fread(received_data, sizeof(char), 40, serial_port);

        // Get end time
        gettimeofday(&end_time, NULL);

        // Calculate elapsed time in milliseconds
        double elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
                                 (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        printf("Received: ");
        for (int i = 0; i < 40; i++) {
            printf("%02x ", received_data[i]);
        }
        printf("\nElapsed Time: %.2f ms\n", elapsed_time_ms);

        // Use usleep for microsecond-level precision (adjust as needed)
        usleep(1000000);  // Sleep for 1 second
        usleep(1000);  // Sleep for 1 milli second
        // usleep(1);  // Sleep for 1 micro second
    }

    fclose(serial_port);

    return 0;
}
