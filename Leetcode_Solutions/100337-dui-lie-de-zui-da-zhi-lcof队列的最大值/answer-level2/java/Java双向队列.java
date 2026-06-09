```Java
class MaxQueue {
    private Queue<Integer> dataDeque = new LinkedList<>();
    private Deque<Integer> maxValueDeque = new ArrayDeque<>();
    
    public MaxQueue() {
        
    }
    
    public int max_value() {
        if (dataDeque.isEmpty()) return -1;
        return maxValueDeque.getFirst();
    }
    
    public void push_back(int value) {
        while (!maxValueDeque.isEmpty() && value > maxValueDeque.getLast()) {
            maxValueDeque.removeLast();
        }
        dataDeque.add(value);
        maxValueDeque.addLast(value);
    }
    
    public int pop_front() {
        if (dataDeque.isEmpty()) return -1;
        if (dataDeque.peek().equals(maxValueDeque.getFirst())) maxValueDeque.removeFirst();
        return dataDeque.poll();
    }
}
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！