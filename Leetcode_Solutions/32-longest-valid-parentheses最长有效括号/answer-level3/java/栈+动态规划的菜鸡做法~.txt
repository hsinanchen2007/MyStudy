栈+dp的思路，首先想到的就是这种解法，感觉还是很好理解的，栈中存索引，`dp[i]` 代表以`i`位置括号结尾的最长有效括号，当遇到右括号的时候将栈顶的左括号的索引`left`弹出来，两者形成的括号长度再加上左括号索引前一个元素`dp[left-1]`就是当前位置的`dp[i]`

```java
public int longestValidParentheses(String s) {
    if (s==null || s.length()<=0) {
        return  0;
    }
    Stack<Integer> stack=new Stack<>();
    int[] dp=new int[s.length()]; //以i位置括号结尾的最长有效括号
    dp[0]=0;
    int res=0;
    for (int i=0;i<s.length();i++) {
        if (s.charAt(i)=='(') {
            stack.push(i); //dp[i]=0
        }else{
            if(!stack.isEmpty()){
                int left=stack.pop();
                dp[i]= left==0?i-left+1:dp[left-1]+i-left+1;
                res=Math.max(res,dp[i]);
            }//else dp[i]=0  
        }
    }
    return res;
}
```

