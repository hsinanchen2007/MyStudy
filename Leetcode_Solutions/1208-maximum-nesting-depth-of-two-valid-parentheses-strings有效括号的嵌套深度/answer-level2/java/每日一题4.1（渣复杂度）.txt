### 解题思路
利用栈的帮助，观察例子可以发现每个左括号表示一种嵌套深度，换句话说按顺序读取字符，每个左括号都入栈，每个右括号都出栈，我们可以发现每个左括号都有属于自己的栈深，我们根据栈深的奇偶性将其分为两组：0和1，也就是题目中的A和B组。所以思路就是判断左括号，是的话算奇偶再入栈，相反的如果是右括号就先出栈再算奇偶，刚好反过来。

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
         int[] res = new int[seq.length()];
         Stack<Character> stack = new Stack<>();
         for(int i=0;i<seq.length();i++){
             char c=seq.charAt(i);
             if(c=='('){
                 res[i]=stack.size()%2;
                 stack.push(c);
             }else{
                 stack.pop();
                 res[i]=stack.size()%2;
             }
         }
         return res;
    }
}
```