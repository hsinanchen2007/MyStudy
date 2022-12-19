![canvas.png](https://pic.leetcode-cn.com/00c9b417f41a947bce7313cde90d5564ac8e0c2cf2825fb0734535f9843a5119-canvas.png)


**数组模拟栈**

```java
class Solution {
    public boolean isValid(String s) {

        // 空字符串
        if (s.length() == 0)
            return true;
        // 排除奇数长度(位运算)
        if ((s.length() & 1) == 1)
            return false;

        // 栈元素个数
        int index = 0;
        // 栈
        char[] stack = new char[s.length()];

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '(':
                case '[':
                case '{':
                    // 进栈
                    stack[index++] = s.charAt(i); 
                    continue;
                case ')':
                    if (index == 0 || stack[--index] != '(')
                        return false;
                    // stack[--index] == '(' ，才会contniue
                    // --index：相当于满足的元素出栈
                    continue;
                case ']':
                    if (index == 0 || stack[--index] != '[')
                        return false;
                    continue;
                case '}':
                    if (index == 0 || stack[--index] != '{')
                        return false;
                    continue;
            }
        }

        return index == 0; // 判断栈是否为空
    }
}
```

**栈的写法**
```java
class Solution {
    public boolean isValid(String s) {
        if (s.length() == 0)
            return true;
        if ((s.length() & 1) == 1)
            return false;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '(':
                case '[':
                case '{':
                    stack.push(s.charAt(i));
                    continue;
                case ')':
                    if (stack.isEmpty() || stack.pop() != '(')
                        return false;
                    continue;
                case ']':
                    if (stack.isEmpty() || stack.pop() != '[')
                        return false;
                    continue;
                case '}':
                    if (stack.isEmpty() || stack.pop() != '{')
                        return false;
                    continue;
            }
        }
        return stack.isEmpty();
    }
}
```



