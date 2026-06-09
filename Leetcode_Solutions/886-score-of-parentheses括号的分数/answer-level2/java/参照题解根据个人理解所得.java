### 解题思路
此处撰写解题思路
首先初始化一个栈（先进后出），并且先压入一个0（用于最后返回值），遇到“（”就将0压入栈，遇到“）”就将本层的数字乘2加上上一层的值压入上一层的深度，这时就需要将本层和上一层弹出，并且将上一层的值存储起来。特殊情况：当遇到“）”本层为“（”时只将得分加一在上层的深度上，这时就需要将本层和上一层弹出，并且将上一层的值存储起来在加一再压入栈。

### 代码

```java
class Solution {
    public int scoreOfParentheses(String S) {
         Stack<Integer> stack = new Stack<>();
         stack.push(0);
         int num,sum=1;
          for (int i = 0; i < S.length(); i++){
             
            
              if(S.charAt(i) =='('){
                  stack.push(0);
              }
            
             else
             {
                 if(S.charAt(i-1) =='(')
                 {
                    stack.pop();
                   int c = stack.pop();
                    stack.push(1+c);
                 }
                 if(S.charAt(i-1) ==')')
                {
                    int a =  stack.pop();
                    int b =  stack.pop();
                    stack.push(a*2+b);
                 } 
                 
             }
          } 
          return stack.pop();
    }
}
```