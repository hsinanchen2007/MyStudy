### 解题思路
利用c++的string类replace函数替换空格。

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                s.replace(i,1,"%20");
                i+=2;
            }
        }
        return s;
    }
};
```