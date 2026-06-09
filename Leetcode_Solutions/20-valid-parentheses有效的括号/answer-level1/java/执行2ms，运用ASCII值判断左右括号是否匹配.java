先上代码
```
class Solution {
	public boolean isValid(String s) {
		Stack<Character> stack = new Stack<>();
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='}'||s.charAt(i)==']'||s.charAt(i)==')') {
				if((!stack.isEmpty())&&(stack.peek()==s.charAt(i)-2||stack.peek()==s.charAt(i)-1)
					stack.pop();
				else return false;
			}
			else stack.push(s.charAt(i));
		}
		if(stack.isEmpty()) return true;
		else return false;
	}
}
```
因为整个字符串只有两种情况，**左括号或者右括号**。
题目并没有要求括号的优先级，即情况**({})**是合法的。
那么当我们扫描字符串遇到左括号时，因为栈中并没有储存右括号(原因下面会讲)，而左括号'(' '[' '{'之间是没有优先级的，我们只需要无脑push压入栈;
而当我们扫描到右括号时，要想使得字符串合法，该右括号只能与栈顶的同类左括号抵消(**左括号比右括号的ASCII值小1或者2**)，若
    1:栈为空
    2:不能抵消，出现类似"(}"
则字符串不合法，返回false。抵消成功则pop栈顶元素。
扫描完成整个字符串后，若栈空，说明所有的左右括号合法配对，返回true;若栈中还有元素则返回false

**时间复杂度：O(n)**。我们只是从头到尾扫描了一次字符准串。并且当**字符串长度不为奇数**或者**栈内元素超出字符串长度的一半**时可以直接结束扫描return false退出循环
**空间复杂度：O(n)**。最差的情况下整个字符串全为左括号。但是若加上**栈内元素超出字符串长度的一半**判断条件时可以运用更少的空间
