```cpp
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = -1; //nums[0...zero] == 0
		int two = nums.size();	//nums[two..n-1] == 2
		for (int i = 0; i < two;) {
			if (nums[i] == 1) {
				i++;
			}
			else if (nums[i] == 2) {
				swap(nums[i], nums[--two]);
			}
			else {
				swap(nums[++zero], nums[i++]);
			}
		}
	}
};
```
