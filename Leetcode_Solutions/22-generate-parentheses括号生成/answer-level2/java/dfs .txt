### 解题思路
这一句很重要：sb.deleteCharAt(sb.length() - 1);

### 代码

```java
class Solution {
    List<String> result = new ArrayList<>();		
	StringBuilder sb = new StringBuilder();
	String str = "";
    
    public List<String> generateParenthesis(int n) {
        if(n <= 0)
			return result;
		
		dfs(0, 0, n, sb);
		return result;
    }

    private void dfs(int left, int right, int n, StringBuilder sb) {
		if(left==n && right==n) {
			result.add(sb.toString());
			return;
		}
		if(left < n) { //可以在加左括号
			dfs(left + 1, right, n, sb.append("(") );
			sb.deleteCharAt(sb.length() - 1);
		}
		if(right < n && left > right) { //剪枝
			dfs(left, right + 1, n, sb.append(")") );
			sb.deleteCharAt(sb.length() - 1);
		}
	}
}
```
![image.png](https://pic.leetcode-cn.com/c35fb6f8967a883a37cc3bb233ab15fd482e3ac0de93207a6147933297dfbd1a-image.png)
