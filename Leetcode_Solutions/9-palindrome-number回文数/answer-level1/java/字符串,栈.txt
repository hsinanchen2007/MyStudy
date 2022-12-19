### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        StringBuffer sb = new StringBuffer();
        String a=String.valueOf(x);
        Stack<Character> stack = new Stack<>();
        for (char ch : a.toCharArray()) {
			stack.push(ch);
		}
        while (!stack.empty()) {
			sb.append(stack.pop());
		}
        return a.equals(sb.toString());
    }
}
```