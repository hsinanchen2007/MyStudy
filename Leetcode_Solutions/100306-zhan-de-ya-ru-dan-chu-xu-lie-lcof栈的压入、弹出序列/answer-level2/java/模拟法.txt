### 解题思路
假设原始元素是 pushed：1 2 3 4 5，popped：4 5 3 2 1
int j = 0;//指示栈顶元素与popped[j]是否相同
1. 依次将pushed入栈
2. 循环判断，如果栈头元素和popped[j]相等，则出栈，j++；否则继续入栈
3. 当j = pushed.length，说明true
### 注意
Java Stack类的peek()方法，当栈为空会返回EmptyStackException(),因此需要先empty()判断
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<Integer>();

        int j = 0;//指示栈顶元素与popped[j]是否相同
        for(int i = 0; i < pushed.length; i++){
            //依次将pushed数组的元素入栈
            
            stack.push(pushed[i]);
            while(!stack.empty()){
                if(stack.peek() == popped[j]){
                    stack.pop();
                    j++;
                }else{
                    break;
                }
            }           
        }

        return j == pushed.length;
    }
}
```