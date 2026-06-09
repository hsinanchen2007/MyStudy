参考[滑动窗口中的最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)，这里只需要稍微的改写一下边界检查代码即可
```
class MaxQueue {
public:
    //双向队列加一个普通队列
    deque<int> dq;//记录下标
    int head=0,rear=0,max_queue[10000];
    void clear_dq(int val){
        while(!dq.empty()&&max_queue[dq.back()]<=val)dq.pop_back();
        dq.push_back(rear);
    }
    MaxQueue() {

    }
    
    int max_value() {
        if(head==rear)return -1;
        return max_queue[dq.front()];
    }
    
    void push_back(int value) {
        clear_dq(value);
        max_queue[rear++]=value;
    }
    
    int pop_front() {
        if(head==rear)return -1;
        if(dq.front()==head){
            dq.pop_front();
        }
        return max_queue[head++];
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```
