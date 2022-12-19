使用链表实现栈，在pop的时候，再去寻找最小值

```
public class MinStack {

	private Node top = null;
	private int min = Integer.MAX_VALUE;

	/** initialize your data structure here. */
	public MinStack() {

	}

	public void push(int x) {
		if (top == null) {
			top = new Node(x, null);
			min = x;
		} else {
			top = new Node(x, top);
			if (x < min) {
				min = x;
			}
		}
	}

	public void pop() {
		if (top != null) {
			if (top.prev != null) {
                int val = top.val;
				top = top.prev;
				
				if (val == min) {
					min = top.val;
					Node p = top;
					while (true) {
						if (p.val < min) {
							min = p.val;
						}
						if ((p = p.prev) == null) {
							return;
						}
					}
				}
			} else {
				top = null;
				min = Integer.MAX_VALUE;
			}
		}
	}

	public int top() {
		return top != null ? top.val : Integer.MIN_VALUE;
	}

	public int getMin() {
		return min;
	}
}

class Node {
	int val;
	Node prev;

	public Node(int val, Node prev) {
		this.val = val;
		this.prev = prev;
	}
}
```
