### 解题思路
利用两个队列实现队列的最大值
这道题目和59-1.滑动窗口的最大值类似，对于入栈处理方式相同，难点在于出栈的实现。
通过手动模拟出每次插入数据后，两个队列的情况，可以慢慢找到规律，所以对于这类题目思想上就是开始时多尝试通过手动模拟，找到一些规律，这样就容易下手
如对于[1,3,-1,5]这个序列的模拟，参考如下
![image.png](https://pic.leetcode-cn.com/e815037faa4f3c077b042dd92636d1a9159a5e420d0b0f213aa18ccfe0dab6ec-image.png)



### 代码
```cpp
class MaxQueue {
public:
	deque<int> dq_data;
	deque<int> dq_max;
	MaxQueue() {

	}
	//获取最大值
	int max_value() {
		if (dq_max.size() == 0) return -1;
		return dq_max.front();
	}
	//入栈
	void push_back(int value) {
		dq_data.push_back(value);
		while (!dq_max.empty()&&dq_max.back() < value) {
				dq_max.pop_back();
			}
		dq_max.push_back(value);
	}
	//出栈
	int pop_front() {
		//栈为空
		if (dq_data.size() == 0) return -1;
		int res=dq_data.front();
		//如果当前元素，和dq_max的栈顶元素相同，栈顶元素也要出栈，如果不同，则不需要出栈；
		if (dq_data.front() == dq_max.front()) dq_max.pop_front();
        dq_data.pop_front();
		return res;
	}
};
```