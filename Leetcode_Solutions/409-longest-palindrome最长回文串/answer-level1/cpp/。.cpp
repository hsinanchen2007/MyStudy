### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int hashCount[52] = {0};
        for(string::size_type i = 0; i < s.size(); i++) {
            if('a' <= s[i] && s[i] <= 'z') {
                hashCount[s[i]-'a']++;
            } else {
                hashCount[s[i]-'A'+26]++;
            }
        }
        int sum = 0;
        for(int i = 0; i < 52; i++) {
            if((sum&1) && (hashCount[i]&1)) {
                sum += hashCount[i]-1;
            } else {
                sum += hashCount[i];
            }
        }
        return sum;
    }
};
```