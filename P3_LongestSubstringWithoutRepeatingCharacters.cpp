#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int left = 0;
        int charIndex[128] = {0}; 

        for (int right = 0; right < n; right++) {
            char currentChar = s[right];
            if (charIndex[currentChar] > left) {
                left = charIndex[currentChar]; 
            }
            charIndex[currentChar] = right + 1;
            maxLength = max(maxLength, right - left + 1); 
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}