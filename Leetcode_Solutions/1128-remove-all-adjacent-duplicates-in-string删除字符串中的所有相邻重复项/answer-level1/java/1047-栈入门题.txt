### 解题思路
1. 字符串转成`char[]`数组
2. 遍历`char[]`数组，判断当前 字符 和  栈顶字符是否相同
- 如果相同，栈顶`字符`出栈
- 如果不同，当前`字符`入栈

### 复杂度
因为遍历了字符数组，所以：时间复杂度为 `O(N)`
因为使用了长度为N的栈空间，所以：空间复杂度为 `O(N)`



```
    public String removeDuplicates(String str) {
        char[] characters = str.toCharArray();
        Stack<Character> stack = new Stack<>();

        for (char character : characters) {
            if (stack.size() > 0 && character == stack.lastElement()) {
                stack.pop();
            }

            stack.push(character);
        }

        StringBuilder stringBuilder = new StringBuilder();
        while (!stack.empty()) {
            stringBuilder.insert(0, stack.pop());
        }

        return stringBuilder.toString();
    }
```
