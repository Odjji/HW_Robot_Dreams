#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double altitude_m;
    double target_x;
    double target_y;
    
    std::cout << "Введіть висоту зависання: ";
    std::cin >> altitude_m;
    
    std::cout << "Введіть зсув праворуч: ";
    std::cin >> target_x;
    
    std::cout << "Введіть взсув вперед: ";
    std::cin >> target_y;
    
    double dist_to_target;
    double rate_to_target;
    double time_fall;
    double speed_metteng;
    bool status_drone;
    
    dist_to_target = sqrt(pow(target_x, 2) + pow(target_y, 2));
    
    double kut_radians = std::atan2(target_x, target_y);
    rate_to_target = kut_radians * (180.0 / M_PI);
    
    time_fall = sqrt(2 * altitude_m / 9.81);
    speed_metteng = time_fall * 9.81;
    
    if (dist_to_target >= 2) {
        status_drone = false;
    } else {
        status_drone = true;
    }
    
    std::cout << "Дистанція до точки скиду: " << std::fixed << std::setprecision(2) << dist_to_target << " м\n";
    std::cout << "Курс на ціль: "             << rate_to_target << " град\n";
    std::cout << "Час падіння: "              << time_fall << " с\n";
    std::cout << "Швидкість зустрічі: "       << speed_metteng << " м/с\n";
    std::cout << "Статус (1 = ATTACK, 0 = MOVE): " << status_drone << "\n";

    return 0;
}