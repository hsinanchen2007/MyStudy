### 解题思路
此处撰写解题思路
存下标用栈来解题
### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        int max=0;
        //创建一个栈
        Stack<Integer> stack=new Stack<>();
        //-1入栈
        stack.push(-1);
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) =='('){
                //下标入栈
                stack.push(i);
            }else{
                //栈顶出栈（后进先出）
                stack.pop();
                //判断栈里是不是为空
                if(stack.empty()){
                    stack.push(i);
                }else{
                    //用i减去栈顶的元素 得到最长有效括号
                    max = Math.max(max,i-stack.peek());
                }
            }
        }
        return max;
    }
}
```