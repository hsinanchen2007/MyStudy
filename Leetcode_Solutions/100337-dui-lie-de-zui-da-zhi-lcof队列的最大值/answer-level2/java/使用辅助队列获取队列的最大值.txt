## 解题思路：使用队列 data 实现队列的正常入队和出队操作；
## 使用一个辅助的双向队列 helper（代码中使用LinkedList实现）在常数时间内获取队列中的最大值，helper为一个单调递减的队列

##代码
class MaxQueue {
    Queue<Integer> data;
    LinkedList<Integer> helper;

    public MaxQueue() {
        data = new LinkedList<>();
        helper = new LinkedList<>();
    }
    
    public int max_value() {
        if(helper.isEmpty()) return -1;
        return helper.getFirst();  // helper的队首元素即为此时data中的最大元素
    }
    
    public void push_back(int value) {
        // helper的元素入队时，需要将队尾的元素依次与value值进行比较：若队尾元素较小，则弹出；直到队尾元素不小于value时才能将value入队
        while(!helper.isEmpty() && helper.getLast() < value){
            helper.pollLast();
        }
        helper.add(value);
        data.add(value);   
    }
    
    public int pop_front() {
        if(data.isEmpty()) return -1;

        int temp = data.peek();
        if(temp == helper.getFirst()){
            helper.pollFirst();
        }
        return data.remove();
    }
}