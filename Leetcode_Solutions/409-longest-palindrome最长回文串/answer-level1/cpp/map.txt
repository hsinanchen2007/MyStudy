### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int res = 0;
        int odd_num = 0;
        for(unordered_map<char,int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
            if(iter->second % 2 == 0) {
                res += iter->second;
            } else {
                res += (iter->second - 1);
                odd_num++;
            }
        }
        if (odd_num >= 1) {
            res += 1;
        }
        return res;

    }
};
```