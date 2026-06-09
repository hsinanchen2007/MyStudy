### 感谢大佬lee215 
搬运自国际站，[这是链接](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/383670/JavaC%2B%2BPython-Why-not-O(N))
### 解题思路1：暴力法
使用栈去匹配左括号，不断的反转两个括号之间的内容，最后输出的时候省略掉左括号和右括号就好。
时间复杂度：O(N^2),空间复杂度O(N)

### 代码
```java
public String reverseParentheses(String s) {
    Stack<Integer> stack = new Stack<>();
    StringBuilder res = new StringBuilder();
    char[] chs = s.toCharArray();

    for (int i = 0; i < chs.length; i++) {
        if (chs[i] == '(') {
            stack.push(i);
        } else if (chs[i] == ')') {
            reverse(chs, stack.pop() + 1, i - 1);
        }
    }
    for (char ch : chs) {
        if (ch != '(' && ch != ')') {
            res.append(ch);
        }
    }
    return res.toString();
}

private void reverse(char[] chs, int start, int end) {
    while (end > start) {
        char temp = chs[end];
        chs[end] = chs[start];
        chs[start] = temp;
        start++;
        end--;
    }
}
```
#### 解题思路2：黑魔法之虫洞法
先看第一张图：**魔法原理图**
![image.png](https://pic.leetcode-cn.com/6220d80727ca3416caae24e298fe54bd0f4ce5cfbd6808a66d6e6069da2cb8e5-image.png)
可能不太懂，再看下这个**魔法实践**
![leetcode1190.gif](https://pic.leetcode-cn.com/10166eb49e485ee1b9abb5a32d4d1a20f4f3bb3840dc696ebf658194582347a2-leetcode1190.gif)
**时间复杂度：O(N)**
```java
class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        Stack<Integer> stack = new Stack<>();
        int[] pair = new int[n];

        //先去找匹配的括号
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else if (s.charAt(i) == ')') {
                int j = stack.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        StringBuilder res = new StringBuilder();
        // i是当前位置 | d是方向,1就是向右穿
        for (int i = 0, d = 1; i < n; i+=d) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                // 如果碰到括号，那么去他对应的括号，并且将方向置反
                i = pair[i];
                d = -d;
            } else {
                res.append(s.charAt(i));
            }
        }
        return res.toString();
    }
}
```