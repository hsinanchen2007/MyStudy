### 解题思路
此处撰写解题思路
栈的运用
### 代码

```java
class Solution {
    public boolean isValid(String s) {
        HashMap<Character,Character> map = new HashMap<>();
		
		map.put(')', '(');
		map.put(']', '[');
		map.put('}', '{');
		
		char[] chars = s.toCharArray();
		Stack<Character> stack = new Stack<>();
		
		for(char c : chars) {
			if(map.containsKey(c)) {
				if(stack.isEmpty()) {
					return false;
				}else {
					if(stack.peek() == map.get(c)) {
						stack.pop();
					}else {
						return false;
					}
				}
			}else {
				stack.push(c);
			}
		}
		return stack.isEmpty();
    }
}
```
![image.png](https://pic.leetcode-cn.com/70d567ad6cc399f6aaed2c24f70a3b911f9373bf62e25f300c9e220c190d2d01-image.png)
