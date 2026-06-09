#### 栈：

我们可以使用栈来模拟整个代码片段的解析过程。当我们发现一个起始标签时，我们把标签入栈；当我们发现一个结束标签时，我们必须保证它和栈顶的起始标签的 `TAG_NAME` 相匹配。在代码解析完毕之后，我们必须保证栈为空。

我们从代码的起始位置遍历整个代码片段。当我们发现 `<` 时，如果我们目前不在 cdata 的范围内，那么我们必须解析这个 `<`，即接下来一定是一个标签（起始标签或结束标签）或者一段 cdata。如果 `<` 后面接着的是 `!`，那么后面一定是一段 cdata，接下来必须匹配到 `[CDATA[`。在这之后，我们就可以遍历代码片段直到遇到 `]]>`，表示 cdata 的结束，这中间的所有特殊符号我们都不需要解析。

如果 `<` 后面接着的不是 `!`，那么它一定是一个标签。如果是 `</` 那么它是结束标签，否则是开始标签。我们继续遍历代码片段，直到遇到 `>` 表示标签的结束为止。此时 `<` 或 `</` 与 `>` 之间的部分就是 `TAG_NAME`，我们需要检查 `TAG_NAME` 的合法性。如果它是一个起始标签，我们会把 `TAG_NAME` 入栈，如果它是一个结束标签，我们需要检查 `TAG_NAME` 和栈顶的元素是否相同。如果不相同或者栈为空，那么这就是一个不合法的结束标签。

在代码片段遍历结束后，我们还需要检查两点：第一是栈是否为空，如果不为空，说明还有未闭合的标签；第二是代码片段是否被合法的闭合标签包围，我们需要保证在第一个起始标签被闭合后，接下来不会有任何代码，并且每个 cdata 必须在栈不为空的时候才能出现。

<![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide14.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide15.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide16.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide17.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide18.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide19.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide20.PNG),![1000](https://pic.leetcode-cn.com/Figures/591/Tag_Validator_StackSlide21.PNG)>

```Java [sol1]
public class Solution {
    Stack < String > stack = new Stack < > ();
    boolean contains_tag = false;
    public boolean isValidTagName(String s, boolean ending) {
        if (s.length() < 1 || s.length() > 9)
            return false;
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isUpperCase(s.charAt(i)))
                return false;
        }
        if (ending) {
            if (!stack.isEmpty() && stack.peek().equals(s))
                stack.pop();
            else
                return false;
        } else {
            contains_tag = true;
            stack.push(s);
        }
        return true;
    }
    public boolean isValidCdata(String s) {
        return s.indexOf("[CDATA[") == 0;
    }
    public boolean isValid(String code) {
        if (code.charAt(0) != '<' || code.charAt(code.length() - 1) != '>')
            return false;
        for (int i = 0; i < code.length(); i++) {
            boolean ending = false;
            int closeindex;
            if(stack.isEmpty() && contains_tag)
                return false;
            if (code.charAt(i) == '<') {
                if (!stack.isEmpty() && code.charAt(i + 1) == '!') {
                    closeindex = code.indexOf("]]>", i + 1);
                    if (closeindex < 0 || !isValidCdata(code.substring(i + 2, closeindex)))
                        return false;
                } else {
                    if (code.charAt(i + 1) == '/') {
                        i++;
                        ending = true;
                    }
                    closeindex = code.indexOf('>', i + 1);
                    if (closeindex < 0 || !isValidTagName(code.substring(i + 1, closeindex), ending))
                        return false;
                }
                i = closeindex;
            }
        }
        return stack.isEmpty() && contains_tag;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是代码片段的长度。

* 空间复杂度：$O(N)$。