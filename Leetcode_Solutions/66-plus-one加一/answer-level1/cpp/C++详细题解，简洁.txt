对于一般的数字，直接在末位加一即可，

本题特殊的两个点：

1. 若加一之后的值为10，需要进一位

2. 若数字为类似999 ，加一之后需要多一位数。使用`insert()`来实现，  insert函数  ： vec.insert(begin()+i ,a) 在第i个元素插入a
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits[size-1] != 9) //若末位不等于9，正常加一
        {
            ++digits[size-1];
        }
        else //若末位等于9，加一等于0
        {
            digits[size-1] = 0;
            for(int i = size - 1; i >0; --i) //若加完一后若等于0，下一位要进一 如869
            {
                if(digits[i] == 0)
                {
                    digits[i-1] = (digits[i-1] + 1) % 10;
                }
                else
                    break; //若某一位是数不需要进一，跳出循环
            }
            if(digits[0] == 0) //若到最后最高位也等于0，需要多一位数 如99 + 1  此时为答案为00，进行一下操作
            {
                digits.insert(digits.begin(),1); //在最高位插入1
            }
        }
        return digits;
    }
};
```