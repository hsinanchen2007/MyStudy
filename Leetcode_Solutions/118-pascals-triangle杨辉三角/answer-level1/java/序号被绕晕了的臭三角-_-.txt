```
public static List<List<Integer>> generate(int numRows) {
		List<List<Integer>> list = new ArrayList<List<Integer>>();
		// 建立数组
		for (int i = 0; i < numRows; i++) {
			list.add(new ArrayList<Integer>());
		}
		if (numRows == 0) {
			return list;
		}

		if (numRows == 1) {
			list.get(0).add(0);
			return list;
		}
		if (numRows == 2) {
			list.get(0).add(1);
			list.get(1).add(1);
			list.get(1).add(1);
			return list;
		}
		list.get(0).add(1);// first row
		list.get(1).add(1);// second row
		list.get(1).add(1);// second row
		for (int j = 2; j < numRows; j++) {
			list.get(j).add(1);
			for (int k = 0; k < j - 1; k++) {
				list.get(j).add(list.get(j - 1).get(k) + list.get(j - 1).get(k + 1));
			}
			list.get(j).add(1);
		}
		return list;

	}
```
