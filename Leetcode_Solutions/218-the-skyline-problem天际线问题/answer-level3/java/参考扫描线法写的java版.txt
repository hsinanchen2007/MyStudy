
执行用时 :50 ms, 在所有 Java 提交中击败了72.38%的用户
内存消耗 :48.9 MB, 在所有 Java 提交中击败了88.46%的用户

不会C++，看了个大概意思，不知道是不是这么个意思
时间复杂度O(NlogN),空间复杂度O(N)
```
class Solution {
	// 排序规则，按照x的坐标升序排列，若x坐标相同，右端点在前
	class IntCompator implements Comparator<int[]> {
		@Override
		public int compare(int[] o1, int[] o2) {
			// TODO Auto-generated method stub
			if (o1[0] == o2[0])
				return o2[1] - o1[1];
			return o1[0] - o2[0];
		}
	}

	public List<List<Integer>> getSkyline(int[][] buildings) {
		List<List<Integer>> list = new ArrayList<>();
		int newbuild[][] = new int[2 * buildings.length][2];

		// 将建筑物坐标化成[右端点，高度]，[左端点，-高度],用高度的正负来判断是左端点还是右端点。
		for (int i = 0; i < buildings.length; i++) {
			newbuild[2 * i][0] = buildings[i][0];
			newbuild[2 * i][1] = buildings[i][2];
			newbuild[2 * i + 1][0] = buildings[i][1];
			newbuild[2 * i + 1][1] = -buildings[i][2];
		}
		Arrays.sort(newbuild, new IntCompator());

		// list1维护堆内的有序
		List<Integer> list1 = new ArrayList<>();
		list1.add(0);
		int index;

		for (int i = 0; i < newbuild.length; i++) {
			if (newbuild[i][1] > 0) {// 左端点
				if (newbuild[i][1] > list1.get(list1.size() - 1)) {// 如果左端点的高度比堆的最大值还大，说明是一个转折点
					list.add(Arrays.asList(newbuild[i][0], newbuild[i][1]));
				}
				index = findIndex(list1, newbuild[i][1]);
				list1.add(index, newbuild[i][1]);// 将该点入堆
			} else {//右端点
				index = findIndex(list1, -newbuild[i][1]);
				list1.remove(index);//先将该点从堆中移除
				if (-newbuild[i][1] > list1.get(list1.size() - 1)) {//如果右端点的高度是堆内最大，说明是一个转折点
					list.add(Arrays.asList(newbuild[i][0], list1.get(list1.size() - 1)));
				}
			}
		}
		return list;
	}

	// 二分查找辅助函数
	public int findIndex(List<Integer> list, int n) {
		int low = 0, high = list.size(), middle;
		while (low < high) {
			middle = (low + high) >>> 1;
			if (list.get(middle) < n) {
				low = middle + 1;
			} else {
				high = middle;
			}
		}
		return low;
	}
}
```
