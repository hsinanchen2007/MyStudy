### 解法一：栈
左括号入栈，右括号出栈。通过栈的空与否判断是否最外层括号。

代码：
```java
class Solution {
    public String removeOuterParentheses(String S) {
        String ans = "";
        Stack<Character> stack = new Stack<Character>();
        char[] s = S.toCharArray();
        int begin = 1;
        for(int i = 0; i < s.length; i++)
        {
            if(s[i] == '(')    stack.push(s[i]);
            else
            {
                stack.pop();
                if(stack.isEmpty())
                {
                    ans += S.substring(begin, i);
                    begin = i + 2;
                }
            }
        }
        return ans;
    }
}
```

### 解法二：计数法
用栈的本质就是为了一对对消除括号，直至栈为空，就找到了最外层括号。
归根结底，消除成对的括号不需要用到栈，用了栈可以存储之前的括号，检查括号是否有效。但题目提到给定的字符串是有效的，即括号都是合法的，那么消除成对的括号就可以不用栈，直接计数即可。
当计数器为零时，就相当于栈为空，也就找到了最外层括号。

```java
class Solution {
    public String removeOuterParentheses(String S) {
        String ans = "";
        int count = 0;
        int begin = 1;
        char[] s = S.toCharArray();
        for(int i = 0; i < s.length; i++)
        {
            if(s[i] == '(') count++;
            else            count--;
            if(count == 0)
            {
                ans += S.substring(begin, i);
                begin = i + 2;
            }
        }
        return ans;
    }
}
```