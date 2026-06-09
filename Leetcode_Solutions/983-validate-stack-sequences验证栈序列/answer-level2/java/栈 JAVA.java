* 以i为pushed数组的下标，j为popped数组的下标，顺序进行遍历
* 定义一个辅助栈s，每一次push(pushed[i])，
* 若s.peek() = popped[j]，则进行pop()，否则i++即可
* 最后判断s是否为空

```
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int j = 0;
        Stack<Integer> s = new Stack<>();
        for(int i = 0; i < pushed.length; i++){
            s.push(pushed[i]);
            while(!s.isEmpty() && s.peek() == popped[j]){
                s.pop();
                j++;
            }
        }
        return s.isEmpty();
    }
}
```