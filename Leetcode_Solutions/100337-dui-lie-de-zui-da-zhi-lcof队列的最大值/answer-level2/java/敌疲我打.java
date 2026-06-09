```
class MaxQueue {
    private ArrayDeque<Integer> valueDeque = new ArrayDeque<Integer>() ;
    private ArrayDeque<Integer> maxValueDeque = new ArrayDeque<Integer>() ;
    public MaxQueue() {
        
    }
    
    public int max_value() {
        return maxValueDeque.isEmpty() ? -1 : maxValueDeque.peek() ;
    }
    
    public void push_back(int value) {
        valueDeque.addLast(value) ;
        while (!maxValueDeque.isEmpty() && maxValueDeque.getLast() < value) {
            maxValueDeque.pollLast() ;
        }
        maxValueDeque.addLast(value) ;
    }
    
    public int pop_front() {
        if (valueDeque.isEmpty())
            return -1 ;
        else{
            int ret = valueDeque.pollFirst() ;
            if (ret == maxValueDeque.peek())
                maxValueDeque.pollFirst() ;
            return ret ;
        }
    }
}
```
