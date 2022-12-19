### 解题思路
此处撰写解题思路
遍历整个字符串，记录连续重复的字符个数。使用栈先入后出的特性。保证栈顶的元素永远是i-1位置的不重复的元素。
关键点 记录遍历过的元素。确定下一个是否和上一个重复。
### 代码

```java
class Solution {
    public String compressString(String S) {
        int length = S.length();
        if (length <= 2) {
            return S;
        }
        Stack<Character> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        int temp = 1;
        for (int i=0;i<length;i++) {
           if (stack.empty()) {
               stack.push(S.charAt(i));
           } else if(stack.peek() == S.charAt(i)) {
               temp++;
           } else {
               sb.append(stack.peek()).append(temp);
               stack.push(S.charAt(i));
               temp = 1;
           }
        }
        sb.append(stack.peek()).append(temp);

        return sb.toString().length() >= length ? S : sb.toString();
    }
}
```