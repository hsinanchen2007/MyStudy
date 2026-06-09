### 解题思路
用了两种方法，第一种是将两数之和等于第三数的相反数，超时；
第二种办法用到了三指针，多指针技巧一般用于处理同时需要数组里面的多个元素的场景；解此题主要需要注意剪枝；
先将数组排好序，然后利用一个指针代表第一个参数，由它来控制整个大循环，每一次遍历结果都是让end指针和middle指针重合；
需要注意的是，当找打正确答案之后，继续挪动end和middle指针的时候，需要剪枝，去除掉两个指针重复的的元素；
最后挪动first指针的时候也需要剪枝，和当前已经遍历过的num相同的数值不需要再次遍历。

**C++注意点** vector的size是一个size_t类型，为一个无符号数，如果小于-便会反转变为一个很大的书，这一点需要特别注意，最好是在一开始将数组长度强转成一个有符号int型。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		int numLenth = nums.size();
		for (int k = 0; k <= numLenth - 3;) {
			int end = numLenth - 1;
			int middle = k + 1;
			while(middle < end) {
				while(middle != end && nums[k] + nums[middle] + nums[end] > 0) {
					end--;
				}
				while(middle != end && nums[k] + nums[middle] + nums[end] < 0) {
					middle++;
				}
				if (middle != end && nums[k] + nums[middle] + nums[end] == 0) {
					vector<int> resultsItem{nums[k], nums[middle], nums[end]};
					results.push_back(resultsItem);
					while(middle != end && nums[middle] == nums[middle + 1]) {
						middle++;
					}
					while(middle != end && nums[end] == nums[end -1]) {
						end--;
					}
					middle++;
					end--;
				}
			}
			while(k < numLenth - 3 && nums[k] == nums[k+1]) {
				k++;
			}
			k++;
		}
		return results;
	}
};
```