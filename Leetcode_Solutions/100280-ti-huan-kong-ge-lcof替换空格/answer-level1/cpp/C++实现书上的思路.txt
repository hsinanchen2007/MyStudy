### 解题思路
和书上思路一样，但是字符串需要使用resize方法扩容

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        if(s.size() == 0) return s;
        int nMore = 0;
        for(int i = 0; i<s.size(); ++i)
        {
            if(s[i] == ' ')
                nMore+=2;
        }
        int oldlen = s.size();
        int newlen = oldlen+nMore;
        s.resize(newlen);
        while(oldlen != newlen)
        {
            if(s[--oldlen] == ' ')
            {
                s[--newlen] = '0';
                s[--newlen] = '2';
                s[--newlen] = '%';
            }
            else s[--newlen] = s[oldlen];
        }
        return s;
    }
};
```