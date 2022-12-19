```
class MaxStack {
    Deque<Integer> stack;
    TreeMap<Integer, Integer> maxCache;
    /** initialize your data structure here. */
    public MaxStack() {
        stack = new LinkedList<>();
        maxCache = new TreeMap<>();
    }

    public void push(int x) {
        stack.push(x);
        if (maxCache.isEmpty()){
            maxCache.put(x,1);
        } else{
            if (maxCache.containsKey(x)) maxCache.put(x,maxCache.get(x)+1);
            else{
                maxCache.put(x,1);
            }
        }
    }

    public int pop() {
        if (stack.isEmpty()) return -1;
        int res = stack.pop();
        reduceKeyOfMaxCache(res);
        return res;
    }

    private void reduceKeyOfMaxCache(int key) {
        int newVal = maxCache.get(key) - 1;
        if (newVal == 0) maxCache.remove(key);
        else maxCache.put(key, newVal);
    }

    public int top() {
        if (stack.isEmpty()) return -1;
        return stack.peek();
    }

    public int peekMax() {
        return maxCache.lastKey();
    }

    public int popMax() {
        int res = peekMax();
        stack.removeFirstOccurrence(res); //注意stack中push是不断在list的头部加入。list头部即是堆顶
        reduceKeyOfMaxCache(res);

        return res;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
```
