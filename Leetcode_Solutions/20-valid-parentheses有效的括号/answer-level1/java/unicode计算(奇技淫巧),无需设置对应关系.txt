运用unicode码进行计算
附上一个码表给大家观察:
https://unicode-table.com/cn/#control-character
举例:
'}' - '{' >=2
[( 等同理


```
class Solution {
    public boolean isValid(String s) {
		if (s.length() % 2 != 0)
			return false;
		char[] inputStrChars = s.toCharArray();
		Stack<Character> stack = new Stack<Character>();
		for (char foo : inputStrChars) {
			if (foo == '(' || foo == '[' || foo == '{') {
				stack.add(foo);
			} else {
				if (stack.isEmpty())
					return false;
				char top = stack.pop();
				if(foo - top<=2&&foo - top>0){
					continue;
				}
				return false;
			}
		}
		return stack.isEmpty();   
    }
}
```
