### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {
    
    int[] arr = new int[20000];
    int head = 0;
    int end = 0;

    public MaxQueue() {
        
    }
    
    public int max_value() {
        if(head == end){
            return -1;
        }else{
            int max = arr[head];
            for(int i = head;i<end;i++){
                max = Math.max(max,arr[i]);
            }
            return max;
        }
    }
    
    public void push_back(int value) {
        arr[end] = value;
        end++;
    }
    
    public int pop_front() {
        if(head == end){
            return -1;
        }else{
            return arr[head++];
        }
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