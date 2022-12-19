### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) {
            return num2;
        }
        if (num2.empty()) {
            return num1;
        }
        int first = num1.size() - 1, second = num2.size() - 1;
        string temp;
        int carry = 0;
        while (first >= 0 && second >= 0) {
            int val = num1[first] - '0' + (num2[second] - '0') + carry;
            temp.push_back(val % 10 + '0');
            carry = val / 10;
            first -= 1, second -= 1;
        }
        while (first >= 0) {
            int val = num1[first] - '0' + carry;
            temp.push_back(val % 10 + '0');
            carry = val / 10;
            first -= 1;
        }
        while (second >= 0) {
            int val = num2[second--] - '0' + carry;
            temp.push_back(val % 10 + '0');
            carry = val / 10;
        }
        if (carry) {
            temp.push_back(carry + '0');
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
```