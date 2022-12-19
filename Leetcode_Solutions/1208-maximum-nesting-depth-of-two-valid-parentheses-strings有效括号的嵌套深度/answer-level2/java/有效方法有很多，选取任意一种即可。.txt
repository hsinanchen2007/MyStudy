- 有很多种策略可以使嵌套深度最小，比如以下两种：
  - 每次把连续嵌套括号的前一半分给 A，后一半分给 B。
  - 把连续嵌套括号交替分给 A 和 B。
- 下面是把连续嵌套括号交替分给 A 和 B 的代码。

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        for (int i = 0, cnt = 0; i < res.length; ++i) {
            if (seq.charAt(i) == '(') {
                res[i] = cnt++ & 1;
            } else {
                res[i] = --cnt & 1;
            }
        }
        return res;
    }
}
```

更多题解欢迎关注 [https://github.com/Jerring/LeetCode](https://github.com/Jerring/LeetCode) ^_^

