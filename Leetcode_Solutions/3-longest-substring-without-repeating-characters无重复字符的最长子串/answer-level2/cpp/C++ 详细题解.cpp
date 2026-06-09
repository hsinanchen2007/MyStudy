思路很简单很暴力，记录每次遇到重复之前最长的子串len，并与答案候选ans对比，若大于ans就赋值给ans
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0; s[i] != '\0'; ++ i){
            unordered_set<char> str;
            int len = 0;
            for(int j = i; s[j] != '\0'; ++ j){
                if(str.count(s[j])) break;
                str.insert(s[j]);
                ++ len;
            }
            len > ans? ans = len : ans = ans;
        }
        return ans;
    }
};
```
