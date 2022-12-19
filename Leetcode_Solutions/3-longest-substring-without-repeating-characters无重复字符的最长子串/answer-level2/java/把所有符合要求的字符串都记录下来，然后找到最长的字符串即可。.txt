### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
int len = s.length();
		Set<String> set = new HashSet<String>();
		Stack<Character> stack = new Stack<Character>();
		Stack<Character> stack02 = new Stack<Character>();
		for (int i = 0; i < len; i++) {
			Character c = s.charAt(i);
			if (!stack.contains(c)) {
				stack.push(c);
				continue;
			} else {
				StringBuffer buff = new StringBuffer();
				for (int j = 0; j < stack.size(); j++) {
					buff.append(stack.get(j));
				}
				set.add(buff.toString());
				Character c02 = stack.pop();
				while (true) {
					if (c02 == c) {
						break;
					}
					stack02.push(c02);
					c02 = stack.pop();
				}
				stack.clear();
				while (!stack02.isEmpty()) {
					stack.push(stack02.pop());
				}
				stack.push(c);
			}
		}
		StringBuffer buff1 = new StringBuffer();
		for (int j = 0; j < stack.size(); j++) {
			buff1.append(stack.get(j));
		}
		set.add(buff1.toString());
		System.out.println(set.toString());
		int max = 0;
		for (String ss : set) {
			if (ss.length() > max) {
				max = ss.length();
			}
		}
		return max;
    }
}
```