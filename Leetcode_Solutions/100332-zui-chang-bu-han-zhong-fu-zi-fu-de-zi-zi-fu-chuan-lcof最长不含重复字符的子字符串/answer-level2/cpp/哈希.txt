### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if( n == 0 || n == 1 ) return n;
        int res = 0;
        map<char,int> mp;
        for(int l = 0,r = 0;r < n;r++){
            if(mp.find(s[r]) != mp.end())
            l = max(mp[s[r]],l);
            mp[s[r]] = r + 1;
            res = max(res,r - l + 1);
        }
        return res;

    }
};
```