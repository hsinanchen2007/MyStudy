阅读理解题。做题五分钟，读题两小时。
看大佬题解一句话概括题意：给你一个合法的括号序列，你需要将其拆分成**两个**合法的子序列（不连续），使得两个子序列的括号嵌套深度较大者尽量的小。 

**思路：栈** 创建一个栈，遍历seq，遇到'('入栈，遇到')'弹出。在这样的规则下，'('入栈时栈的深度就对应着当前括号对的嵌套深度深度。将奇数深度的括号分成一组，将偶数深度的括号分成一组，分别用0和1标记即可。

例如：

```
括号序列   ( ( ) ( ( ) ) ( ) )
下标编号   0 1 2 3 4 5 6 7 8 9
嵌套深度   1 2 2 2 3 3 2 2 2 1
将奇数深度的分一组用0标记，将偶数深度的括号分一组用1标记。
标记结果   0 1 1 1 0 0 1 1 1 0

```

按照上述思路进行实现：

```java
public int[] maxDepthAfterSplit(String seq) {
    if (seq == null || seq.equals("")) return new int[0];
    Stack<Character> stack = new Stack<>();
    int[] res = new int[seq.length()];
    //遍历
    for (int i = 0; i < seq.length(); i++) {
        char c = seq.charAt(i);
        if (c == '(') {//入栈,记录括号对所在深度,奇数用0标记，偶数用1标记。
            res[i] = stack.size() % 2;
            stack.push(c);
        } else {//出栈,记录括号对所在深度,奇数用0标记，偶数用1标记。
            stack.pop();
            res[i] = stack.size() % 2;
        }
    }
    return res;
}
```

其实我们并不需要真的使用一个栈，因为我们需要的仅仅是记录当前栈的深度depth：

```java
public int[] maxDepthAfterSplit(String seq) {
    if (seq == null || seq.equals("")) return new int[0];
    int depth=0;
    int[] res = new int[seq.length()];
    //遍历
    for (int i = 0; i < seq.length(); i++) {
        char c = seq.charAt(i);
        if (c == '(') {//入栈,栈内深度增加
            res[i] = ++depth % 2;
        } else {//出栈，栈内深度减少
            res[i] = depth-- % 2;
        }
    }
    return res;
}
```

时间复杂度：O(n)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和源码:[github](https://github.com/Jerrymouse1998/learning-record-of-leetcode) 