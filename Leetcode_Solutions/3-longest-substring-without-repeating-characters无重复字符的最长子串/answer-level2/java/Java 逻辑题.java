### 解题思路

![image.png](https://pic.leetcode-cn.com/1af9196238c1604740e38ceb55f86996185cd5ef1d334f4e6a3429f1169e069d-image.png)

记录出现过的字符下标，复杂度n

### 代码

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int[] cs = new int[256];
        for (int i = 0; i < 256; ++i) cs[i] = -1;
        int len = 1;
        int res = len;
        int start_index = 0;
        cs[s.charAt(0)] = 0;
        for (int i = 1; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (cs[c] >= 0) {
                if (cs[c] >= start_index) {
                    len = (len + 1) - (cs[c] - start_index + 1);
                    start_index = cs[c] + 1;
                } else {
                    len++;
                }
            } else {
                len++;
            }
            if (res < len) {
                res = len;
            }
            cs[c] = i;
        }
        return res;
    }
}
```