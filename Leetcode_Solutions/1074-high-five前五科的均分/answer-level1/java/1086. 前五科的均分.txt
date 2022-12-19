### 解题思路
6ms, >83.55%
41.2MB, >100%
求前几，可以用优先队列
PriorityQueue 默认小根堆(求最大)，内部元素自然排序，peek查看最小值，可以控制最小值的替换得到前k大的数
如果要求最小的几个就得反一下了：
大根堆，求最小几个：PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

### 代码

```java
public int[][] highFive(int[][] items) {
	Map<Integer, List<Integer>> gradeMap = new HashMap<>();
	for (int[] item : items) {
		List<Integer> list = gradeMap.containsKey(item[0]) ? gradeMap.get(item[0]) : new ArrayList<>();
		list.add(item[1]);
		gradeMap.put(item[0], list);
	}

	int[][] res = new int[gradeMap.size()][2];
	for (int id : gradeMap.keySet()) {
		res[id - 1][0] = id;
		res[id - 1][1] = this.getTop5Avg(gradeMap.get(id));
	}
	return res;
}

/**
 * 找到前五成绩的平均值
 */
public int getTop5Avg(List<Integer> grades) {
	PriorityQueue<Integer> maxHeap = new PriorityQueue<>();
	for (int grade : grades) {
		if (maxHeap.size() < 5) {
			maxHeap.offer(grade);
		} else if (maxHeap.peek() < grade) {
			maxHeap.remove();
			maxHeap.offer(grade);
		}
	}
	int sum = 0;
	while (maxHeap.size() > 0) {
		sum += maxHeap.remove();
	}
	return sum / 5;
}
```