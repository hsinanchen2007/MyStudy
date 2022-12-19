### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int zero = 0;
		int cur = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				zero++;
			}
			else if (cur == -1) {
				cur = nums[i];
			}
			else if (cur == nums[i]) {
				return false;
			}
			else if (++cur != nums[i]) {
				if (zero > 0) {
					zero--;
					i--;
				}
				else {
					return false;
				}
			}
		}
	return true;
	}
};
```