### 解题思路
假如不存在重复元素的话，则二分法很好实现，但此题存在重复元素，所以会比较复杂一点。

举例：
对于 [0, 1, 4, 4, 4] 这个数组，使用二分法拿出位于中间的 idx 为 2 的数字 4，然后我们发现 nums[idx] > idx
此刻我们除了可以确认 idx2 不是魔术索引外，还可以确定 idx3 也肯定不是魔术索引。因为假如 idx3 是魔术索引的话那 idx3 的值就必须是 3，这将导致 nums[idx3] < nums[idx2]，和题目的“递增数组”矛盾。
所以，此刻魔术索引只可能出现在 [0, mid - 1] 和 [nums[mid], nums.length - 1] 这两个范围里。

### 代码

```javascript
var findMagicIndex = function(nums) {
	// 在 [left, right] 范围内搜索最小的魔术索引值，不存在则返回 -1
	var helper = function(left, right) {
		if (left > right) {
			return - 1;
		}
        	// 二分搜索，所以找中间点
		var mid = left + ((right - left) >> 1);
		if (nums[mid] == mid) {
			// mid 肯定是魔术索引，但 [left, right - 1] 也有可能存在魔术索引
			var res1 = mid;
			var res2 = helper(left, right - 1);
			if (res2 == -1) {
				return res1;
			} else {
				return res2;
			}

		} else if (nums[mid] > mid) {
			// mid 不是魔术索引，但 [left, mid - 1] 和 [nums[mid], right] 可能存在魔术索引
			// 换句话说，[mid, nums[mid] - 1] 之间肯定不存在魔术索引
			var res1 = helper(left, mid - 1);
			if (res1 != -1) {
				return res1;
			}
			return helper(nums[mid], right);

		} else if (nums[mid] < mid) {
			// mid 不是魔术索引，但 [left, nums[mid]] 和 [mid + 1, right] 可能存在魔术索引
			// 换句话说，[nums[mid] + 1, mid] 之间肯定不存在魔术索引
			var res1 = helper(left, nums[mid]);
			if (res1 != -1) {
				return res1;
			}
			return helper(mid + 1, right);
		}
	};
	return helper(0, nums.length - 1);
};
```