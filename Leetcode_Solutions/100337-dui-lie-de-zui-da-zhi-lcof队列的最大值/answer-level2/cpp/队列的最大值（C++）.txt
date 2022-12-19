### 解题思路
使用队列实现，最大队列最前端始终保持当前最大值及其index，如果新加入的值大于当前队列中的值，则清空当前小于当前值得所有值，保存当前值到队列后端，保存当前最大值，如果小于则保存到最大队列的后边（最大值被弹出后，当前值为最大值），如果队列中当前最大值被弹出，根据相应的index判断是否为最大队列的头值

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue():cur_idx(0) { // 新加入的值在队列中的index

    }
    
    int max_value() {
        if(max_data.empty())
            return -1;
        return max_data.front().data_val;
    }
    
    void push_back(int value) {
        while(!max_data.empty() && value >= max_data.back().data_val)
            max_data.pop_back(); // 弹出最大队列中小于当前的值
        temp temp_data{value, cur_idx};
        data.push_back(temp_data);
        max_data.push_back(temp_data);
        cur_idx++;
    }
    
    int pop_front() {
        if(max_data.empty())
            return -1;
        int result = data.front().data_val;
        if(data.front().index == max_data.front().index)
            max_data.pop_front();  // 根据队列中弹出的值的index判断是否需要弹出最大队列中的值
        data.pop_front();
        return result;
    }

    struct temp
    {
        int data_val;
        int index;
    };
    int cur_idx;
    deque<temp> data;
    deque<temp> max_data;


};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```