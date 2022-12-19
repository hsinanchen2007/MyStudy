### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int len = pushed.length;
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        for (int x : pushed){
            stack.push(x);
           while (!stack.isEmpty() && i < len && stack.peek() == popped[i] ){
                stack.pop();
                i++;
            }
        }
        return i == len;
    }
}
```