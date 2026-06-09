```
class MaxQueue {
    Queue<Integer> queue;
    List<Integer> res; //为了在max_value中找到最大数 因为在queue中peek方法用于peek第一个
    public MaxQueue() {
        queue = new LinkedList<>();
        res = new ArrayList<>();
    }
    
    public int max_value() {
        if(queue.isEmpty())
            return -1;
        int max = Integer.MIN_VALUE;
        for(int i = 0 ; i < res.size() ; i ++){
            if(res.get(i) == null)
                continue;
            else{
                int temp = res.get(i);
                if( temp > max){
                    max = temp;
                }
            }
        }
        return max;
    }
    
    public void push_back(int value) {
        queue.offer(value);
        res.add(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty())
            return -1;
        int tem = res.indexOf(queue.peek());//找到这个pop——front的元素的位置  并在res中删除
        res.remove(tem);
        return queue.poll();
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
