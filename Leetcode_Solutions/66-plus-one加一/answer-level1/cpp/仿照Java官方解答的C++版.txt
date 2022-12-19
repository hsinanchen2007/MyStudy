### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i > -1; i--){
            digits[i] += 1;
            digits[i] = digits[i] % 10;
            if(digits[i] != 0) return digits;
        }
        
        digits = vector<int> (digits.size() + 1);
        digits[0] = 1;
        return digits;
    }
};
```