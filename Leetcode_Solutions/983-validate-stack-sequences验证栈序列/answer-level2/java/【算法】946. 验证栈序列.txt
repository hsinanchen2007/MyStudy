### 解题思路
1. 使用LinkedList来模拟栈，遍历入栈和出栈的数组, 两个下标分别用 push 和 pop 代替
* 如果 pushed[push] == poped [pop] 则入栈后立马出栈，两个下标分别后移即可，否则；
* 如果 栈顶元素 == poped[pop]，则出栈顺序相符，出栈并且把pop下标后移，否则；
* 说明 出栈顺序不符，则pushed中的元素入栈，且push后移。

2. 当pused中的元素全部入栈后，如果仍有元素没有出栈，则需要继续遍历出栈顺序的数组：
* 如果出栈顺序与栈中元素的顺序一致，则返回true，否则；
* 返回false

时间复杂度为：$O(n)$, 空间复杂度为: $O(n)$

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int pushLength = pushed.length;
        int poppedLength = popped.length;
        
        if(pushLength != poppedLength){
            return false;
        }
        if(pushLength == 0){
            return true;
        }
        
        LinkedList<Integer> stack = new LinkedList();
        int push = 0;
        int pop = 0;
        while(push < pushLength && pop < poppedLength) {
            if (pushed[push] == popped[pop]){
                push++;
                pop++;
            } else if (stack.size() > 0 && stack.getFirst().equals(popped[pop])) {
                stack.removeFirst();
                pop++;
            } else {
                stack.addFirst(pushed[push++]);
            }
        }

        while(pop < pushLength && stack.size() > 0) {
            if (!stack.getFirst().equals(popped[pop++])){
                break;
            }
            stack.removeFirst();
        }

        return push == pushLength && pop == poppedLength && stack.size() == 0;
    }
}
```