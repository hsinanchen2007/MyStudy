### 解题思路
主要思路：
1.将序列1入栈
2.比较栈顶元素和序列2元素是否相同，
2.1相同就出栈，序列2的指针后移
2.2不相同就继续循环
3.最后判断栈中是否还剩下元素，剩下元素就说明不是弹出序列（因为不是弹出序列所以一直无法相等就无法出栈）

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> res=new Stack<>();
        int index=0;
        for(int i=0;i<pushed.length;i++){
            res.push(pushed[i]);
            while(!res.isEmpty()&&index<pushed.length&&res.peek()==popped[index]){
                res.pop();
                index++;
            }
        }
        return res.isEmpty();
    }
}
```