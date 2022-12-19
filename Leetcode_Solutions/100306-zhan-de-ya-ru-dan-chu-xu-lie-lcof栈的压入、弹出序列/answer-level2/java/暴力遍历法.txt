### 解题思路
先压入后检查弹出序列

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        //用于遍历poped
        //确认一个弹出则index++
        int index = 0;
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i < pushed.length;i++){
            stack.push(pushed[i]);
            //防止空栈
            while(!stack.isEmpty() && stack.peek() == popped[index]){
                stack.pop();
                index++;
            }
        }
        return stack.isEmpty();
    }
}
```