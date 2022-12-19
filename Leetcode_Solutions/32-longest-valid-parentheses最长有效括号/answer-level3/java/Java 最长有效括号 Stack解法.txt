### 解题思路
1.有效括号问题想到使用Stack
2.长度问题想到下标
综上，使用栈求解，并且栈中存放下标。

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        if(s == null || s.length() < 2) return 0 ;
        char[] ss = s.toCharArray() ;
        Stack<Integer> stack = new Stack() ;
        stack.push(-1) ;
        int max = 0 ;
        for(int i = 0 ; i < ss.length ; i++){
            if(ss[i] == '('){
                stack.push(i) ;
            }else{
                stack.pop() ;
                if(stack.isEmpty()){
                    stack.push(i) ;
                }else{
                    max = Math.max(i - stack.peek() , max) ;
                }
            }
        } 
        return max ;
    }
}
```