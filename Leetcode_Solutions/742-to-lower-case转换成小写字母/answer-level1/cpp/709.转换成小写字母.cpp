### 解题思路
解题思路
按照ASCII值，遍历字符串

### 代码

```cpp
class Solution {
public:
    string toLowerCase(string str) 
    {
        int l=str.size();
        for(int i=0;i<l;i++)
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