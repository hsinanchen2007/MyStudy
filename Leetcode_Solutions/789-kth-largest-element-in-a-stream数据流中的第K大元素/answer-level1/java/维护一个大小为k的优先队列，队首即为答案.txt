```
class KthLargest {
	PriorityQueue<Integer> queue;
	int size = 0;

	public KthLargest(int k, int[] nums) {
		queue = new PriorityQueue<>();
		size = k;
		for (int x : nums) {
			queue.offer(x);
			if (queue.size() > size)
				queue.poll();
		}
	}

	public int add(int val) {
		queue.offer(val);
		if (queue.size() > size)
			queue.poll();
		return queue.peek();
	}
}
```
