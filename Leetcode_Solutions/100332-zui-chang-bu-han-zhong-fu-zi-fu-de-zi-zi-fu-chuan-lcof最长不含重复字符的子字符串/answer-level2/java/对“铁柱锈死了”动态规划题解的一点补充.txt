### 解题思路
参考“铁柱锈死了”的动态规划题解，用f[i]表示以第i个字符结尾的无重复字符的子串的最大长度，用s[i]表示第i个字符，用indexes[s[i]]表示第i个字符上一次出现的位置。
已知f[i-1]时，f[i]的取值如下：
1. 当s[i]在之前从未出现过，即indexes[s[i]] < 0，此时f[i] = f[i-1] + 1
2. 当s[i]在f[i-1]对应的子串中未出现过，即i - indexes[s[i]] > f[i-1]，此时f[i] = f[i-1] + 1
3. 当s[i]在f[i-1]对应的子串中出现过，即i - indexes[s[i]] <= f[i-1], 此时f[i] = f[i-1]，并且**包括s[i]的子串长度为i - indexes[s[i]](要把上次出现的字符排除掉)**

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() <= 0) {
            return 0;
        }
        int[] indexes = new int[128];
        for (int i = 0; i < indexes.length; i++) {
            indexes[i] = -1;
        }
        int maxLength = 0;
        int currentLength = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int index = indexes[c];//该字符上一次出现的位置
            if (index < 0 || i - index > currentLength) {
                currentLength++;
            } else {
                currentLength = i - index;
            }
            if (maxLength < currentLength) {
                maxLength = currentLength;
            }
            indexes[c] = i;
        }
        return maxLength;
    }
}
```

###执行结果
![image.png](https://pic.leetcode-cn.com/43ac95ef8b9f401afbd8b30052c529dd59475f2ceb66bfe7e6995158b4260979-image.png)
