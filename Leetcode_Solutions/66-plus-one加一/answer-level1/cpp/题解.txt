### 解题思路
既然是数位小的增加，则思考从后面的循环解决问题。 
从小到大给每位直接+1.若出现10，则进位，进入下一位数的循环，不是10，则可直接返回。
当每一位都+1时，需要在首位+1.

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        
        for(int i = len-1 ; i >= 0 ; i--){
            digits[i]++;

            if(digits[i] != 10)
                return digits;
            else
                digits[i] = 0;
        }

        digits.insert(digits.begin(),1);
        return digits;
    }
};
```