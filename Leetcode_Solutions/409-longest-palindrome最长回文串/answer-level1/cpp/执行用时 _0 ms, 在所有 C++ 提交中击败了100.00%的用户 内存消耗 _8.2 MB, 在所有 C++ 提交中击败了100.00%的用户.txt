### 解题思路


### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int a[52] = {0};
        int count = 0;
        int more = 0;
        for (int i = 0; i < s.size(); i++) {
            if((s[i]-'A')<=25)
                a[s[i] - 'A']++;
            if ((s[i] - 'A') >= 32)
                a[s[i] - 'a' + 26]++;
        }
        for (int i = 0; i < 52; i++) {
            if (a[i] % 2 == 0) {
                count += a[i];
            }
            else {
                count += a[i] - 1;
                more = 1;
            }
        }
        count += more;
        return count;
    }
};
```