### 解题思路

KMP 算法

### 代码

```java
class Solution {
    public String longestPrefix(String s) {
        int n = s.length();
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 1, j = -1; i < n; i ++) {
            while (j > - 1 && s.charAt(j + 1) != s.charAt(i)) j = next[j];
            if (s.charAt(i) == s.charAt(j + 1)) j ++;
            next[i] = j;
        }
        int max = next[n - 1];
        return s.substring(0, max + 1);
    }
}
```