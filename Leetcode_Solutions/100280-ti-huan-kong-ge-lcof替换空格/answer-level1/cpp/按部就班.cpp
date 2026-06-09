### 解题思路
按部就班，遍历原字符串，如果s[i]==' '，则res+="%20"，否则res+=s[i]

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res,temp="%20";
        for(int i=0;i<s.size();i++)
            if(s[i]==' ')
                res+=temp;
            else
                res+=s[i];
        return res;
    }
};
```