```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        
        int index = 0; // 记录出栈的位置
        for(int i = 0; i < pushed.length; i++){
            if(pushed[i] != popped[index]){
                while(stack.size() > 0 && stack.peek() == popped[index]){
                    stack.pop();
                    index++;
                }
                stack.push(pushed[i]);
            } else {
                index++;
            }
        }

        while(stack.size() > 0){
            if(stack.pop() != popped[index]){
                return false;
            }
            index++;
        }

        return true;
    }
}
```
首先将不等于第一个出栈元素的所有元素入栈，因为只要不等于第一个出栈元素，那么就说明pushed前面的所有元素都在栈中。当在pushed和popped中找到一个相同的元素，表示该元素先入栈又出栈，
所以我们直接跳过，将index指向出栈的第二个元素。

如果我们发现pushed指向的元素不等于popped的元素，我们就要判断栈顶的元素是否等于popped中的元素，等于就出栈，并且index++。

当循环完所有的pushed数组，最后我们的栈中会剩下元素，将栈中的元素与popped的元素一一比较即可。
