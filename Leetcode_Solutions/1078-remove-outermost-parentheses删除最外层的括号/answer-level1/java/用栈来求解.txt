### 解题思路
主要是找到每个原语的位置 第一个括号和第一个与之对应的闭括号位置

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
      Stack<Character>stack=new Stack<>();
        StringBuilder stringBuilder=new StringBuilder();
       int start=0,end=0;
       for(int i=0;i<S.length();i++){
           char c=S.charAt(i);

           if(c=='('){
               if(stack.isEmpty()){
                   start=i;
               }
               stack.push(c);
           }


           if(c==')'){
               stack.pop();
               if(stack.isEmpty()){
                   end=i;
                   stringBuilder.append(S.substring(start+1,end));
               }
           }

       }
       return stringBuilder.toString();
    }
}
```