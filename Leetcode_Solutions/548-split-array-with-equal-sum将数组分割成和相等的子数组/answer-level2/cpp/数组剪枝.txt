### 解题思路
子数组题通常情况下使用presum进行求解，先求出数组的presum。

如果需要将数组分成3段，可以从中间那段入手，开始遍历：
需要满足前面两段满足条件，并且可能有多个满足条件的点，将所有存在的点存入到set里面；
然后在验证后面两段，后面两段首先需要相等，同时后面两段需要存在于前面的子数组和里面！


子数组 (0, i - 1)，(i + 1, j - 1)相等，并且把所有相等的放进一个set；
在验证(j + 1, k - 1)，(k + 1, n - 1)相等，并且出现在以前的set里面，这样虽然还是比较慢，但是能够理解。

### 代码

```cpp
class Solution {
public:
    bool splitArray(vector<int>& nums) {
		vector<long long> preSum(nums.size() + 1,0);
		if (nums.size() <= 3) {
			return false;
		}
		for (int i = 0; i < nums.size(); i++) {
			preSum[i + 1] = preSum[i] + nums[i];
		}
		bool flag = false;
		
		for (int j = 3; j + 2 < nums.size(); j++) {
			set<long long> ansTemp;
			for (int i = 1; i + 1 < j; i++) {
				if (preSum[i] - preSum[0] == preSum[j] - preSum[i + 1]) {
					ansTemp.insert(preSum[i]);
				}
			}
			for (int k = j + 2; k + 1 < nums.size(); k++) {
				if (preSum[k] - preSum[j + 1] == preSum[nums.size()] - preSum[k + 1] && ansTemp.find(preSum[nums.size()] - preSum[k + 1]) != ansTemp.end()) {
					return true;
				}
			}
		}
		return false;
    }
};
```