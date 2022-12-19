- 每次添加元素时，先看一下链表中有没有可以合并的区间，如果有就合并，没有就新增一个区间。
- 因为要在链表中合并、新增区间，选择链表来存储各区间。
- 因为数据流中存在重复元素，为了避免重复在链表中的查找，设置一个集合记录已经出现过的数字。
```
class SummaryRanges {
	private Set<Integer> dataStream;
	private LinkedList<int[]> intervals;

	public SummaryRanges() {
		dataStream = new HashSet<>();
		intervals = new LinkedList<>();
		return;
	}

	public void addNum(int val) {
		if (!dataStream.contains(val)) {
			setIntervals(intervals, val);
			dataStream.add(val);
		}
		return;
	}

	private void setIntervals(LinkedList<int[]> intervals, int val) {
		int pos = findPos(intervals, val);
		if (dataStream.contains(val - 1) && dataStream.contains(val + 1)) { // 合并两个区间
			intervals.get(pos - 1)[1] = intervals.get(pos)[1];
			intervals.remove(pos);
		} else if (dataStream.contains(val - 1)) { 		// 扩展左区间
			intervals.get(pos - 1)[1]++;
		} else if (dataStream.contains(val + 1)) { 		// 扩展右区间
			intervals.get(pos)[0]--;
		} else { 										// 新增区间
			intervals.add(pos, new int[] { val, val });
		}
	}

	private int findPos(LinkedList<int[]> intervals, int val) {
		int index = 0;
		while (index < intervals.size() && val > intervals.get(index)[0]) {
			index++;
		}
		return index;
	}

	public int[][] getIntervals() {
		return intervals.toArray(new int[0][0]);
	}
}
```
