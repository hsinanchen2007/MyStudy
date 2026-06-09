### 解题思路
此处撰写解题思路
需要考虑两种情况：
1、不需要进位：直接加以返回；
2、需要进位：
（1）注意最高位需要进位的情况；
（2）注意仅为一个数字9时；

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int digitsSize = digits.size();
        int dp = digitsSize - 1; //dp为数组的下标
        digits[dp] += 1;
        if(digits[dp] < 10) //最后一个数加1不等于10，不用进位，直接返回即可
            return digits;
        else if(digits[dp] == 10) //考虑进位
        {
            digits[dp] = 0;
            if(dp == 0) 
            {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            dp--;
            digits[dp] += 1;
            while(digits[dp] == 10 && dp > 0)
            {
                digits[dp] = 0;
                dp--;
                digits[dp] += 1;
            }
            if(dp == 0 && digits[dp] == 10) //最高位也需要进位（例如：999999）
            {
                digits[dp] = 0;
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }
        return {};         
    }
};
```