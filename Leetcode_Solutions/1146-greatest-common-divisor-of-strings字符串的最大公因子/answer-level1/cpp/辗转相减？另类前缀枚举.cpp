### 解题思路
比较两个字符串，若有对应位置不等则一定不存在gcd串，若两个字符串前缀相等但长度不同，则gcd字符串一定为较长字符串的后缀与前缀的gcd字符串。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while(str1!=str2)
        {
            int n = min(str1.size(), str2.size());
            for(int i=0;i<n;++i)
            {
                if(str1[i]!=str2[i])
                    return string("");
            }
            if(n < str1.size())
                str1 = str1.substr(n, str1.size()-n);
            else
                str2 = str2.substr(n, str2.size()-n);
        }
        return str1;
    }
};
```