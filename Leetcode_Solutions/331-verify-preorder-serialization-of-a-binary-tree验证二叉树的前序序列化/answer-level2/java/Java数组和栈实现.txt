按惯例附上2种实现。

解题思路(**建议理解了栈实现方法后再看数组实现,会更容易理解**)：
1. 如果字符串有且仅有一个#，直接true
2. 依次入栈，当有两个#连续出现时，将栈里的#出栈，然后并将栈顶元素换成#(先栈顶出栈，再push("#")),若换了之后仍然有2个连续的#，继续将2个#出栈，栈顶换成#，直到没有连续的#出现，如果出栈过程中栈为空，直接返回fasle
3. 遍历结束后，如果栈为空，返回true，否则false
<br>
总的来说就是：当**遇到2个连续的#时将它们换成1个#**，换的过程中如果栈空了但没遍历完，直接false，如果遍历结束了栈空则true,非空则false

```java
class Solution {
    // 数组实现(略有提升)  42.80%  44.72%  10ms	36.7 MB
	public static boolean isValidSerialization(String preorder) {
		String[] s = preorder.split(",");
		if (s.length == 1 && "#".equals(s[0])) {
			return true;
		}
		String[] stack = new String[s.length];
		int index = 0;
		for (int i = 0; i < s.length; i++) {
			if (index == 0) {
				stack[index++] = s[i];
			} else if ("#".equals(s[i])) {
				while (index != 0 && "#".equals(stack[index - 1])) {
					index--;
					if (index == 0) {
						return false;
					}
					index--;
				}
				if (i != s.length - 1) {
					stack[index++] = "#";
				}
			} else {
				stack[index++] = s[i];
			}
		}
		return index == 0;
	}

	// 栈实现 慢 22% 5%  14ms	38.1 MB
	public static boolean isValidSerialization_stack(String preorder) {
		String[] s = preorder.split(",");
		//1. 如果字符串有且仅有一个#，直接true
		if (s.length == 1 && "#".equals(s[0])) {
			return true;
		}
		Stack<String> stack = new Stack<>();
		for (int i = 0; i < s.length; i++) {
			if (stack.isEmpty()) {
				stack.push(s[i]);
			} else if ("#".equals(s[i])) {
/*
2. 依次入栈，当有两个#连续出现时，将栈里的#出栈，然后并将栈顶元素换成#(先栈顶出栈pop()，再push("#")),
若换了之后仍然有2个连续的#，继续将2个#出栈，栈顶换成#，直到没有连续的#出现，
如果出栈过程中栈为空，直接返回fasle.
*/
				while (!stack.isEmpty() && "#".equals(stack.peek())) {
					stack.pop();
					if (stack.isEmpty()) {
						return false;
					}
					stack.pop();
				}
				//没有遍历到最后一个元素时才入栈#，否则栈恒为非空
				if (i != s.length - 1) {
					stack.push("#");
				}
			} else {
				stack.push(s[i]);
			}
		}
//3. 遍历结束后，如果栈为空，返回true，否则false
		return stack.isEmpty();
	}
}
```
