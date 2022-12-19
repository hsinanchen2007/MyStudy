### 解题思路
两个栈A B，遍历字符串，哪个栈深度低，将把左括号往那个栈里压。哪个栈深度高，右括号就归哪个栈，同时出栈一个括号。

### 代码

```java
class Solution {
 public int[] maxDepthAfterSplit(String seq) {
        final char leftSide = '(';
        final char rightSide = ')';
        final int inStackA = 0;
        final int inStackB = 1;

        Stack<Character> stackA = new Stack<>();
        Stack<Character> stackB = new Stack<>();
        int[] result = new int[seq.length()];
        for (int i = 0; i < seq.length(); ++i) {
            if (leftSide == seq.charAt(i)) {
                //左括号哪个栈少，往那个里面加，并记录其所在的栈
                if (stackA.size() < stackB.size()) {
                    stackA.push(leftSide);
                    result[i] = inStackA;
                } else {
                    stackB.push(leftSide);
                    result[i] = inStackB;
                }


            } else {
                if (stackA.size() > stackB.size()) {
                    stackA.pop();
                    result[i] = inStackA;
                } else {
                    stackB.pop();
                    result[i] = inStackB;
                }


            }

        }


        return result;
    }
}
```