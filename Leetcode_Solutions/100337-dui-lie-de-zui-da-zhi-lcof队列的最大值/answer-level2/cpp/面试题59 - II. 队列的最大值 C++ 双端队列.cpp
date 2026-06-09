### 解题思路
参考《剑指offer》和[面试题59 - II. 队列的最大值](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/)以及[239. 滑动窗口最大值 C++ 双端队列](https://leetcode-cn.com/problems/sliding-window-maximum/solution/239-hua-dong-chuang-kou-zui-da-zhi-c-shuang-duan-d/)

### 代码

```cpp
class MaxQueue {
public:
    deque<int> maxQueue;    // 队列只保存最大值
    queue<int> q;           // 普通队列
    MaxQueue() {

    }
    
    int max_value() {
        if(maxQueue.empty()){
            return -1;
        }
        else{
            // 如果最大化值队列不为空，返回队首元素即为最大值
            return maxQueue.front();
        }
    }
    
    void push_back(int value) {
        while(!maxQueue.empty() && value > maxQueue.back()){
            // 如果队列元素不为空，并且push进来的元素比队列最小值要大，那么要将比value小的值出栈（因为这些值不可能成为最大值了）
            maxQueue.pop_back();
        }
        maxQueue.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()){
            // 如果普通队列为空，那么返回-1
            return -1;
        }
        int res = q.front();    // res保存pop_front()的结果
        if(res == maxQueue.front()){
            // 为了保证q和maxQueue的同步
            // 如果q.front()和maxQueue.front()为同一个元素，那么maxQueue也需要弹出队首元素
            maxQueue.pop_front();
        }
        q.pop();
        return res;
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