#include <iostream>
#include <string>
#include <vector>

// Function to compute the longest common substring
std::string longest_common_substring(const std::string &s1, const std::string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    std::vector<std::vector<int>> lookup(len1 + 1, std::vector<int>(len2 + 1, 0));

    int longest_length = 0;
    int longest_end = 0;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
                if (lookup[i][j] > longest_length) {
                    longest_length = lookup[i][j];
                    longest_end = i - 1;
                }
            }
        }
    }

    return s1.substr(longest_end - longest_length + 1, longest_length);
}

int main() {
    std::string s1, s2;
    std::cout << "Enter the first string: ";
    std::cin >> s1;
    std::cout << "Enter the second string: ";
    std::cin >> s2;

    std::string result = longest_common_substring(s1, s2);
    std::cout << "The longest common substring is: " << result << std::endl;

    return 0;
}
