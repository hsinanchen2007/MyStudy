需要一个栈，遍历数组时处理两种情况：

① 当数组元素等于栈顶元素或栈为空时入栈；

② 当元素不等于栈顶元素时则出栈。

最后的栈顶元素即为众数。

```
    public int majorityElement(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        for(int i:nums){
            if(stack. empty()||i==stack.peek()){
                stack.push(i);
            }else{
                stack.pop();
            }
        }
        return stack.peek();
    }
```