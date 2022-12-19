### 解题思路
只要寻找到能跳到的最远的点就行了，当跳到的最远点超过终点的时候就成功了。
利用上上次跳到的最远距离和上次跳到的最远距离，只要考虑中间点能跳的最远距离就可以得到本次最远距离。

### 代码

```cpp
#include<iostream>
#include<vector>
using namespace std;
using std::vector;

/*给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。*/
class Solution {
public:
	int get_far(vector<int>& nums, int farther, int farthest) {
		int max = farthest;
		for (int i = 0; i < farthest - farther; i++) {
			if (nums[i + farther + 1] + farther + i + 1 > max)
				max = nums[i + farther + 1] + farther + i + 1;
		}
		return max;
	}
	int jump(vector<int>& nums) {
		int farthest = nums[0], farther = 0;
		int size = nums.size();
		int ans = 1;
		if (size == 1)
			return 0;
		while (farthest < size-1) {
			ans++;
			int temp = get_far(nums, farther, farthest);
			farther = farthest;
			farthest = temp;
		}
		return ans;
	}
};
```