### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++; //所有字母遍历一遍
        }
        for(int j=0;j<s.size();j++)
        {
            if(hash[s[j]-'a']==1)
            {
                return j;
            }
        }
        return -1;
    }
};
```