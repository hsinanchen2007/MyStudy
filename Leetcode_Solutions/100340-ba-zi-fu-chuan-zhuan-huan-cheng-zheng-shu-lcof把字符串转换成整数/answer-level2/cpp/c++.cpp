```c++
class Solution {
public:
    inline bool IsDigit(char c) const { return c >= '0' && c <= '9'; }
    inline int ToDigit(char c) const { return c - '0'; }
    inline bool IsOverflow(int x, int y) { return x > INT_MAX / 10 || x == INT_MAX / 10 && y > INT_MAX % 10; }
    
    int strToInt(string str) {
        int positive = -1, ans = 0;
        for (auto c : str) {
            if (positive == -1) {
                if (c == '-') {
                    positive = 2;
                }
                else if (c == '+' || IsDigit(c)) {
                    positive = 1;
                    if (IsDigit(c)) {
                        ans = ToDigit(c);
                    }
                }
                else if (c != ' ') {
                    return 0;
                }
            }
            else if (IsDigit(c)) {
                int cd = ToDigit(c);
                if (positive == 1 && IsOverflow(ans, cd)) {
                    return INT_MAX;
                }
                if (positive == 2 && IsOverflow(ans, cd)) {
                    return INT_MIN;
                }
                ans = 10 * ans + cd;
            }
            else {
                break;
            }
        }
        return positive == 1 ? ans : -ans;
    }
};
```