### 解题思路
其实就算是使用双端队列时间复杂度应该也不是O(1)。

实现队列功能，同时还需要返回最大值，肯定就是需要增加空间来存储相应数据。
如果只用一个max来保存最大值，当最大值被pop了之后，是不好获取下一个最大值的。那么可以使用一个双端队列，队列首总是保存当前队列里面的最大值，
push操作，那么利用该数把前面比它小的数都干掉，应该那个数肯定是最后一个被pop出去的，比它小的数已经没有意义了；
pop操作，如果当前pop的数就是max队列的首位，直接将max队列的首位pop即可。

### 代码

```cpp
class MaxQueue {
public:
	queue<int> commQueue;
	deque<int> maxQueue;
    MaxQueue() {
	
    }
    
    int max_value() {
		if (maxQueue.empty()) {
			return -1;
		}
		return maxQueue.front();
    }
    
    void push_back(int value) {
		commQueue.push(value);
		while(! maxQueue.empty() && maxQueue.back() < value) {
			maxQueue.pop_back();
		}
		maxQueue.push_back(value);
    }
    
    int pop_front() {
		if (commQueue.empty()) {
			return -1;
		}
		int ans = commQueue.front();
		commQueue.pop();
		if (ans == maxQueue.front()) {
			maxQueue.pop_front();
		}
		return ans;
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