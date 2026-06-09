class MaxQueue {
    Queue<Integer> data;
    Deque<Integer> helper=null;

    public MaxQueue() {
        data=new LinkedList<>();
        helper=new LinkedList<>();
    }
    
    public int max_value() {
        if(helper.isEmpty()){
            return -1;
        }
        return helper.getFirst();
    }
    
    public void push_back(int value) {
        data.add(value);
        while(!helper.isEmpty() && helper.getLast() < value){
            helper.removeLast();
        }
        helper.addLast(value);
    }
    
    public int pop_front() {
        if(data.isEmpty())
            return -1;
        int ret=data.peek();
        if(ret==helper.getFirst())
            helper.pop();
        return data.poll();
    }
}