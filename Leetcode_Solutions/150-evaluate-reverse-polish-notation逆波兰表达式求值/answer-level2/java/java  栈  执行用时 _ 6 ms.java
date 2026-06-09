### 解题思路
遇数进栈，遇操作符出栈两个数进行计算，算完再把结果入栈。
（这咋成中等难度了。。。）

### 代码

```java
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<>();
        int n = tokens.length;

        for (int i = 0; i < n; i++) {
            int a,b;
            switch (tokens[i]) {
                case "+" :
                    b = s.pop();
                    a = s.pop();
                    s.push(a + b);
                    break;
                case "-" :
                    b = s.pop();
                    a = s.pop();
                    s.push(a - b);
                    break;
                case "*" :
                    b = s.pop();
                    a = s.pop();
                    s.push(a * b);
                    break;
                case "/" :
                    b = s.pop();
                    a = s.pop();
                    s.push(a / b);
                    break;
                default:
                    s.push(Integer.parseInt(tokens[i]));
            }
        }
        return s.pop();
    }
}
```