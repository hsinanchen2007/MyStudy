####思路：
1. 遍历seq，遇到`(`则压入栈
2. 遇到`)`则计算：
- 使用`stack.size()`获取当前深度
- 当前遍历`stack.pop()`和`i` 获取括号的左右下标
- `depth%2` 判断负责为`1` 还是`0`

```java []
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if (seq == null || seq.isEmpty()) {
            return new int[0];
        }
        int[] result = new int[seq.length()];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                stack.push(i);
            } else {
                int depth = stack.size();
                int left = stack.pop();
                if (depth % 2 == 0) {
                    result[left] = 1;
                    result[i] = 1;
                }
            }
        }
        return result;
    }
}
```