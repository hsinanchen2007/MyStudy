### 思路
1. 使用一个优先队列用来存储**窗口中**的数字，插入时会排序。
2. 使用一个优先队列用来存储**离开窗口**的数字。
3. 遍历数组，超过k个元素时，开始将**窗口中**的最大值（即优先队列的top）存入返回值。
4. 如果**窗口中**和**离开窗口**两个优先队列中最大的值相同，说明可以删除了。循环处理可以删除的数值。
5. 否则，就算有已经过期的数字还在**窗口中**存储，但是不影响最大值，所以不用担心。
6. 遍历结束，返回结果。

### 答题
```C++
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> ans;
	priority_queue<int> del_queue;
	priority_queue<int> cur_queue;

	for (size_t i = 0; i < nums.size(); i++)
	{
		cur_queue.push(nums[i]);
		if (i < k - 1) continue;

		ans.push_back(cur_queue.top());
		del_queue.push(nums[i - k + 1]);
		while (!cur_queue.empty() && !del_queue.empty() && cur_queue.top() == del_queue.top())
		{
			cur_queue.pop();
			del_queue.pop();
		}
	}
	return ans;
}
```


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

