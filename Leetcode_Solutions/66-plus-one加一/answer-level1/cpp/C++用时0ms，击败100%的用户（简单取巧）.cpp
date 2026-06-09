### 解题思路
当加上1等于10时，当前下标处赋值为0，向r-1下标加1；
直到r==0时，向开头插入1；

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = digits.size() - 1;
        while(r >= 0){
            digits[r] = digits[r] + 1;
            if(digits[r] == 10){
                digits[r] = 0;
                r--;
            }else{
                break;
            }
        }
        if(r < 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
```