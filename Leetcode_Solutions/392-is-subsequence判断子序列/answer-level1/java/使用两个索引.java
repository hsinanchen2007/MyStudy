本题解空间复杂度：O(1)，使用两个变量存储索引
时间复杂度（线性）：O(N)，N为t的长度，最优情况下N为s的长度

```
class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j))
                i++;
            j++;
        }
        return i == s.length();
    }
}
```
