### 解题思路
做的时候想偏了，用了DP。。。

主要的矛盾是怎么将数据分类，以什么为变量进行循环。
所有工程师的效率最小值为整个团队的效率，那么只要遍历所有效率，那么所有的可能性就遍历完了。因此先将效率和速度整合在一起，然后以效率排序，这里注意需要从大到小排序，因为最大效率的结果是已知的；然后往下遍历，如果总人数小于K，那么直接加入，然后刷新ans即可；如果总人数超过了K，那么这个时候就需要看看当前的speed最小是什么（因为当前情况下的效率已经固定了），如果当前的speed小于整个团队的最小speed，那么它算出来的结果一定不是答案；反之，重新计算结果。动态增删，快速获取最值，利用优先队列求解即可。

### 代码

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (k == 0) {
			return 0;
		}
		unsigned long long ans = 0;
		vector<pair<int, int>> nums;
		for (int i = 0; i < n; i++) {
			nums.emplace_back(speed[i], efficiency[i]);
		}
		sort(nums.begin(), nums.end(), [](pair<int,int> a, pair<int,int> b){
			return a.second > b.second;
		});
		unsigned long long sum = 0;
		priority_queue<int, vector<int>, greater<int>> smallQueue;
		for (int i = 0; i < n; i++) {
			unsigned long long eff = nums[i].second;
			if (smallQueue.size() < k) {
				smallQueue.push(nums[i].first);
				sum += nums[i].first;
			} else {
				if (nums[i].first > smallQueue.top()) {
					sum = sum - smallQueue.top() + nums[i].first;
					smallQueue.pop();
					smallQueue.push(nums[i].first);
				}
			}
			ans = max(ans, sum * eff);
		}
		return ans % (1000000000 + 7);
    }
};
```