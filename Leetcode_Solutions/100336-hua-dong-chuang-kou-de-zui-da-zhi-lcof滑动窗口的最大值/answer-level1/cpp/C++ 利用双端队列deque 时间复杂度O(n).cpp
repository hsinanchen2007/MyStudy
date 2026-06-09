### 解题思路

举例如下：
![image.png](https://pic.leetcode-cn.com/7c80de271eb8ca21329d2a162354e3f99c5012dec8cf81a0dff76c38a7de7f13-image.png)



### 代码

```cpp
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;//存放最大值的索引
		vector<int> res;//存放答案

		if (nums.size() >= k && k > 0) {
			//获取第一个滑动窗口的最大值
			for (int i = 0; i < k; i++)
			{
				while (dq.size() > 0 && nums[i] > nums[dq.back()])
					//队列中有值，且当前值比最后一个值大
					//则把队列中的比它小的值删除
				{
					dq.pop_back();
				}
				//压入下标
				dq.push_back(i);
			}
			//存储最大值
			res.push_back(nums[dq.front()]);
			//获取其它滑动窗口的最大值
			for (int i = k; i < nums.size(); i++)
			{
				while (dq.size() > 0 && nums[i] > nums[dq.back()])
					//队列中有值，且当前值比最后一个值大
					//则把队列中的比其小的值删除
				{
					dq.pop_back();
				}
				//压入下标
				dq.push_back(i);
				//如果加入该值之后，队列的存储数据下标值之差比窗口值大（说明首元素不属于该滑动窗口），删除首元素
				if (abs(dq.front() - dq.back()) >= k)
				{
					dq.pop_front();
				}
				//存储最大值
				res.push_back(nums[dq.front()]);
			}
		}
		return res;
	}
};
```