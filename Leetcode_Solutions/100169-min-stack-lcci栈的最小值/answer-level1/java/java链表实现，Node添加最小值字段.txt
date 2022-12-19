使用链表实现，节点Node添加一个min字段，保存在当前节点看来的栈中最小值
注：思路来自国外leetcode大佬，很巧妙，在此分享
```
class MinStack {
	class Node {
		int val;
		int min;
		Node next;

		public Node(int val, int min) {
			this.val = val;
			this.min = min;
		}

		public Node(int val, int min, Node next) {
			this.val = val;
			this.min = min;
			this.next = next;
		}
	}

	private Node head = null;

	/** initialize your data structure here. */
	public MinStack() {

	}

	public void push(int x) {
		if (head == null) head = new Node(x, x);
/*新加入节点的min字段（最小值）为：自己的值和栈顶的值较小的那个*/
		else if (head != null) {
			int min = Math.min(x, head.min);
			Node node = new Node(x, min, head);
			head = node;
		}
	}

	public void pop() {
		if (head == null) return;
		head = head.next;
	}

	public int top() {
		return head.val;
	}

	public int getMin() {
		return head.min;
	}
}
```
