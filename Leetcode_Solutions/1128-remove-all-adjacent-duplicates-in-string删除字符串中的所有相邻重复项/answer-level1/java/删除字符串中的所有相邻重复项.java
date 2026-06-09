>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 栈的应用

时间复杂度和空间复杂度均是O(n)，其中n为字符串S的长度。

执行用时：66ms，击败42.05%。消耗内存：42.4MB，击败5.62%。

```java
public class Solution {
    public String removeDuplicates(String S) {
        int n;
        if (null == S || (n = S.length()) == 0) {
            return S;
        }
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            char c = S.charAt(i);
            if (!stack.isEmpty() && stack.peek() == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.insert(0, stack.pop());
        }
        return result.toString();
    }
}
```