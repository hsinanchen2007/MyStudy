![2020030301.PNG](https://pic.leetcode-cn.com/65e0eb2442b69c243694c7a17e4591b8c64e4d7a4022745ee577675820f71926-2020030301.PNG)

### 解题思路
**思路:因为有效字符串"abc"的结尾是字符'c',

所以,每遍历到一个字符'c'时,则先判断当前栈中包含的字符是否可以构成"ab",

若当前栈中靠近栈顶的前两个字符可以构成"ab"则继续,

若当前栈为空或者当前栈中靠近栈顶的前两个字符构不成"ab",则直接返回false;

在遍历完字符串S后,再判断栈是否为空,若栈为空则返回true,若栈非空则返回false;**
### 代码

```java
class Solution {
    public boolean isValid(String S) {
    	Deque<Character> stack= new LinkedList<>();
    	for(int i=0;i<S.length();i++) {
    		if(stack.peek()==null||S.charAt(i)!='c') {
    			stack.push(S.charAt(i));
    		}else {
    			if(stack.peek()==null||stack.poll()!='b') {
    				return false;
    			}
    			if(stack.peek()==null||stack.poll()!='a') {
    				return false;
    			}
    		}
    	}
    	return stack.peek()==null;
    }
}
```