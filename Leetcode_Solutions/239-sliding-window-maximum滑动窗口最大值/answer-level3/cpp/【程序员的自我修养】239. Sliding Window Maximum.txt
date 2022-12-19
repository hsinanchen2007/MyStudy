# 【程序员的自我修养】239. Sliding Window Maximum

### 解题思路
1. 暴力法，O（n^2）260 ms
```cpp
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0)return {};
		int length = nums.size();
		if (length <= 0)
			return vector<int>{};
		//  这一步很关键  因为vector每次扩张容量都会造成时间的损耗。
		vector<int> result(length - k + 1, 0);  
		//1. 暴力法，O（n^2）260 ms
		int maxNum = INT32_MIN;
		for (int i = 0; i <= length - k; i++)
		{
			maxNum = nums[i];
			for (int j = i; j < i + k; j++)
			{
				maxNum = max(nums[j], maxNum);
			}
			result[i] = maxNum;
		}
		return result;
}
```


2. 双端队列
**利用一个双端队列来保存当前窗口中最大那个数在数组里的下标，双端队列新的头就是当前窗口中最大的那个数。**
![239.gif](https://pic.leetcode-cn.com/f42d2ecac3c9be6253914d7e4cbddbb0dad4145abc0ff567681fcef06b78f012-239.gif)
```
初始化窗口 k = 3，包含 1，3， - 1，把 1 的下标压入双端队列的尾部；

把 3 和双端队列的队尾的数据逐个比较，3 > 1，把 1 的下标弹出，把 3 的下标压入队尾；

- 1 < 3， - 1 压入双端队列队尾保留到下一窗口进行比较；

3 为当前窗口的最大值；

窗口移动， - 3 与队尾数据逐个比较， - 3 < -1， - 3 压入双端队列队尾保留；

3 为当前窗口的最大值；

窗口继续移动，5 > -3， - 3 从双端队列队尾弹出；

5 > -1， - 1 从队尾弹出；

3 超出当前窗口，从队列头部弹出；

5 压入队列头部，成为当前窗口最大值；

继续移动窗口，操作与上述同理。
```

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0)return {};
		int length = nums.size();
		if (length <= 0)
			return vector<int>{};
		//  这一步很关键  因为vector每次扩张容量都会造成时间的损耗。
		vector<int> result(length - k + 1, 0);  
		deque<size_t>window;
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
		}
		result[0] = nums[window.front()];
		/*End of initialization*/

		for (size_t i = k; i < nums.size(); i++) {
			//超出当前窗口，从队列头部弹出
			if (!window.empty() && window.front() <= i - k)
				window.pop_front();

			while (!window.empty() && nums[i] > nums[window.back()])
				window.pop_back();

			window.push_back(i);
			result[i - k + 1] = nums[window.front()];
		}
		return result;
    }
};
```