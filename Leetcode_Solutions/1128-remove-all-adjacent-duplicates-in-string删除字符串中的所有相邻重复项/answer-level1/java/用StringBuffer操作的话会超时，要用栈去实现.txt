### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack();
		stack.push(S.charAt(0));
		for(int i=1;i<S.length();i++) {
			if(stack.size()==0) {
				stack.push(S.charAt(i));
				continue;
			}
			if(S.charAt(i)==stack.peek()) {
				stack.pop();
			}else {
				stack.push(S.charAt(i));
			}
		}
		String str="";
		for(int i=0;i<stack.size();i++) {
			str+=stack.get(i);
		}
		return str;
    }
}
```