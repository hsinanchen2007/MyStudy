### 解题思路
用状态机的思路来做，唯一的问题就是case太多太杂了，注意边界条件和各种情况。

### 代码

```cpp
class Solution {
public:
enum status {
    begin = 0,
    symbol = 1,
    number = 2,
    closed = 3,
};
    int myAtoi(string str) {
        status state = status::begin;
        bool positive = true;
        vector<int> code_table(64, 0);
        code_table[48] = 0;
        code_table[49] = 1;
        code_table[50] = 2;
        code_table[51] = 3;
        code_table[52] = 4;
        code_table[53] = 5;
        code_table[54] = 6;
        code_table[55] = 7;
        code_table[56] = 8;
        code_table[57] = 9;
        stack<char> nums;
        for (auto& c : str) {
            if (state == status::begin || state == status::symbol) {
                if (c == '+' || c == '-') {
                    if (state == status::symbol)
                        break;
                    state = status::symbol;
                    if (c == '-') {
                        positive = false;
                    }
                    continue;
                }
                else if ((c < 48 || c > 57) && c != ' ') {
                    state = status::closed;
                }
                else if (c >= 48 && c <= 57){
                    state = status::number;
                }
            }
            if (state == status::symbol) {
                if (c < 48 || c > 57) {
                    state = status::closed;
                    break;
                }
            }
            if (state == status::number) {
                if (c >= 48 && c <= 57)
                    nums.push(c);
                else {
                    state = status::closed;
                }
            }
        }

        long long position = 1;
        int result = 0;
        while (!nums.empty()) {
            char c = nums.top();
            nums.pop();
            int n = code_table[c];
            long long indeed = result + position * n;
            if (indeed > INT_MAX) {
                if (positive == false) {
                    result = INT_MIN;
                    return result;
                }
                result = INT_MAX;
                break;
            }
            else {
                result += position * n;
            }
            if (position < 10000000000) {
                position = position * 10;
            }
        }
        if (positive == false) {
        result = -result;
        }
        return result;     
    }
};
```