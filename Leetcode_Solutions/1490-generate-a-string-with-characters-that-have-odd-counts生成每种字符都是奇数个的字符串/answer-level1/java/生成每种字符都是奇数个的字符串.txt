>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 暴力破解法

时间复杂度是O(n)。空间复杂度是O(1)。

执行用时：1ms，击败100.00%。消耗内存：36.9MB，击败100.00%。

```java
public class Solution {
    public String generateTheString(int n) {
        StringBuilder sb = new StringBuilder();
        if (n == 0) {
            return "";
        }
        if ((n & 1) == 1) {
            while (sb.length() < n) {
                sb.append('a');
            }
            return sb.toString();
        }
        return "b" + generateTheString(n - 1);
    }
}
```