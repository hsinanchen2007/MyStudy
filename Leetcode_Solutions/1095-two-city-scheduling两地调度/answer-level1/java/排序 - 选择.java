```

public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, (a, b) -> {
			int a1 = a[0] - b[0];
			int b1 = a[1] - b[1];
			if (a[0] == b[0]) {
				return b[1] - b[0];
			}
			return a1 - b1;
		});
		int sum = 0;
		for (int i = 0; i < costs.length; i++) {
			if (i < costs.length / 2) {
				sum += costs[i][0];
			}
			for (int j = 0; j < costs[i].length; j++) {
				if (i >= costs.length / 2 && j > 0) {
					sum += costs[i][j];
				}
			}

		}
		return sum;
    }

```