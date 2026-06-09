### 解题思路
map存储字符和次数。
遍历两次，第一次存次数。
第二次遍历时，第一个值为1的字符即为所求。

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty())
            return ' ';
        unordered_map<char,int> res;
        for(int i = 0;i<s.length();i++)
        {
            if(res.count(s[i]) == 0)
            {
                res.insert(make_pair(s[i],1));
            }
            else
            {
                res[s[i]]++;
            }
        }
        for(int i = 0;i<s.length();i++)
        {
            if(res[s[i]] == 1)
                return s[i];
        }   
        return ' ';
    }
};
```