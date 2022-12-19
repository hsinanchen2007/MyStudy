执行用时打败100%Java用户。
使用Stack数据结构的话会比较慢，本题可以使用数组来模拟，提升空间很大。

核心：
- 如果是字符a或b直接入模拟栈stack，模拟栈大小index++
- 如果是c,则前两个字符必须能组成"ab"，否则直接无效
- 最后模拟栈大小index如果是0,则说明能消除完毕，有效，反之无效

```java
// 纯数组实现
class Solution {
	public static boolean isValid(String S) {
		char[] s = S.toCharArray();
		char[] stack = new char[s.length];
		int index = 0;
		for (char cs : s) {
			if (cs != 'c') {
				stack[index++] = cs;
			} else {
				// 当前字符是c,如果前面不是"ab"串,肯定是false
				if (index < 2 || stack[--index ] != 'b'|| stack[--index] != 'a' ) {
					return false;
				}
			}
		}
		return index == 0;
	}
}
```

以下是栈实现，可以对比一下以上数组实现，基本一致
```java
// 栈实现
class Solution {
	public static boolean isValid_stack(String S) {
		Stack<Character> stack = new Stack<>();
		for (char cs : S.toCharArray()) {
			if (cs == 'a' || cs == 'b') {
				stack.push(cs);
			} else if (cs == 'c') {
				// 当前字符是c,如果前面不是"ab"串,肯定是false
				if (stack.size() < 2 || stack.pop() != 'b' || stack.pop() != 'a') {
					return false;
				}
			}
		}
		return stack.isEmpty();
	}
}
```
