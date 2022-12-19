### 解题思路
再为会议分配会议室时，遍历所会议室，并且逐个判断当前会议室已分配的会议与待分配的会议时间是否冲突，
若冲突遍历下一个会议室，若所有的会议室内已分配的会议都与当前待分配的会议冲突，那么重新创建一个会议室
将该会议放入新创建的会议室中！

### 代码

```java
class Solution {
    public int minMeetingRooms(int[][] intervals) {
		if (intervals == null || intervals.length == 0) {
			return 0;
		}
		Arrays.sort(intervals, Comparator.comparingInt(item -> item[0]));
		List<List<int[]>> rooms = new ArrayList<>();
		rooms.add(new ArrayList<>(Arrays.asList(intervals[0])));
		for (int i = 1; i < intervals.length; i++) {
			int[] baseMeet = intervals[i];
			boolean success = false;
			for (List<int[]> roomItem : rooms) {
				boolean notConflict = true;
				for (int[] meetItem : roomItem) {
					if (baseMeet[0] < meetItem[1]) {
						notConflict = false;
						break;
					}
				}
				if (notConflict) {
					roomItem.add(baseMeet);
					success = true;
					break;
				}
			}
			if (!success) {
				rooms.add(new ArrayList<>(Arrays.asList(baseMeet)));
			}
		}
		return rooms.size();
	}
}
```