### 解题思路
可以采用一个栈去模拟整个过程；
将pushed[] 数组中的元素依次放入栈中；
如果stack栈顶元素等于poped的第j个元素，弹出栈顶元素
直到栈是否为空；

### 代码

```java
class Solution {
    //采用栈，按照顺序，存入到栈中；
    //如果栈顶的元素等于poped数组的第一个元素，弹出对应的元素；
    //判断一下最终的栈是否为空即可
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if(pushed.length!=popped.length) return false;
        Stack<Integer> stack =  new Stack<>();
        int n = pushed.length;
        int j = 0;
        for(int x:pushed){
            stack.push(x);
            while(j<n&&!stack.isEmpty()&&stack.peek()==popped[j]){
                stack.pop();
                j++;
            }
        }
        return stack.isEmpty();
    }   
}
```