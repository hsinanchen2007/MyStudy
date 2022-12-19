![2020011001.PNG](https://pic.leetcode-cn.com/49e372f3ebb582bc5b2192a585795184a241964b98214916fef5cfffcbde73fa-2020011001.PNG)

### 解题思路
栈具有先进的元素后出的特点,即先进后出;
栈中,最下边（相当于队列的最左边）的元素是栈底,最上边（相当于队列的最右边）的元素是栈顶,栈中的元素总是从栈顶进和栈顶出.
队列具有先进的元素先出的特点,即先进先出;
队列中,位于队列最左边的元素称为队首,队首元素先出;位于队列最右边的元素称为队尾,每次添加元素总是从队尾添加.
#####在这里队列的pop()方法和peek()方法的实现类似.
//队列的pop()方法,队列删除元素(相当于将栈中的最下边的元素弹出栈):
维护两个栈stack1和stack2:
首先,将stack1中的所有元素弹出,并放入stack2中,
接着,从stack2中弹出栈顶元素,并将该元素返回,
最后,再将stack2中的所有元素弹出,并放入stack1中.
##########
//队列的peek()方法,取出元素(相当于找出栈中的最下边的元素):
维护两个栈stack1和stack2:
首先,将stack1中的所有元素弹出,并放入stack2中,
接着,从stack2中获取栈顶元素,将获得的栈顶元素返回,
最后,再将stack2中的所有元素弹出,并放入stack1中.

### 代码

```java
class MyQueue {

    /** Initialize your data structure here. */
    public MyQueue() {
        
    }
    private Stack<Integer> stack1 = new Stack<>();
    private Stack<Integer> stack2 = new Stack<>();
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
    	while(!stack1.isEmpty()) {
    		stack2.push(stack1.pop());
    	}
    	int temp = stack2.pop();
    	while(!stack2.isEmpty()) {
    		stack1.push(stack2.pop());
    	}
        return temp;
    }
    
    /** Get the front element. */
    public int peek() {
    	int i =0;
    	while(i<stack1.size()-1) {
    		stack2.push(stack1.pop());
    	}
    	int temp = stack1.pop();
    	stack2.push(temp);
    	while(!stack2.isEmpty()) {
    		stack1.push(stack2.pop());
    	}
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack1.size()==0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```