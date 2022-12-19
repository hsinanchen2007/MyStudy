>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 每考虑一位数都对5取余一次，防止越界

时间复杂度是O(n)，其中n是数组A的长度。空间复杂度是O(1)。

执行用时：4ms，击败94.78%。消耗内存：42.2MB，击败5.43%。

```java
public class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> result = new ArrayList<>();
        int num = 0;
        for (int a : A) {
            num = ((num << 1) + a) % 5;
            if (num == 0) {
                result.add(true);
            } else {
                result.add(false);
            }
        }
        return result;
    }
}
```