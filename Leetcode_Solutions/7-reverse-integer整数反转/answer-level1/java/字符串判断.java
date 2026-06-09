### 解题思路
此处撰写解题思路

### 代码

```java
import java.math.BigInteger;
import java.util.Stack;
class Solution {
    public int reverse(int x) {
        int result = 0;
		String a = String.valueOf(x);
		Stack<Character> stack = new Stack<>();

		StringBuffer sb = new StringBuffer();
		if (a.startsWith("-")) {
			for (char ch : a.substring(1).toCharArray()) {
				stack.push(ch);
			}
			sb.append("-");
		} else {
			for (char ch : a.toCharArray()) {
				stack.push(ch);
			}
		}
		while (!stack.empty()) {
			sb.append(stack.pop());
		}
		try {
			result = Integer.parseInt(sb.toString());
		}catch (NumberFormatException e) {
			
		}
		return result;
    }
}
```