## 两种解法

### 解法一：使用栈
最普通的解法，使用栈，遍历字符串，通过压入弹出完成处理。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack<Character>();
        for(char c : S.toCharArray())
        {
            if(!stack.isEmpty() && c == stack.peek())
                stack.pop();
            else stack.push(c);
        }
        String ans = "";
        while(!stack.isEmpty())
            ans = stack.pop() + ans;
        return ans;
    }
}
```

### 解法二：使用数组模拟栈
定义一个变量（本解法中的j），初始化为0，用于记录下一次赋值的下标。
具体处理过程见代码。

时间复杂度：O(n)。
空间复杂度：O(n).

代码：
```java
class Solution {
    public String removeDuplicates(String S) {
        char[] s = S.toCharArray();
        int j = 0;
        for(int i = 0; i < s.length; i++)
        {
            if(j == 0 || s[i] != s[j-1])
                s[j++] = s[i];
            else    j--;
        }
        return new String(s, 0, j);
    }
}
```