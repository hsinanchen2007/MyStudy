### 解题思路
栈的缺点是只能删除栈顶元素
而要实现删除队首元素，需要一个辅助栈

### 代码

```java
class CQueue {
	LinkedList<Integer> A, B;
    public CQueue() {		
        A = new LinkedList<Integer>();
		B = new LinkedList<Integer>();

    }
    
    public void appendTail(int value) {
	A.offer(value);
    }//直接加入栈A即可
    
    public int deleteHead() {
		if(!B.isEmpty()) return B.poll();  //B不为空 弹出B栈顶元素
		if(A.isEmpty()) return -1;      
		while(!A.isEmpty()) {   // A不为空，将A传入B 再弹出B栈顶元素
			B.offer(A.poll());
		}
		return B.poll();
	}
    
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```python
class CQueue(object):

    def __init__(self):
        self.stack1 = []
        self.stack2 = []


    def appendTail(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.stack1.append(value)
        
    def deleteHead(self):
        """
        :rtype: int
        """
        if self.stack2:
            return self.stack2.pop()
        if not self.stack1:
            return -1
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        return self.stack2.pop()
