### 解题思路
 利用栈得思路，左括号压进栈里面，右括号则匹配栈最上面的字符，相匹配则出栈，不匹配则直接返回错误。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
if(s.isEmpty()) return true;
		if(s.charAt(0)=='}'||s.charAt(0)==')'||s.charAt(0)==']') return false;
		int [] LEFT=new int[s.length()];
		
		int top=0;
		for(int i=0;i<s.length();i++)
		{
			if(top <0) return false;
			if(s.charAt(i)=='('||s.charAt(i)=='{'||s.charAt(i)=='[') {
				LEFT[top++]=s.charAt(i);
			}
			else if (top==0||(Math.abs(s.charAt(i)-LEFT[top-1])>5)){
			return false;
			}
			else 
			{
				top-=1;
			}
		}
		if(left!=0) return false;
		
		return true;
    }
}
```