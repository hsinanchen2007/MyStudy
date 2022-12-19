![image.png](https://pic.leetcode-cn.com/28546788c4b347bd98b7c447fce2083b654d18a42afbc622788c07a4535a7641-image.png)

### 解题思路
转化为有序二分法
思路精髓就是：每次二分必有一边是有序的，检查target在不在有序的那一边，从而决定下一次二分的方向

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1;
		while (left <= right){
			int mid = (right - left) / 2 + left;
			if (nums[mid] == target) return mid;
			if (nums[left] <= nums[mid]){//如果左边有序，则检查target是否在左边并决定二分方向
				if (nums[left] <= target && target < nums[mid]) right = mid - 1;
				else left = mid + 1;
			}
			else{//右边有序也同理
				if (nums[mid] < target && target <= nums[right]) left = mid + 1;
				else right = mid - 1;
			}
		}
		return -1;
	}
};
```