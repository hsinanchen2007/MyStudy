简单清晰的做法：使用一个栈用于暂存得不到计算的数字（无法确定优先级，比如当前是"+"，那么可能下一个操作符是"*"，所以暂时无法计算）。
- 如果是空格，跳过即可；
- 如果是"+"或数字字符，则向栈中push进一个数字；
- 如果是"-"，则获得下一个数字，并向栈中push进它的负数形式；
- 如果是"*"，则获得下一个数字，并向栈中push进栈顶数字和下一个数字的乘积；
- 如果是"/"，则获得下一个数字，并向栈中push进栈顶数字和和一个数字的商。

<br>
```java
class Solution {
    public int calculate(String s) {
        Deque<Integer> stack = new ArrayDeque<>();
        char ch;
        int[] ret;
        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (ch == ' ') 
                continue;
            ret = getNextNumber(s, i);
            if (Character.isDigit(ch) || ch == '+') {
                stack.push(ret[0]);
            } else if (ch == '-') {
                stack.push(-ret[0]);
            } else if (ch == '*') {
                stack.push(stack.pop() * ret[0]);
            } else if (ch == '/') {
                stack.push(stack.pop() / ret[0]);
            }
            i = ret[1]; //调整索引为，获得的下一个数字的末尾索引
        }
        // 返回计算结果
        int[] ans = {0};
        stack.forEach(num -> ans[0] += num);
        return ans[0];
    }
    // 返回下一个数字
    private int[] getNextNumber(String s, int i) {
        int num = 0;
        while (!Character.isDigit(s.charAt(i))) 
            i++;
        while (i < s.length() && Character.isDigit(s.charAt(i)))
            num = 10 * num + s.charAt(i++) - '0';
        return new int[] {num, i-1}; // 返回得到的数字及该数字最后一个数字字符的索引
    }
}
```
