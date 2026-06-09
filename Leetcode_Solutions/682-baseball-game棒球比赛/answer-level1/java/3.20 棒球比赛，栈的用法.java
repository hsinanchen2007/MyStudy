### 解题思路
1.因为tag是栈，自然而然就想到了要用栈来解决这个问题
2.循环遍历这个栈，如果遇到+，那么push入栈。栈的三个基本操作push peek pop

### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
           Stack <Integer> stack=new Stack();
           for(String op:ops){
               if(op.equals("+")){
                   int top=stack.pop();
                   int newtop=top+stack.peek();
                   stack.push(top);
                   stack.push(newtop);

               }
               else if(op.equals("C"))
               {
                   stack.pop();
               }
               else if(op.equals("D"))
               {
                   stack.push(2*stack.peek());
               }
               else{
                   stack.push(Integer.valueOf(op));
               }

           }
           int ans=0;
           for(int score:stack)ans+=score;
           return ans;
    }
}
```