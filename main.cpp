#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::cout << "Input timer (mm:ss): ";
    std::tm timer_input;
    std::cin >> std::get_time(&timer_input, "%M:%S");
    std::time_t current_time = time(nullptr);
    std::tm goal_time = *std::localtime(&current_time);
    goal_time.tm_min += timer_input.tm_min;
    goal_time.tm_sec += timer_input.tm_sec;
    double timer_counter = std::difftime(mktime(&goal_time), current_time);
    double last_time = 0;
    while (timer_counter > 0) {
        if (last_time != timer_counter) {
            std::time_t timer = (std::time_t) timer_counter;
            std::tm remaining_time = *std::localtime(&timer);
            std::cout << remaining_time.tm_min << ":" << remaining_time.tm_sec << std::endl;
            last_time = timer_counter;
        }
        current_time = time(nullptr);
        timer_counter = std::difftime(mktime(&goal_time), current_time);
    }
    std::cout << "DING! DING! DING!";
    return 0;
}
