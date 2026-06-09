### 解题思路
这类预留一个0,注意进位问题即可

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int flag = 1;
        for (int i = digits.size() - 1; i > -2; i--)
        {
            int digit;
            if (i > -1)
                digit = digits[i];
            else if (i == -1)
                digit = 0;
            
            digit += flag;
            if (digit >= 10)
                flag = 1;
            else
                flag = 0;
            result.push_back(digit % 10);
        }
        reverse(result.begin(), result.end());
        if(result[0] == 0)
            result.erase(result.begin());
        return result;
    }
};
```