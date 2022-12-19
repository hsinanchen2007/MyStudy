```
class MaxQueue {
    MaxStack s1;
    MaxStack s2;

    public MaxQueue() {
        s1 = new MaxStack();
        s2 = new MaxStack();
    }

    public int max_value() {
        if(s1.isEmpty() && s2.isEmpty()){
            return -1;
        }
        return s1.getMax() > s2.getMax()? s1.getMax(): s2.getMax();
    }

    public void push_back(int value) {
        s1.push(value);
    }

    public int pop_front() {
        if(s1.isEmpty() && s2.isEmpty())
            return -1;
        
        if(s2.isEmpty()){
            while (!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

}
class MaxStack {
    LinkedList<Integer> s1;
    LinkedList<Integer> smax;

    /**
     * initialize your data structure here.
     */
    public MaxStack() {
        s1 = new LinkedList<>();
        smax = new LinkedList<>();
    }

    public void push(int x) {
        s1.add(x);
        if (smax.isEmpty())
            smax.add(x);
        else {
            if (x < smax.peekLast())
                smax.add(smax.peekLast());
            else
                smax.add(x);
        }
    }

    public int pop() {
        if(s1.isEmpty())
            return -1;
        smax.pollLast();
        return s1.pollLast();
    }

    public int top() {
        return s1.peekLast();
    }

    public int getMax() {
        if(smax.isEmpty())
            return -1;
        return smax.peekLast();
    }

    public boolean isEmpty() {
        return s1.isEmpty();
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
如果最小栈和用栈实现队列已经做好，把最小栈改成最大栈，直接拿过来套一下就好了。
第一次提交假设调用都合理，没有考虑空的时候返回-1，没过。看了一下说明，然后急急忙忙修修补补了几个if判断，比较丑陋。