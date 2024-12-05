#include <stdio.h>
#include <stdbool.h>

#define OBSTACLE_X_MIN 0.25
#define OBSTACLE_X_MAX 0.75
#define OBSTACLE_Y_MIN 0.85
#define OBSTACLE_Y_MAX 1.15

bool is_static_obstacle(double x, double y) {
    return (x >= OBSTACLE_X_MIN && x <= OBSTACLE_X_MAX) && (y >= OBSTACLE_Y_MIN && y <= OBSTACLE_Y_MAX);
}

int main() {
    double obstacle_x = 0.5; // Center of the obstacle in x direction
    double obstacle_y = 1.0; // Center of the obstacle in y direction
    int motor_speed = 100; // Initial motor speed
    int steer = 0; // Initial steer angle

    if (is_static_obstacle(obstacle_x, obstacle_y)) {
        printf("Static obstacle detected at (%.2f, %.2f)\n", obstacle_x, obstacle_y);
        motor_speed = 0; // Set motor speed to 0 to stop the vehicle
        steer = 15; // Set steer angle to 15 degrees to move to the right lane
    } else {
        printf("No static obstacle detected at (%.2f, %.2f)\n", obstacle_x, obstacle_y);
        steer = -15; // Set steer angle to -15 degrees to move back to the original lane
    }
    
    if (motor_speed == 0) {
        printf("Vehicle stopped\n");
    } else {
        printf("Vehicle moving\n");
    }
    

    printf("Motor speed: %d\n", motor_speed);
    printf("Steer angle: %d\n", steer);

    return 0;
}