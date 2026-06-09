```
	public static int[][] merge(int[][] intervals) {
		if (intervals.length == 0)
			return intervals;

		/**
		 * 定义一个链表,类似一条线段,我们将一个个数组放进去。每2个点为一组
		 */
		LinkedList<Integer> list = new LinkedList<>();
		list.add(intervals[0][0]);
		list.add(intervals[0][1]);
		for (int i = 1; i < intervals.length; i++) {
			int left = intervals[i][0];
			int right = intervals[i][1];
			int cursor = 0;
			boolean isUse = true;
			while (cursor < list.size()) {
				isUse = true;
				int start = list.get(cursor);
				int end = list.get(cursor + 1);
				if (start > right) {
					list.add(cursor, left);
					list.add(cursor + 1, right);
					break;
				}
				if (end < left) {
					cursor = cursor + 2;
					isUse = false;
					continue;
				}
				int min = Math.min(start, left);
				int max = Math.max(end, right);
				list.set(cursor, min);
				list.set(cursor + 1, max);
				/**
				 * 还要向右边扩散，前面的，绝对可以了
				 */
				int newCursor = cursor + 2;
				while (newCursor < list.size()) {
					int newStart = list.get(newCursor);
					int newEnd = list.get(newCursor + 1);
					if (newStart > max) {
						break;
					}
					if (newEnd >= max) {
						list.remove(newCursor);
						list.remove(newCursor - 1);
						break;
					}
					list.remove(newCursor);
					list.remove(newCursor);
					
				}

				break;
			}
			if (!isUse) {
				list.add(left);
				list.add(right);
			}

		}
		int cursor = 0;
		int arrayCursor = 0;
		int[][] newIntervals = new int[list.size() / 2][2];
		while (cursor < list.size()) {
			newIntervals[arrayCursor][0] = list.get(cursor);
			newIntervals[arrayCursor][1] = list.get(cursor + 1);
			cursor = cursor + 2;
			arrayCursor++;
		}
		return newIntervals;

	}
```
