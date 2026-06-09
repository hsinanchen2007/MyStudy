## 两种解法

### 解法一：栈
利用栈，遇到字母，将其压入栈，遇到退格，相当于从栈顶弹出元素。处理完所有字符后，得到最终的字符串。
比较两个字符串用上述方法得到的最终结果是否相等。

时间复杂度：O(n)。n为两字符串长度之和。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        return toRes(S).equals(toRes(T));
    }
    private String toRes(String s) {
        Stack<Character> stack = new Stack<Character>();
        for(char c : s.toCharArray())
        {
            if(c != '#')
                stack.push(c);
            else if(! stack.isEmpty())
                stack.pop();
        }
        return String.valueOf(stack);
    }
}
```

### 解法二：逆序遍历直接比较
倒着遍历的好处是可以直接跳过需要退格的字符，剩下的有效字符直接进行比较即可。
官方的解法二代码没有充分复用，并且一行写多条语句，这里稍微做了点改进。

时间复杂度：O(n)。
空间复杂度：O(1)。

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1, j = T.length() - 1;
        while(i >= 0 || j >= 0)
        {
            i = getValidIndex(i, S);
            j = getValidIndex(j, T);
            if(i >=0 && j >= 0 && S.charAt(i) != T.charAt(j))
                return false;
            if((i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
    private int getValidIndex(int idx, String s) {
        int cnt = 0;
        while(idx >= 0)
        {
            if(s.charAt(idx) == '#')
            {
                idx--;
                cnt++;
            }
            else if(cnt > 0)
            {
                idx--;
                cnt--;
            }
            else    break;
        }
        return idx;
    }
}
```