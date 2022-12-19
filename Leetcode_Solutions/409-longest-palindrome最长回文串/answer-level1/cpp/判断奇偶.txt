### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(256, 0);
        int len = 0;
        for(auto ss: s){
            cnt[int(ss)]++;
            if(cnt[int(ss)] == 2 ){
                len += 2;
                cnt[int(ss)] = 0;
            }
        }
        if(len < s.size()) len++;
        return len;
    }
};
```