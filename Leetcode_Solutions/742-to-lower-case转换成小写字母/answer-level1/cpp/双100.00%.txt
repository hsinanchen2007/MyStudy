### 解题思路
遍历str，遇到大写字母就改成小写字母

### 代码

```cpp
class Solution {
public:
    string toLowerCase(string str) {
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                str[i]+=32;
            }
        }
        
        return str;

    }
};
```