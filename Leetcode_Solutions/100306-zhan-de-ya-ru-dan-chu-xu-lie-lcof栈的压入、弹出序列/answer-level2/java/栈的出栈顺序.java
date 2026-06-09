### 解题思路
此处撰写解题思路
我们可以新建一个栈用于模拟对应的出栈顺序，先进站，然后如果此时的栈顶元素在出栈数组里，则开始出站，还需要一个元素记录出栈元素的位置，相等就出栈然后继续判断栈顶元素是否相同。最后判断栈是否为空，如果是则为真，不是则为假。
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int count = 0;
        for(int i = 0; i < pushed.length; i++){
            stack.push(pushed[i]);
            while(!stack.isEmpty() && stack.peek() == popped[count]){
                stack.pop();
                count++;
            }
        }
        return stack.isEmpty();
    }
}
```