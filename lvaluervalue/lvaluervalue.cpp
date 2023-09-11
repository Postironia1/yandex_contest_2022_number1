#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>


int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < N; i++) {
        std::string input;
        std::getline(std::cin, input);

        // Parse the CSV input
        std::string fio, day, month, year;
        size_t pos = 0;
        for (int j = 0; j < 6; j++) {
            size_t comma_pos = input.find(',', pos);
            std::string field = input.substr(pos, comma_pos - pos);
            pos = comma_pos + 1;

            switch (j) {
            case 0:
                fio += field;
                break;
            case 1:
                fio += field;
                break;
            case 2:
                fio += field;
                break;
            case 3:
                day = field;
                break;
            case 4:
                month = field;
                break;
            case 5:
                year = field;
                break;
            }
        }

        // 1. Calculate the number of unique characters in FIO
        int unique_chars = 0;
        std::map<char, int> unique_char_count;
        for (char c : fio) {
            unique_char_count[c]++;
        }
        for (const auto& el : unique_char_count) {
            unique_chars++;
        }
        unique_char_count.clear();

        // 2. Calculate the sum of day and month, multiplied by 64
        int month_numbers_summ = 0;
        int day_number_summ = 0;
        int temp = std::stoi(month);
        while (temp != 0)
        {
            month_numbers_summ += temp % 10;
            temp /= 10;
        }
        temp = std::stoi(day);
        while (temp != 0)
        {
            day_number_summ += temp % 10;
            temp /= 10;
        }

        int birth_code = (month_numbers_summ + day_number_summ) * 64;
        int x = std::stoi(day);

        int family_code = (static_cast<int>(fio[0]) - 64) * 256;

        // 3. Calculate the code
        int code = unique_chars + birth_code + family_code;

        // Convert the code to base 16 (hex) and keep the last 3 digits
        std::string hex_code = "";
        while (code > 0) {
            int remainder = code % 16;
            hex_code = "0123456789ABCDEF"[remainder] + hex_code;
            code /= 16;
        }

        while (hex_code.length() > 3) {
            hex_code.erase(0, 1); // Удаляем первый символ
        }

        while (hex_code.length() < 3) {
            hex_code = "0" + hex_code;
        }

        std::cout << hex_code << " ";
    }

    std::cout << "\n";

    return 0;
}
