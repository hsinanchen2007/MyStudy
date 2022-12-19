
```
class MaxQueue {
    
    private int[] data;
    private int front;
    private int rear;
    private int size;

    
    public MaxQueue() {
        data = new int [100000];
        front = 0;
        rear = 0;
        size = 0;
    }
    
    public int max_value() {
        if(size == 0)return -1;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < size; i++){
            if(data[(i + front)%data.length] > max){
                max = data[(i + front)%data.length];
            }
        }
        return max;
}
    
    public void push_back(int value) {
        data[rear] = value;
        rear = (rear + 1)%data.length;
        size++;
    }
    
    public int pop_front() {
        if(size == 0)return -1;
        int ret = data[front];
        front = (front + 1)%data.length;
        size--;
        return ret;
    }
    
}
```
