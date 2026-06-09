### 解题思路
使用partition，双路快排and剪枝
### 代码

```cpp
class Solution {
private:
	// 返回随机找到数的基准值
	int partition(vector<int>& nums, int l, int r)
	{
		int randnum = rand() %(r - l+1) + l;
		int target = nums[randnum];
		swap(nums[l], nums[randnum]);
		while (l < r) {
			while (l < r && nums[r] > target)
				r--;
			nums[l] = nums[r];
			while (l < r && nums[l] <= target)
				l++;
			nums[r] = nums[l];
		}
		nums[l] = target;
		return l;
	}

public:
	int findKthLargest(vector<int>& nums, int k) {
		int m = nums.size();
		k = m - k;          //因为排成了从小到大，则转换下
		int l = 0 , r = nums.size() - 1;
		while( l <= r){
			int t = partition(nums,l,r);
			if(t == k) // 如果基准值就是K 则返回
				return nums[k];
			else if(t > k)  // 如果基准值大于k ,则在基准值左边寻找
				r = t - 1;
			else			// 如果基准值小于K,则在基准值右边寻找
				l = t + 1;
		}
		return nums[k];
	}
};
```