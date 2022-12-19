### 解法一：栈
最基础的思路，不管用栈还是模拟栈，利用后进先出（LIFO）的特性对括号进行匹配：
如果是左括号，则入栈；如果是右括号，则从栈中弹出一个元素，看是否与该右括号匹配。
此外，要注意一些边界条件，还有各种不匹配的情况，栈是否为空等。

时间复杂度：O(n)。最坏情况下，字符串内全是左括号时的时间复杂度。
空间复杂度：O(n)。

代码:
```java
class Solution {
    public boolean isValid(String s) {
        char[] str = s.toCharArray();
        if(str.length == 0)         return true;
        if(str.length % 2 == 1)     return false;
        Stack<Character> stack = new Stack<Character>();
        Map<Character, Character> map = new HashMap<Character, Character>();
        map.put(')', '(');
        map.put(']', '[');
        map.put('}', '{');
        for(char c : str)
        {
            if(map.containsKey(c))
            {
                if(stack.isEmpty() || stack.peek() != map.get(c))
                    return false;
                stack.pop();
            }
            else    stack.push(c);
        }
        return stack.isEmpty();
    }
}
```

### 解法二：字符串


代码：
```java
class Solution {
    public boolean isValid(String s) {
        while(s.contains("()") || s.contains("[]") || s.contains("{}"))
        {
            if(s.contains("()"))    s = s.replace("()", "");
            if(s.contains("[]"))    s = s.replace("[]", "");
            if(s.contains("{}"))    s = s.replace("{}", "");
        }
        return s.isEmpty();
    }
}
```