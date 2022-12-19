```
class MaxQueue {
public:
    std::queue<int> que;
    std::deque<int> deq; //辅助双端队列，随着每次push记录队列中相应最大值、第二大、第三大.....单调非递增
    MaxQueue() {
    }
    int max_value() {
        if(deq.size() == 0) return -1;
	    return deq.front();
    }
    void push_back(int value) {
        que.push(value);
	    if(deq.size() == 0) deq.push_back(value);
        else if(value > deq.front()) {
            deq.clear();
            deq.push_back(value); //更新最大值
	    }
	    else{         //维护双端队列非递增特性，若双端队列队尾元素小于当前push入的元素，则不断被弹出
		    while (deq.back() < value) deq.pop_back();
		    deq.push_back(value);
	    }
    }
    int pop_front() {
        if(que.size() == 0) return -1;
	    int res = que.front();
	    que.pop();
	    if (res == deq.front()) deq.pop_front();//若弹出的元素为最大值，需弹出双端队列队头元素
	    return res;
    }
};
```
