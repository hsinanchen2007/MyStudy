### 解题思路


### 代码

```java
class Solution {
  public int movingCount(int m, int n, int k) {
		int[] ans = { 0, 0 };
		HashSet<String> hs = new HashSet();
		Queue<int[]> q = new LinkedList<>();
		q.offer(ans);
		//转换为String存入HashSet可以避免重写hashCode
		//中间穿插“0”可以区分(1,11)(11,1)
		hs.add(ans[0]+"0"+ans[1]);
		while (!q.isEmpty()) {
			int[] temp = q.poll();
			// System.out.println(Arrays.toString(temp));
			// up
			if (insum(temp[0]) + insum(temp[1] + 1) <= k && temp[1] + 1 < n) {
				moving(q, hs, new int[] { temp[0], temp[1] + 1 });
			}
			// right
			if (insum(temp[0] + 1) + insum(temp[1]) <= k && temp[0] + 1 < m) {
				moving(q, hs, new int[] { temp[0] + 1, temp[1] });
			}
		}
		return hs.size();

	}
	public void moving(Queue<int[]> q, HashSet<String> hs, int[] ans) {
		if (hs.contains(ans[0]+"0"+ans[1])) {
			return;
		}
		q.offer(ans);
		hs.add(ans[0]+"0"+ans[1]);
	}

	public int insum(int a) {
		int sum = 0;
		while (a > 0) {
			sum += a % 10;
			a /= 10;
		}
		return sum;
	}

}
```