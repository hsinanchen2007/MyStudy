public class Solution {
	public int[][] merge(int[][] intervals) {
		// 将数组按照起始点排序
		Arrays.sort(intervals, new Comparator<int[]>() {
			@Override
			public int compare(int[] arg0, int[] arg1) {
				return arg0[0] - arg1[0];
			}
		});
		// for (int[] start:intervals) {
		// System.out.println(Arrays.toString(start));
		// }
		List<List<Integer>> arrlist = new ArrayList<>();
		for (int i = 0; i < intervals.length; i++) {
			List<Integer> item = new ArrayList<>();
			item.add(intervals[i][0]);
			item.add(intervals[i][1]);
			arrlist.add(item);
		}
		int[][] ret = mergelist(arrlist);
		return ret;
	}

	private int[][] mergelist(List<List<Integer>> arrlist) {
		for (int i = 0; i < arrlist.size() - 1; i++) {
			List<Integer> item0 = arrlist.get(i);
			List<Integer> item1 = arrlist.get(i + 1);
			int item0Start = item0.get(0);
			int item0End = item0.get(1);
			int item1Start = item1.get(0);
			int item1End = item1.get(1);
			// 第i行的终点大于 第 i + 1 行的起点
			if (item0End >= item1Start) {
				int start = item0Start;
				int end = item0End > item1End ? item0End : item1End;
				List<Integer> item = new ArrayList<>();
				item.add(start);
				item.add(end);
				arrlist.add(i, item);
				arrlist.remove(i + 1);
				arrlist.remove(i + 1);
				i = -1;
			}
		}
		int[][] newarr = new int[arrlist.size()][2];
		for (int i = 0; i < arrlist.size(); i++) {
			newarr[i][0] = arrlist.get(i).get(0);
			newarr[i][1] = arrlist.get(i).get(1);
		}
		return newarr;
	}
}