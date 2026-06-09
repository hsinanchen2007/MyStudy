### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {                         //直接遍历，时间o(n), 空间o(n)
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ') ans += "%20";
            else ans += s[i];
        }

        return ans;
    }
};
```