### 解题思路
首先，题目要求实现队列的y入队和出队操作，很自然想到用队列，而且这些操作都是O(1)的复杂度，但是重点在于求最大值的操作，这个的复杂度要是o(1)，首先想到是用一个变量记录最大值，没当一个元素入队，记录队列中的最值，但是这样无法实现当最大值弹出厚，剩余队列的最大值。
我无奈的选择了优先级队列来辅助查找最大值，但是这个看起来操作是O(1)但是，内部的调整是O(Log n)的。可能是这道题本身有些问题，O(1)的算法很难实现我感觉。就是对于这个求最大值的函数实现部分。
### 代码

```java
class MaxQueue {
	private Queue<Integer> queue;
	private PriorityQueue<Integer> Pqueque;
    public MaxQueue() {
    	this.queue = new LinkedList<Integer>();
    	this.Pqueque = new PriorityQueue<Integer>(new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return o2-o1;
			}
		});
    }
    
    public int max_value() {
    	return queue.isEmpty()? -1: Pqueque.peek();
    }
    
    public void push_back(int value) {
    	queue.add(value);
    	Pqueque.add(value);
    }
    
    public int pop_front() {
    	if(!queue.isEmpty()) {
    		int re = queue.poll();
    		Pqueque.remove(re);
    		return re;
    	}
    	else
    		return -1;
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