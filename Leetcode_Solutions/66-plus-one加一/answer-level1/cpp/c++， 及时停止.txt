### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        int carry = 0;
        digits[digits.size() - 1] += 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int val = digits[i] + carry;
            if (val >= 10) {
                digits[i] = val % 10;
                carry = val / 10;
            } else {
                digits[i] = val;
                carry = 0;
                break;
            }
        }
       
        if (carry) {
            digits.push_back(0);
            for (int i = digits.size() - 1; i > 0; --i) {
                digits[i] = digits[i - 1];
            }
            digits[0] = carry;
        }
        return digits;
    }
};
```