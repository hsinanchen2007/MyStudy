### 解题思路
1. 把pushed数组按照顺序模拟入栈
2. 当栈顶元素跟popped数组的开始元素相同时，做出栈操作。
3. 其中定义数组模拟栈的出栈，入栈，获取栈顶元素
4. 数组模拟栈的API操作：
    * push: stack[stackIdx++] = arr[arrIdx++];
    * pop: stackIdx--;
    * peek: arr[arrIdx - 1]
    * isEmpty: stackIdx != 0

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int len = pushed.length;
        int[] stack = new int[len];
        // si: stackIndex, ps: pushedIndex, pp: poppedIndex
        for (int si = 0, ps = 0, pp = 0; ps < len || si > 0; ) {
            if (si != 0 && stack[si - 1] == popped[pp]) {
                pp++;
                si--;
            } else if (ps < len) {
                stack[si++] = pushed[ps++];
            } else {
                return false;
            }
        }
        return true;
    }
}
```