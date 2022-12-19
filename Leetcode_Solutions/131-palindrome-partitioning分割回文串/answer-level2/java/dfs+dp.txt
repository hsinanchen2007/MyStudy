### 解题思路
仔细看看代码,都可以看懂的

### 代码

```java
class Solution {
   public List<List<String>> partition(String s) {
List<List<String>> ans = new LinkedList<>();
        if(s.equals("")){
            LinkedList<String> list=new LinkedList<>();
            
            ans.add(list);
            return ans;

        }
		boolean[][] dp = new boolean[s.length()][s.length()];

		
dp[0][0] = true;
		for (int j = 1; j < s.length(); j++) {
			dp[j][j] = true;
			dp[j][j-1]=true;

			for (int i =j - 1; i >= 0; i--) {

				if (s.charAt(i) == s.charAt(j)) {
					dp[i][j] = dp[i + 1][j - 1];
				} else {
					dp[i][j] = false;
				}

			}
		}
		
		dfs(dp, ans, new LinkedList<>(), 0, s.length() - 1, s);
		return ans;
	}

	void dfs(boolean[][] dp, List<List<String>> ans, List<String> list, int start, int end, String s) {

		if (start > end) {
			ans.add(new LinkedList<>(list));
			return;
		}
		for (int i = start ; i <= end; i++) {
			if (dp[start][i]) {
				list.add(s.substring(start, i + 1));
				dfs(dp, ans, list, i + 1, end, s);

				list.remove(list.size() - 1);
			}
		}

	}

}
```