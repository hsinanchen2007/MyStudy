### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i =digits.size()-1;i>=0;i--)
        {
            digits[i]++;   //先加一个,也可以做进位
            digits[i]=digits[i]%10;
            if (digits[i]!=0)  //若取余为0 说明有进位
            {
                return digits;
            }
        }
        digits.insert(digits.begin(),1); //最高位补1
        return digits;
    }
};
```