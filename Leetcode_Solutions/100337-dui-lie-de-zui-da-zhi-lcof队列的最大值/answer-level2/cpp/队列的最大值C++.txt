### 解题思路
![image.png](https://pic.leetcode-cn.com/0114d13cacfd99e5ee43916c9fc13f8537300147276af9b00dc8985395bbd89d-image.png)
我保存了一个头节点，可以方便操作（其实也差不多）
数据结构是用vector<int>实现的，为了取最大值方便。

### 代码
```cpp
class MaxQueue {
private:
    int MaxVal;
    vector<int> arr;
    int rear;
public:
    MaxQueue() {
        arr.clear();
        arr.push_back(-1);
        rear=0;
    }
    int max_value() {
        if(rear>0)
        {
            vector<int>::iterator a=arr.begin()+1;//+1是为了过滤掉头节点
            vector<int>::iterator b=arr.end();
            return arr[max_element(a,b)-a+1];
        }
        else return -1;
    }
    void push_back(int value) {
        arr.push_back(value);
        rear++;
    }
    int pop_front() {
        if(rear>0)
        {   
            int x=arr[1];
            vector<int>::iterator tmp=arr.begin();
            tmp++;
            arr.erase(tmp);
            rear--;
            return x;
        }
        else return -1;
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