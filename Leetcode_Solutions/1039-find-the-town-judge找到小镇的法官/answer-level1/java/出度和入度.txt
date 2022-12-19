法官是这样一个点：出度为0，并且入度为N-1
```
public int findJudge(int N, int[][] trust) {
		int inDegree[] = new int[N + 1];
		int outDegree[] = new int[N + 1];
		for (int[] path : trust) {
			int start = path[0];
			int end = path[1];
			inDegree[end]++;
			outDegree[start]++;
		}
		for (int i = 1; i <= N; i++) {
			if (outDegree[i] == 0 && inDegree[i] == N - 1) {
				return i;
			}
		}
		return -1;
	}
```

