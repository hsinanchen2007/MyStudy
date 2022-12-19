### 解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> count;
        int ans=0;
        for(char c : s)
            ++count[c];
        for(auto t : count) {
            int inc=t.second;
            ans+=inc/2*2;
            if(inc%2==1 && ans%2==0)
                ans++;
        }
        return ans;
    }
};
```