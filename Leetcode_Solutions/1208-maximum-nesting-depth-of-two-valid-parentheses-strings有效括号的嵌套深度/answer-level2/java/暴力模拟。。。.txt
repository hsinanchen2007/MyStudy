### 解题思路
一下子没看出奇偶规律，采用的类似有效括号的嵌套深度来做的。。。

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        char[] chars = seq.toCharArray();
        int length = chars.length;
        Stack<Integer> stack = new Stack<>();
        int[] ans = new int[length];
        int record = 0;
        // 本质上左括号的栈帧是 字符+其应该有的flag值
        for(int i = 0; i < length; i++) {
            if(chars[i] == '(') {
                if(stack.isEmpty()) {
                    stack.push(i);
                    ans[i] = record;
                } else{
                    record = Math.abs(ans[stack.peek()] - 1);
                    stack.push(i);
                    ans[i] = record;
                }
            } else {
                int c = stack.peek();
                ans[i] = ans[c];
                stack.pop();
            }
        }
        if(stack.isEmpty()) {
            return ans;
        }
        return new int[]{-1};
    }
}
```