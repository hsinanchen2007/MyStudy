### 解题思路
此处撰写解题思路
这题的关键是如何寻找到最小值，解决了这个问题，这题就通过了。
一开始想的是直接用一个min存最小值不就行了吗，但是因为会pop元素，所以min值会改变，这时下一个min值就不知道了。
所以我们可以用一个栈来存储当前栈中的最小值。
开两个栈，一个储存元数据，一个存当前栈的最小元素。
设这两个栈分别为st1,st2,下面我们来演示一下。
push(-2):st1:-2  st2:-2
push(0):st1:-2,0 st2:-2,-2
push(-3):st1:-2,0,-3 st2:-2,-2,-3
这样每次pop()元素时，将st1,st2分别pop()即可，用一个min来存储st2的top值，如果st2为空，那么min=Integer.MAX_VALUE;
### 代码

```java
class MinStack {
    private Stack<Integer> st1;
    private Stack<Integer> st2;
    private int min;
    /** initialize your data structure here. */
    public MinStack() {
        st1=new Stack<>();
        st2=new Stack<>();
        min=Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        st1.push(x);
        if(min>x)
        min=x;
        st2.push(min);
    }
    
    public void pop() {
        st1.pop();
        st2.pop();
        if(!st2.isEmpty())
        min=st2.peek();
        else
        min=Integer.MAX_VALUE;
    }
    
    public int top() {
        return st1.peek();
    }
    
    public int getMin() {
        return min;
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