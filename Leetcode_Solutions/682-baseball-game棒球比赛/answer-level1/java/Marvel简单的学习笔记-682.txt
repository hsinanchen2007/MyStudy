### 解题思路
思路比较简单，用栈存储有效的分数，用代码一步一步模拟计算总分的过程即可。

时间复杂度：O(n)。
空间复杂度：O(n)。

### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<Integer>();
        for(String s : ops)
        {
            if(s.equals("+"))
            {
                int t = stack.pop();
                int score = t + stack.peek();
                stack.push(t);
                stack.push(score);
            }
            else if(s.equals("D"))
                stack.push(stack.peek() * 2);
            else if(s.equals("C"))
                stack.pop();
            else
                stack.push(Integer.parseInt(s));
        }
        int sum = 0;
        for(int i : stack)
            sum += i;
        return sum;
    }
}
```