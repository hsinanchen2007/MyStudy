### 解题思路
我分不清这算不算dfs,但姑且算吧，就一个个字符往下加，
注意递归结束条件，左括号数目与右括号数目都等于n的时候，就完成了一个结果
递归过程：不变量 n >= 左括号数目 >= 右括号数目
且当左括号数目等于右括号数目时，不能再添加右括号，根据这两个条件进行剪枝

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
      List<String> ans = new ArrayList<String>();
		StringBuilder sb = new StringBuilder();
		dfs(0, 0, n, sb, ans);
		return ans;
		
		
	}
	
	public void dfs(int left,int right,int n,StringBuilder sb,List<String> ans) {
		if(left < right) {
			return;
		}
		if(left == n && right == n) {
			ans.add(sb.toString());
			return;
		}
		if(left == right) {
			sb.append('(');
			dfs(left + 1, right, n, sb, ans);
			sb.deleteCharAt(sb.length()-1);
		}else {
			if(left < n) {
				sb.append('(');
				dfs(left + 1, right, n, sb, ans);
				sb.deleteCharAt(sb.length()-1);
			}
			sb.append(')');
			dfs(left, right + 1, n, sb, ans);
			sb.deleteCharAt(sb.length()-1);
		}
	}
}
```