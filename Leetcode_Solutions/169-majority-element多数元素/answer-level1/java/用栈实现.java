### 解题思路
用栈实现：
栈为空或者和栈顶元素相同，则入栈。
与栈顶元素不同则栈顶元素出栈。

### 代码
```
class Solution {
    public int majorityElement(int[] nums) {
        Stack<Integer> stack=new Stack<>();
        for(int i:nums){
            if(stack.isEmpty()||stack.peek()==i)
                stack.push(i);
            else
                stack.pop();
        }
        return stack.peek();
    }
}

```
