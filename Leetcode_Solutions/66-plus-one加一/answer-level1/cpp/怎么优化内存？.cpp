### 解题思路
考虑了特殊情况，但是执行效果并不好，最后选择这种比较简洁的代码吧。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+1<=9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        if(digits[0]==0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```