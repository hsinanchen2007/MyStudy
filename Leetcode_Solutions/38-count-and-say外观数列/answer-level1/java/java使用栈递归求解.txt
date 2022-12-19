    刚拿到题目没有思路看了题解，发现第一页没有java解法，就尝试用java做了一下，主要思路为：

    1.定义一个helper函数，其功能为给定一个序列，求解下一个序列，返回字符串，其中用到了栈

    2.定义递归函数，n=1时直接返回1，否则进行递归

```
import java.util.Stack;
class Solution {
	public static String countAndSay(int n) {
		if(n==1) return "1";
		if(n==2) return thenext("1");
		return thenext(countAndSay(n-1));
	}
	 
    public static String thenext(String s) {
    	StringBuilder sb=new StringBuilder();
    	char a[]=s.toCharArray();
    	Stack<Character> stack=new Stack<Character>();
    	for(int i=0;i<a.length;i++) {
    		if(stack.isEmpty()||stack.peek()==a[i]){
    			stack.push(a[i]);
    		}else {
				sb.append(stack.size());
				sb.append(stack.pop());
				stack.clear();
				stack.push(a[i]);
    		}
    	}
    	sb.append(stack.size());
		sb.append(stack.pop());
		return sb.toString();
    }
    public static void main(String args[]) {
    	System.out.print(countAndSay(10));
    }
}
```


