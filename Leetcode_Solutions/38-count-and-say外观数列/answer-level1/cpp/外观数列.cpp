### 解题思路
此处撰写解题思路
本题需要采用递归的思想：第n项的外观序列要根据第n-1项的外观序列来计算。
计算第n项外观序列时，先获取第n-1项外观序列`str`，再根据规则生成第n项外观序列。
### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n<1 || n>30)
        {
            return "";
        }

        if(n == 1)
        {
            return "1";
        }

        string str = countAndSay(n-1);
        string sRet;
        int pre = str[0], cnt = 1;
        for(int i=1; i<str.length(); i++)
        {
            if(str[i] == pre)
            {
                cnt++;           //记录连续相同的字符个数
            }
            else
            {
                sRet += (cnt+'0');
                sRet += pre;         
                pre = str[i];
                cnt = 1;
            }
        }
        sRet += (cnt+'0');
        sRet += pre;
        return sRet;
    }
};
```