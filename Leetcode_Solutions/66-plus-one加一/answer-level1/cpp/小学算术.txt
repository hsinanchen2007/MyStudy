### 解题思路
模拟进位即可。重要的是方法，印象中有几道模拟竖式计算的题思想和这个比较相近。这道题的corner situation不多，也算是帮忙了orz

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int ptr = digits.size()-1;
        while (carry) {
            if (ptr == -1) {
                digits.insert(digits.begin(), 1);
                break;
            }
            if (digits[ptr] != 9) {
                digits[ptr] += 1;
                carry = false;
            }
            else {
                digits[ptr] = 0;
                ptr--;
            }
        }
        return digits;
    }
};
```