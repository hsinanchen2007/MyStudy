### 解题思路
![image.png](https://pic.leetcode-cn.com/8231f7b98fef478c4ba592e1d4e42f1d7298b235f418df907e1f11403844c6ea-image.png)

还能优化。

这里有一个巧妙的点在于：
在保存最大值的deque中，
* 如果后面入队的数比前面小，自然不会**丢失**，压入尾部即可；
* 如果后面入队的数比前面大，会将前面小的数抛弃，直达遇到比入队的数要大的数，再执行入队。
尽管在第二种情况中，会丢失一部分数据，但可以发现：丢失的那些数，在queue出队的时候，不可能是当时queue中剩余数的最大数！这个很关键！

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (max.size() != 0) {
            return max.front();
        }
        return -1;
    }
    
    void push_back(int value) {
        ret.push(value);
        if (max.size() == 0) {
            max.push_back(value);
        } else if (value <= max.back()) {
            max.push_back(value);
        } else {
            while (max.size() && max.back() < value) {
                max.pop_back();
            }
            max.push_back(value);
        }

    }
    
    int pop_front() {
        if (ret.size() == 0) {
            return -1;
        }
        int tmp = ret.front();
        ret.pop();
        if (tmp == max.front()) {
            max.pop_front();
        }
        return tmp;
    }
private:
    queue<int> ret;
    deque<int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```