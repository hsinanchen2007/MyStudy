### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--){
            ++digits[i];
            digits[i] = digits[i] % 10;
            if(digits[i] != 0)
                return digits;
        }
        if (digits[0] == 0){    //进位
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
```