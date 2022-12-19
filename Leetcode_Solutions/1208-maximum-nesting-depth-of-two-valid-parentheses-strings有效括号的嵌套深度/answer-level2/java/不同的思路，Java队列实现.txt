看到高赞题解都是用栈去实现，想说说自己的思路。时间复杂度O(n)，空间复杂度O(n)，并不是最优，仅供大家参考。

括号匹配问题，第一反应都是用栈去解决。
但此题的另一个要求是嵌套深度最小，因此为了防止嵌套过深，最先入栈的左括号反而要急着出栈匹配右括号。这种先入的要先出的模式让我想到了可以用队列实现括号匹配。
如果此时队列还存在未匹配的左括号，仍然会与当前配对的括号形成嵌套关系。为了拆散这种嵌套关系，还需要切换group。

因此，有了如下解法。

```java
    public int[] maxDepthAfterSplit(String seq) {
        char[] chars = seq.toCharArray();
        Queue<Integer> lefts = new LinkedList<>();
        int[] groups = new int[chars.length];
        int group = 0;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == '(') {
                lefts.add(i);
            } else if (chars[i] == ')') {
                Integer left = lefts.poll();
                groups[left] = group;
                groups[i] = group;
                group = (1 + group) % 2;
            }
        }
        return groups;
    }
```