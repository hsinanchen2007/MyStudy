### 解题思路

先对数组进行排序，首先让饼干和孩子胃口对应的满足，之后满足饼干大于孩子的，奇数即可。

### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
                if (g.length == 0) return 0;

        Arrays.sort(g);
        Arrays.sort(s);

        int count = 0;

        for (int i = g.length - 1, j = s.length - 1; j >= 0 && i >= 0; ) {
            if (g[i] == s[j] || g[i] < s[j]) {
                i--;
                j--;
                count++;
            } else if (g[i] > s[j]) {
                i--;
            }
        }

        return count;
    }
}
```