```
public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
		List<Integer> numOfLeaf = new ArrayList<Integer>();
		for (int i = 0; i < informTime.length; i++) {
			if (informTime[i] == 0) {
				numOfLeaf.add(i);
			}
		}
		int result = 0;
		for (int leaf : numOfLeaf) {
			leaf = manager[leaf];
			int time = 0;
			while (leaf != -1) {
				time += informTime[leaf];
				leaf = manager[leaf];
			}
			result = Math.max(result, time);
		}
		return result;
    }
```
