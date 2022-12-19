### 解题思路
发个题解纪念一下快把自己写死了的代码。

### 代码

```java

import java.util.LinkedList;

class Solution {
	public int[][] insert(int[][] intervals, int[] newInterval) {
		if(newInterval.length == 0) return intervals;
		if(intervals.length == 0) {
			int[][] ans = new int[1][2];
			ans[0][0] = newInterval[0];
			ans[0][1] = newInterval[1];
			return ans;
		}
		int left = findLeftIndex(intervals, newInterval[0]);
		int right = findRightIndex(intervals, newInterval[1]);
		if(left > right) return intervals;
		LinkedList<int[]> LL = new LinkedList<int[]>();
		if(left == -1 && right == intervals.length) {
			LL.add(newInterval);
		}else if(left == -1) {//讨论newInterval[1]的值在intervals[right][0]的左侧还是右侧
			if(newInterval[1] >= intervals[right][0]) {
				newInterval[1] = intervals[right][1];
				LL.add(newInterval);
				for(int i = right + 1;i < intervals.length;i++) {
					LL.add(intervals[i]);
				}
			}else {
				LL.add(newInterval);
				for(int i = right;i < intervals.length;i++) {
					LL.add(intervals[i]);
				}
			}
		}else if(right == intervals.length) {//讨论newInterval[0]的值在intervals[left][1]的左侧还是右侧
			if(newInterval[0] <= intervals[left][1]) {
				newInterval[0] = intervals[left][0];
				for(int i = 0;i < left;i++) {
					LL.add(intervals[i]);
				}
				LL.add(newInterval);
			}else {
				for(int i = 0;i <= left;i++) {
					LL.add(intervals[i]);
				}
				LL.add(newInterval);
			}
		}else {//讨论四种情况
			if(newInterval[0] <= intervals[left][1] && newInterval[1] >= intervals[right][0]) {
				newInterval[0] = intervals[left][0];
				for(int i = 0;i < left;i++) {
					LL.add(intervals[i]);
				}
				newInterval[1] = intervals[right][1];
				LL.add(newInterval);
				for(int i = right + 1;i < intervals.length;i++) {
					LL.add(intervals[i]);
				}
			}else if(newInterval[0] > intervals[left][1] && newInterval[1] >= intervals[right][0]) {
				for(int i = 0;i <= left;i++) {
					LL.add(intervals[i]);
				}
				newInterval[1] = intervals[right][1];
				LL.add(newInterval);
				for(int i = right + 1;i < intervals.length;i++) {
					LL.add(intervals[i]);
				}
			}else if(newInterval[0] <= intervals[left][1] && newInterval[1] < intervals[right][0]) {
				newInterval[0] = intervals[left][0];
				for(int i = 0;i < left;i++) {
					LL.add(intervals[i]);
				}
				LL.add(newInterval);
				for(int i = right;i < intervals.length;i++) {
					LL.add(intervals[i]);
				}
			}else {
				for(int i = 0;i <= left;i++) {
					LL.add(intervals[i]);
				}
				LL.add(newInterval);
				for(int i = right;i < intervals.length;i++) {
					LL.add(intervals[i]);
				}
			}
		}
		
		return LL.toArray(new int[LL.size()][2]);
	}
	
	private int findLeftIndex(int[][] intervals, int par) {
		int low = 0;
		int high = intervals.length - 1;
		while(low < high) {
			int middle = (low + high) >> 1;
			if(intervals[middle][0] == par) return middle;
			if(intervals[middle][0] < par) {
				low = middle + 1;
				continue;
			}
			if(intervals[middle][0] > par) {
				high = middle - 1;
				continue;
			}
		}
		if(par >= intervals[low][0]) return low;
		else return low - 1;
	}
	private int findRightIndex(int[][] intervals, int par) {
		int low = 0;
		int high = intervals.length - 1;
		while(low < high) {
			int middle = (low + high) >> 1;
		if(intervals[middle][1] == par) return middle;
		if(intervals[middle][1] < par) {
			low = middle + 1;
			continue;
		}
		if(intervals[middle][1] > par) {
			high = middle - 1;
			continue;
		}
		}
		if(par <= intervals[low][1]) return low;
		else return low + 1;
	}
	
}

```