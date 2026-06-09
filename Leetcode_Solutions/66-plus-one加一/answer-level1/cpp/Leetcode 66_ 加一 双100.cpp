### 解题思路
从Vector的末位处 + 1
依次计算本位与进位
对于999 这样的需要在vector的首位添加进位 
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int j = 0;
        int k = 0;
        for(int i = length-1; i >= 0; i--)
        {
            if(i == length-1)
            {
                j = (digits[i] + 1 + k) % 10;
                k = (digits[i] + 1 + k) / 10;
                digits[i] = j;
            }
            else
            {
                j = (digits[i] + k) % 10;
                k = (digits[i] + k) / 10;
                digits[i] = j;
            }
            
        }
        if(k != 0)
        //vector 头部插入元素
            digits.insert(digits.begin(), k);    
        return digits;
    }
};
```