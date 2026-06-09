### 解题思路
打卡打卡

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for(char c : s) count[c]++;
        int ans = 0;
        for(int v : count){
            ans += v / 2 * 2;
            if(v % 2 == 1 && ans % 2 == 0) ans++;
        }
        return ans;
    }
};
```