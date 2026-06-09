![image.png](https://pic.leetcode-cn.com/b34356ecfced9d0e0df104e998079b6a19a08965b9b4cf0353c7b1ed846949b0-image.png)

### 解题思路
回溯算法，主要按照这几个步骤进行分析：
1. 递归结束的条件：左右括号数都为n
2. 每次递归条件：
	当左括号数<n，添加左括号
	当右括号数少于左括号数，意味着需要闭合，添加右括号
3. 每次递归之后需要回溯到上一状态：即删除stringbuilder最后一个元素

### 代码

```java
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
    	if(n == 0) {
	      res.add("");
	      return res;
    	}
    	StringBuilder sb = new StringBuilder();
    	dfs(sb, 0, 0, n);
    	return res;
    }

    private void dfs(StringBuilder sb, int left, int right, int n) {
    	if(left == n && right == n) {
    		res.add(new String(sb));
    		return;
    	}
    	
    	if(left < n) {
    		dfs(sb.append('('), left + 1, right, n);
    		//回溯上一步
    		sb.deleteCharAt(sb.length() - 1);
    	}
    	
    	
    	
    	if(left > right) {
    		dfs(sb.append(')'), left, right + 1, n);
    		//回溯上一步
    		sb.deleteCharAt(sb.length() - 1);
    	}
    }
}
```