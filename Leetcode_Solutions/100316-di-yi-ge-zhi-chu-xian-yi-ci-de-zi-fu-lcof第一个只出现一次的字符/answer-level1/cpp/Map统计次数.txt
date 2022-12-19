题目**没有说明**包含什么类型字符，完全记录ASCII可能也不够，所以使用map

遍历两次
时间复杂度O(n)
空间复杂度O(n)

```
    char firstUniqChar(string s) {
        map<char, int>mp;
        for(int i = 0; i<s.length(); i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = 1;
            }
            else mp[s[i]]++;
        }
        for(int i = 0; i<s.length(); i++)
        {
            if(mp[s[i]] == 1)
            {
                return s[i];
            }
        }
        return ' ';
    }
```

