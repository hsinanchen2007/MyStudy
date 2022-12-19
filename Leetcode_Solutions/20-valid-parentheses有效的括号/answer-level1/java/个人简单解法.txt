### 解题思路
对这道题 我们先观察题目规律 
1.遇到左括号就入栈 
2.遇到右括号就出栈，将出栈的 与现在的右括号在键值对中对应的括号作比较 若不相等就说明不是有效字符串 相等则继续比较

注意 ： 
1.若栈空了使用pop出栈会报错！
2.若经过以上遍历之后 栈里还有元素 则同样说明不是有效字符串
### 代码

```java
class Solution {
public boolean isValid(String s) {
		Map<Character, Character> map = new HashMap<Character, Character>();
		map.put(')', '(');
		map.put(']', '[');
		map.put('}', '{');
		Stack<Character> st = new Stack<>();
		char[] a = s.toCharArray();
		if (a.length%2!=0) {
			return false;
		}
		for (char c : a) {
			if(c=='('||c=='['||c=='{') {
				st.push(c);
			}else {
				if(st.empty()) {
					return false;
				}
				if(st.pop()!=map.get(c)) {
					return false;
				}
			}
		}
		if(!st.empty()) {
			return false;
		}else {
			return true;
		}
	}
}
```