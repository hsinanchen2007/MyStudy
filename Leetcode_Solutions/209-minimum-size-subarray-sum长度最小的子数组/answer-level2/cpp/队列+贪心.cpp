### 解题思路
求子数组的区间和问题，二话不说，直接转成前缀和。
由于本题目每一个数字都是大于0，所以前缀和应该是一个单调递增的数组。
利用队列，从前往后压入队列，那么队首的数一定是最小的。

遍历到i的时候，如果它能满足条件，那么当前队首的元素就没有存在的意义了，直接弹掉即可。
遍历一次preSum，找到ans最小值即可。

ps：如果输入元素存在负数，那么就需要优先队列进行求解，**需要保证队首元素为当前最小值，那么当前的index和队首组合起来就是利用当前队首的情况下的最佳解决方案。**

### 代码

```cpp
class Solution {
public:
	struct node {
		int index;
		int num;
		node (int i, int n) {
			index = i;
			num = n;
		}
	};
    int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		vector<int> preSum(1 + nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			preSum[i + 1] = nums[i] + preSum[i];
		}
		int ans = INT_MAX;
		queue<node> numQueue;
		numQueue.push(node(0, preSum[0]));
		for (int i = 1; i < preSum.size(); i++) {
			while (! numQueue.empty() && preSum[i] - s >= numQueue.front().num) {
				ans = min (ans, i - numQueue.front().index);
				numQueue.pop();
			}
			numQueue.push(node(i, preSum[i]));
		}
		return ans == INT_MAX ? 0 : ans;
    }
};
```