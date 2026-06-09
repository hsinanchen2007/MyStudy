### 解题思路
使用一个双向链表辅助，保存最大值序列
Note：链表中小于后插入的元素的元素，对结果没有影响

### 代码

```cpp
class MaxQueue {
private:
    queue<int> que;
    list<int> que_vice;
public:
    MaxQueue() {
    }
    
    int max_value() {
    //    cout<<"max:"<<que_vice.front()<<endl;
        if(que.empty()){
            return -1;
        }
        return que_vice.front();
    }
    
    void push_back(int value) {
    //    cout<<"pus:"<<value<<endl;
        if(value > que_vice.front()){ // 大于最大元素
            que_vice.clear();
            que_vice.push_back(value);
        }else{ 
            // 移除所有小于当前插入元素的结点
            for (auto it = que_vice.begin(); it != que_vice.end();){
                if(*it < value){
                    it = que_vice.erase(it);
                }else{
                    it++;
                }
            }
            que_vice.push_back(value);
            }
        }
	    
        que.push(value);
    }
    
    int pop_front() {
        
        if(que.empty()){
            return -1;
        }
        int t = que.front();
        que.pop();
        if(t == que_vice.front()){
            que_vice.pop_front();
        }
    //    cout<<"pop:"<<t<<endl;
        return t;
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