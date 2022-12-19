### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> s = new Stack<>();
        int n = pushed.length;
        int i = 0, j = 0;
        while(j < n) {
            while((s.isEmpty() || s.peek() != popped[j]) && i < n) {
                s.push(pushed[i++]);
            }
            if(s.peek() != popped[j]) return false;
            while(!s.isEmpty() && s.peek() == popped[j]) {
                s.pop();
                j++;
            }
        }

        return true;
    }
}
```