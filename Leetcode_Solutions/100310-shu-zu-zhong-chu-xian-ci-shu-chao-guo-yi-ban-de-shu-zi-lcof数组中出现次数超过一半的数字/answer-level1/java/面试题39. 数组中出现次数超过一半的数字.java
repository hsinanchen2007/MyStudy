### 解题思路
用栈，栈为空或栈顶元素和当前元素相同入栈，不同则出栈，并删除两元素，栈中剩余即为所求；

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {

        Stack<Integer> stack = new Stack<Integer>();


        for(int item : nums){

            if(stack.isEmpty() || stack.peek() == item)
                stack.push(item);
            else
                stack.pop();
        }

        return stack.isEmpty() ? 0 : stack.pop();
    }
}
```