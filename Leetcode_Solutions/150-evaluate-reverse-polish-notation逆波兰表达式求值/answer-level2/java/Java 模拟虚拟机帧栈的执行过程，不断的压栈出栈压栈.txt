```java
class Solution {
        // 模拟 Java 字节码帧栈的执行过程，遇到计算符号时，栈顶两个数出栈进行计算后重新入栈。否则直接压栈。
        // 最终栈中只有一个元素就计算结果。
        // 注意运算时顺序
        public int evalRPN(String[] tokens) {
            final Deque<Integer> deque = new LinkedList<>();
            for (String s : tokens) {
                if ("+".equals(s)) {
                    Integer pop1 = deque.pop();
                    Integer pop2 = deque.pop();
                    deque.push(pop2 + pop1);
                } else if ("-".equals(s)) {
                    Integer pop1 = deque.pop();
                    Integer pop2 = deque.pop();
                    deque.push(pop2 - pop1);
                } else if ("*".equals(s)) {
                    Integer pop1 = deque.pop();
                    Integer pop2 = deque.pop();
                    deque.push(pop2 * pop1);
                } else if ("/".equals(s)) {
                    Integer pop1 = deque.pop();
                    Integer pop2 = deque.pop();
                    deque.push(pop2 / pop1);
                } else {
                    deque.push(Integer.valueOf(s));
                }
            }
            return deque.pop();
        }
}
```