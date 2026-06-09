1、栈的概念

很好的理解栈的概念的基础题。这里通过LinkedList实现同样的push,pop,top,geimin的栈操作。

首先理解栈是一个数据结构，只能支持插入、取出两种数据修改。插入只能插到栈顶，取出也只能取出栈顶。也就是一个Last-in,First-out的数据结构，后进要先出，最后进入的就是栈顶元素。



2、题解

对这题的操作使用栈是最直接的，除了getmin以外其实没有任何新增代码量。

实现栈的方式多种，有简单数组、动态数组，以及链表。用LinkList实现本题，和直接用栈的复杂度是一样的。



代码：

上手第一次写，用循环的方式去实现getmin, 通过17/18个测试用例，用LinkedList对搜索最小元素进行遍历时长超出限制。

```java
private LinkedList<Integer> minStack;
	
	/** initialize your data structure here. */
    public MinStack() {
    	minStack = new LinkedList<>();
    }
    
    public void push(int x) {
    	minStack.addFirst(x);
    }
    
    public void pop() {
    	if (!minStack.isEmpty()){
    		minStack.removeFirst();
    	}
    }
    
    public int top() {
    	if (!minStack.isEmpty()){
    		return minStack.getFirst();
    	}
    	return -1;
    }
    
    public int getMin() {
    	if (!minStack.isEmpty()){
	    	int size=minStack.size(), min=minStack.get(0);
	    	for(int i=1;i<size;i++){
	    		min=Math.min(min, minStack.get(i));
	    	}
	    	return min;
    	}
    	return -1;
    }
```



代码：第二次使用辅助列表，对最小元素单独记录。在push和pop时判断后与主列表同步出入栈。

```java
public class MinStack {

	private LinkedList<Integer> minStack;
	private LinkedList<Integer> helpmin;
	
	/** initialize your data structure here. */
    public MinStack() {
    	minStack = new LinkedList<>();
        helpmin = new LinkedList<>();
    }
    
    // 思路 ：辅助栈和数据栈不同步
    // 关键 1：辅助栈的元素空的时候，必须放入新进来的数
    // 关键 2：新来的数小于或者等于辅助栈栈顶元素的时候，才放入（特别注意这里等于要考虑进去）
    // 关键 3：出栈的时候，辅助栈的栈顶元素等于数据栈的栈顶元素，才出栈，即"出栈保持同步"就可以了
    
    public void push(int x) {
    	minStack.addFirst(x);
    	if (helpmin.isEmpty()||helpmin.getFirst()>=x){
    		helpmin.addFirst(x);
    	}
    }
    
    public void pop() {
    	if (!minStack.isEmpty()){
    		if (minStack.getFirst().equals(helpmin.getFirst())){
    			helpmin.removeFirst();
    		}
    		minStack.removeFirst();
    	}
    }
    
    public int top() {
    	if (!minStack.isEmpty()){
    		return minStack.getFirst();
    	}
    	return -1;
    }
    
    public int getMin() {
    	if (!helpmin.isEmpty()){
	    	return helpmin.getFirst();
    	}
    	return -1;
    }
}
```



