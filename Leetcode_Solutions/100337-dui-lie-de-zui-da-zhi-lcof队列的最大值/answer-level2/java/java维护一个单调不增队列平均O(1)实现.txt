### 解题思路
- 时间复杂度：出队操作为O(1)，取最大值为O(1)，入队操作平均为O(1)
- 空间复杂度：O(n)
- 思路：维护一个单调不增队列。
- bb几句，这题一开始想到直接维护一个单调递增队列，但是发现，若队首出队时把最大元素移走了，那队尾最大值就不成立了！于是就尝试往单调递减队列实现，只要出队时有和最大值相同就同步出队，否则普通队列出队即可！注意：若维护最大值的队列队尾元素与当前要插入队列的元素值相同，则不能将队尾弹出队列，否则就没办法判断出队时是否等值时必须出队！综上，必须维护一个单调不增队列！

### 代码

```java
class MaxQueue {
	Queue<Integer> qScan;
	Deque<Integer> qMax;

	public MaxQueue() {
		qScan = new ArrayDeque<Integer>();
		qMax = new ArrayDeque<Integer>();
	}

	public int max_value() {
		return qMax.isEmpty() ? -1 : qMax.element(); // element()元素是返回队首元素
	}

	public void push_back(int value) {
		qScan.add(value);
		while (!qMax.isEmpty() && qMax.getLast() < value) // 维护一个单调不增的双端队列
			qMax.removeLast();
		qMax.addLast(value);
	}

	public int pop_front() {
		if (qScan.isEmpty())
			return -1;
		int val = qScan.remove();
		if (!qMax.isEmpty() && qMax.element() == val)
			qMax.removeFirst();
		return val;
	}
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```