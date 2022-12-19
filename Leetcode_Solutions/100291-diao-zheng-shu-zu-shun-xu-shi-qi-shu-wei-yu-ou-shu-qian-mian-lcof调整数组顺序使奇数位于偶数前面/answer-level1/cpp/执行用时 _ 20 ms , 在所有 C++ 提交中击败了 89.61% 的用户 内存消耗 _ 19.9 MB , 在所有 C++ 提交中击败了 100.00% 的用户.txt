### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		while (low<=high) {
			if (nums[low]%2==1&&nums[high]%2==0) {
				low++;
				high--;
			}
			else if (nums[low] % 2 != 1 && nums[high] % 2 == 0) {
				high--;
			}
			else if (nums[low] % 2 != 1 && nums[high] % 2 != 0) {
				int temp = nums[high];
				nums[high] = nums[low];
				nums[low] = temp;
				low++;
				high--;
			}
			else {
				low++;
			}
		}
		return nums;
	}
};
```