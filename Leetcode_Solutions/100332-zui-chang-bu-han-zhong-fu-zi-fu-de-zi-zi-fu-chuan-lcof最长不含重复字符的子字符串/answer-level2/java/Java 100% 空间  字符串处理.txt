### 解题思路
二维数组标示每一个字符在当前有效字符串中出现的位置，当重复的时候，从它后面继续寻找不重复的连续字符串。
之所以是二维，因为一个标示存在性，一个标示index位置。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int[][] result = new int[256][2];
        int cur = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (result[c][0] == 1) {
                i = result[c][1];

                result = new int[256][2];
                cur = 0;
            } else {
                cur++;
                result[c][0] = 1;
                result[c][1] = i;
            }

            if (cur > max) {
                max = cur;
            }
        }

        return max;
    }
}
```