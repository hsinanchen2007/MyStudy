### 解题思路
看了好一会其他人的题解，还是没有找到怎么减少内存开销。
至于解题思路，就是用了栈这个数据结构先进后出的特点，因为括号的匹配也存在着类似先进后出的特点，即最先出现的括号最后进行匹配。

### 代码

```java
class Solution {
    public boolean isValid(String s) {

		Stack<Character> stack = new Stack<>();
		for (char c : s.toCharArray()) {

			if ('{' == c || '(' == c || '[' == c) {

				stack.push(c);
				continue;
			}
			if (('}' == c || ')' == c || ']' == c) && stack.isEmpty()) return false;
			if ('}' == c && '{' != stack.pop()) return false;
			if (']' == c && '[' != stack.pop()) return false;
			if (')' == c && '(' != stack.pop()) return false;
		}
		return stack.isEmpty();
    }
}
```