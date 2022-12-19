### 解题思路
1.看到时间复杂度为O（1）时，就知道不能用循环，第一个想到的是用自动排序存储的SortedSet进行辅助，但由于Set不能存储相同的元素，这个想法被测试用例0，1，0打回
2.尝试用两个栈，一个栈正常执行出入栈、取栈顶操作，另一个用于存当前输入进来的数中的最小值。一开始的时候两个栈同时push第一个输入的数，之后，另一个存最小值的栈在每次有值输入的时候都判断：如果这个输入的值比当前栈顶更小才入栈。在pop操作时存最小值的栈需要判断准备出栈的这个数是否当前栈顶（即最小的数），如果是，存最小值的栈也要执行出栈操作，因为这时原来的最小值已经被出栈，此时的最小值是之前的历史最小值。这样，取最小值的时候只要取存最小值的栈的栈顶元素就可以了。

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> stack=new Stack<>();
	Stack<Integer> s1=new Stack<>();
    public MinStack() {
        
    }
    
    public void push(int x) {
        if(stack.empty()) {
    		s1.push(x);
    	}
    	if(!s1.empty() && x<=s1.peek()) {
    		s1.push(x);
    	}
        stack.push(x);
    }
    
    public void pop() {
        int x=stack.pop();
    	if(x==s1.peek()) {
    		s1.pop();
    	}
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return s1.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```