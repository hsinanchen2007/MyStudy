### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                res+="%20";
            else
             res+=s[i];
        }
        return res;
        
    }
};
```