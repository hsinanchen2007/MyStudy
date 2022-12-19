### 解题思路
利用hashmap的k-v存储左右符号常量，
遍历字符串，遇到left符号push到stack中，遇到右符号则从stack中出栈一个符号，
栈顶元素即left 与 遍历到的字符比较是否相等，不等的话，返回false。

### 代码

```java
class Solution {
    private static Map<Character, Character> map = new HashMap<>();
	static {
		map.put('{', '}');
		map.put('(', ')');
		map.put('[', ']');
	}
    public boolean isValid(String s) {
        
		Stack<Character> stack = new Stack<>();
		
		int len = s.length();
		
		for (int i = 0; i < len; i++) {
			char c = s.charAt(i);
			if (map.containsKey(c)) {
				stack.push(c);
			} else { //右括号 ] } )
				if (stack.isEmpty()) return false;
				char left = stack.pop();
				
				if (c != map.get(left)) return false;
				
			}
			
		}
		
		return stack.isEmpty();
	
	

    }
}
```