### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string space="%20";
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
                str.append(space);
            else str.append(s,i,1);
        }
        return str;
    }
};
```