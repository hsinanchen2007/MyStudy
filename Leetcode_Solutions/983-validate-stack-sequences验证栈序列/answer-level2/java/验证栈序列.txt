### 解题思路
    辅助栈的思想，具体解析见代码

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if(pushed.length!=popped.length)
            return false;
        Stack <Integer> stack=new Stack<>();  //定义一个辅助栈
        /*遍历pushed数组，将pushed数组放入stack栈中，若栈顶元素等于poped的元素，则出栈。出栈后
    popped数组指针加1*/
        int index=0;    //popped数组的指针
        for(int i=0;i<pushed.length;i++)
        {
            stack.push(pushed[i]);
            while(!stack.isEmpty()&&stack.peek()==popped[index])
            {
                stack.pop();
                index++;
            }
        }
        return stack.isEmpty();   //判断栈是否为空，如果栈空，则说明栈序列是对的。
    }
}
```