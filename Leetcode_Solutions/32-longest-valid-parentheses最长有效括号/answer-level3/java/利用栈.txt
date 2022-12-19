### 解题思路
如果字符串的长度为0，则直接返回0，首先在栈底存放-1（因为字符串的长度是从0开始），然后判断单个字符是'('还是')'，如果是‘（’,则把字符的下标存放在栈内，如果是‘）’,则取出栈顶元素，然后判断栈是否为空，如果为空，则将‘（’的下标放入栈，如果不为空，则用‘(’的下标减去栈顶的值得到max，如果结果大于之前的max，则更新max。
举例：输入（）
一开始栈底为-1，字符串长度大于0，首先将‘（’的下标存放进栈，栈内元素为[-1,0],当为‘（’时，将栈顶元素取出，此时栈内元素为[-1],栈不为空，则将‘（’的下标减去栈顶元素的值，即1-（-1）=2，所以最长有效括号长度为2
### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
      //定义栈
      Stack<Integer> stack=new Stack<>();
     int max=0;//max为有效括号的长度
      stack.push(-1);//将-1存放在栈底
      //字符串长度为0
      if(s.length()==0){
          max=0;
      }
       //遍历字符串
      for(int i=0;i<s.length();i++){
          //如果为‘（’，则存放进栈
          if(s.charAt(i)=='('){
              stack.push(i);
          }
          //如果为‘）’，则将栈顶元素取出
          else if(s.charAt(i)==')'){
               stack.pop();
               //判断栈是否为空
              if(stack.isEmpty()){
                 //将当前下标的值存放入栈
                  stack.push(i);
              }
              else{
              //如果当前的值大于之前的max,则更新max
                  if(i-stack.peek()>max)
               //当前下标减栈顶
                 max=i-stack.peek();
              }
          }

      }
      return max;
    }
}
```