### 解题思路
此题解法的思路很重要
实现一个队列，就得对头出，队尾进
所以可以推出只要队尾前的变元素比队尾的小，最大的值就一定是队尾的那一个，所以可以考虑用另一个双端队列record记录队列的最大队尾元素，该队列要保持单调递减，求最大值时只需要出队record对头元素
出队时，如果队头的元素跟record队头元素相等（即要出队的元素是最大值），
要将record队头也出队

### 代码

```java
class MaxQueue {
        Deque<Integer> de;
		Deque<Integer> record;
	    public MaxQueue() {
	    	de=new LinkedList<>();//构造函数，定义
	    	record=new LinkedList<>();//辅助队列降序排列数据
	    }
	    
	    public int max_value() {
	    	return de.isEmpty()?-1:record.peek();
	    }
	    
	    public void push_back(int value) {
	    	de.offer(value);
	    	while(!record.isEmpty()&&record.peekLast()<value) {
	    		record.pollLast();
	    	}
	    	record.offer(value);
	    }
	    
	    public int pop_front() {
	    	if(de.isEmpty())
	    		return -1;
	    	else {
                int val=de.pop();
	    		if(val==record.peekFirst())
		    		record.pop();//如果记录的队列头结点等于要取出的结点，就移除
		    	return val;
	    	}
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