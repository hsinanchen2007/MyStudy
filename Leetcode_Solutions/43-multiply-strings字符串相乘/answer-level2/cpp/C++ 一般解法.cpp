### 解题思路
![image.png](https://pic.leetcode-cn.com/1a34707bb4b86e30a7227e2b0731f8b124842df99417dece7b7babed9c1551f5-image.png)
计算每一位，当前位置 i 的值 str[i] 等于 num1[j] * num2[i-j],j 从 0 到 len1 的遍历之和，再加上进位carry。

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0") return "0";
        int carry = 0,len1 = num1.size(),len2 = num2.size(),tmp = 0;
        string str;
        for(int i = len1+len2-2; i >= 0; i--)
        {
            tmp = 0;
            for(int j = len1 - 1; j >= 0; j--)
            {
                if(i - j >= len2 || i - j < 0) continue;
                tmp += (num1[j] - '0') * (num2[i - j] - '0');
            }
            tmp += carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            str.push_back(tmp + '0');
        }
        if(0 != carry) str.push_back(carry + '0');
        reverse(str.begin(),str.end() );
        return str;
    }
};
```