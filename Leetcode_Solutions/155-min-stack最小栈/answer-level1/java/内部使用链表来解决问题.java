### 解题思路
内部使用链表，每次push都保存一个最小值，每次pop都重新计算最小值

### 代码

```java
class MinStack {

    private int minValue = Integer.MAX_VALUE;

    private LinkedList<Integer> queue;

    /** initialize your data structure here. */
    public MinStack() {
        queue = new LinkedList<>();
    }

    // 增加一个元素修改最小值
    public void push(int x) {
        if(x < minValue){
            minValue = x;
        }
        queue.addLast(x);
    }

    // 弹出一个元素，有可能把最小值弹出去了
    public void pop() {
        if(queue.size()>0){
            int ele = queue.removeLast();
            if(ele == minValue){
                minValue = Integer.MAX_VALUE;
                for(int m:queue){
                    if(m < minValue){
                        minValue = m;
                    }
                }
            }
        }
    }

    public int top() {
        if(queue.size()>0){
            return queue.getLast();
        }else{
            throw new RuntimeException("no element here");
        }
    }

    public int getMin() {
        return this.minValue;
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