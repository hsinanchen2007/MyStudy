class Solution {
public:
    char tolower(char ch) {
        if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
            return ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;
        } else {
            return 0;
        }
    }
    bool isPalindrome(string s) {
        const int size = s.size();
        if (size <= 1) {
            return true;
        }
        int left = 0, right = s.size() - 1;
        char l, r;
        while (left < right) {
            while (true) {
                l = tolower(s[left]);
                if (left >= right || l != 0) {
                    break;
                }
                left++;
            }
            while (true) {
                r = tolower(s[right]);
                if (left >= right || r != 0) {
                    break;
                }
                right--;
            }
            if (l != r) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};