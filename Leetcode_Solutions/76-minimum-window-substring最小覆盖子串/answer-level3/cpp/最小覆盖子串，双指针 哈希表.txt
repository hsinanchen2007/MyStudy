### 解题思路
j在前， i在后
统计T里面字母出现的次数，
每次出现的字母次数都要-1
如果t中的字母次数小于0
说明出现了两次，那么j就要向前移动


### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>hash;
        for(auto c : t) hash[c]++;
        int cnt = hash.size();
        string res;
        for(int i = 0 , j = 0, c = 0; i < s.size();i++)
        {
            if(hash[s[i]] == 1) c++;
            hash[s[i]]--;
            while(hash[s[j]] < 0)hash[s[j++]]++;
            if(c == cnt)
            {
                if(res.empty() || res.size() > i - j + 1) res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};
```