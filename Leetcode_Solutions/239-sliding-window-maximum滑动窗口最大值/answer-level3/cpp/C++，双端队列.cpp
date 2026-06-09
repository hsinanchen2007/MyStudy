### 解题思路
双端队列
### 代码

```cpp
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==0)return {};
		vector<int>res;
		deque<size_t>window;
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty()  && nums[i] > nums[window.back()]) {  //新的数出现，小于这个数的全部从后方出队
				window.pop_back();
			}
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		/*End of initialization*/
		for (size_t i = k; i < nums.size(); i++) {
			if (!window.empty() && window.front() <= i - k) {  //最大值的位置不在窗口中，从前方出队
				window.pop_front();
			}
			while (!window.empty() && nums[i] > nums[window.back()]) {  //同上
				window.pop_back();
			}
			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};
```