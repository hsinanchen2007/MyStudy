### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
		List<List<String>> ans = new ArrayList<List<String>>();
		backtrack(n, 0, new int[n], ans);
		return ans;
	}

	public void backtrack(int n, int index, int[] locations, List<List<String>> ans) {
		if (index == n) {
			ans.add(solution(locations));
			return;
		}

		for (int i = 1; i <= n; i++) {
			if (isNotUnderAttack(locations, index, i)) {
				locations[index] = i;
				backtrack(n, index + 1, locations, ans);
				// locations[index] = 0;
			}
		}
	}

	private boolean isNotUnderAttack(int[] locations, int index, int location) {
		if (index == 0) {
			return true;
		}

		for (int i = 0; i < index; i++) {
			if (locations[i] == location) {
				return false;
			}

			if (Math.abs(location - locations[i]) == Math.abs(index - i)) {
				return false;
			}
		}

		return true;
	}

	private List<String> solution(int[] locations) {
		int n = locations.length;
		List<String> list = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			StringBuilder stringBuilder = new StringBuilder();
			for (int j = 1; j <= n; j++) {
				if (locations[i] == j) {
					stringBuilder.append("Q");
				} else {
					stringBuilder.append(".");
				}
			}
			list.add(stringBuilder.toString());
		}
		return list;
	}
}
```