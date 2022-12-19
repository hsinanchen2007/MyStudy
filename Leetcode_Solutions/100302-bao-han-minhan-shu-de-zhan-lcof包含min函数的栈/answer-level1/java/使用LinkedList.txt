### 解题思路
在添加或者删除时将最小值找出来

### 代码

```java
class MinStack {
    LinkedList<Integer> linkedList = null;
	int tem = Integer.MAX_VALUE;

	/** initialize your data structure here. */
	public MinStack() {
		linkedList = new LinkedList<>();
	}

	public void push(int x) {
		linkedList.add(x);
		if (x < tem)//找出最小值
			tem = x;
	}

	public void pop() {
		int tem2 = 0, i = 0;
		if (!linkedList.isEmpty())
			tem2 = linkedList.removeLast();
		if (tem2 != tem)//如果删除的不是最小值，那么现在的最小值还是之前的最小值
			return;
		tem = Integer.MAX_VALUE;//否则重新找最小值
		while (i < linkedList.size()) {
			int tem3 = linkedList.get(i++);
			if (tem > tem3)
				tem = tem3;
		}
	}

	public int top() {
		if (!linkedList.isEmpty())
			return linkedList.getLast();
		return 0;
	}

	public int min() {
		return tem;
	}
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```