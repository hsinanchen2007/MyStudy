### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        int longest = 0, odd = 0;
        bool flag = false;
        map<char, int> mp;
        for(auto item : s) mp[item] += 1;
        for(auto it : mp){
            if((it.second) % 2){
                longest += it.second-1;
                flag = true;
            }
            else{
                longest += it.second;
            }
        }
        return flag ? longest + 1 : longest;
    }
};
```