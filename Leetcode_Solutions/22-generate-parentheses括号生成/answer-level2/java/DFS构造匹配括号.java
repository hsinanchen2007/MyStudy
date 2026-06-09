执行用时 :1 ms, 在所有 Java 提交中击败了98.38%的用户
内存消耗 :39.7 MB, 在所有 Java 提交中击败了5.01%的用户
### 解题思路
需要想通两点，1、我们总是先放左括号。2、右括号数量不能少于左括号数量，否则肯定有个右括号没法找到与它匹配的左括号。
递归试探所有可能即可
### 代码

```java
class Solution {
    static LinkedList<String> ans = null ;
	
	public List<String> generateParenthesis(int n) {
		ans = new LinkedList<>() ;
		dfs(n,n,"") ;
		return ans ;
    }
	
	public void dfs(int l,int r,String str) {
		if(l==0&&r==0)
		{
			ans.addLast(str) ;
			return ;
		}
		if(l>r)
			return ;
		if(l>0)
			dfs(l-1,r,str+"(") ;
		if(r>0)
			dfs(l,r-1,str+")") ;
	}
}
```