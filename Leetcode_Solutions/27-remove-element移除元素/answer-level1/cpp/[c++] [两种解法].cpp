### 解题思路
面试经典考点:erase

### 代码
解法一
```cpp
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
			if (*it == val) {
				it = nums.erase(it);
			}
			else {
				it++;
			}
		}
		return nums.size();
	}
};
```
解法二
```cpp
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				nums.erase(nums.begin() + i);
				i--;	//随着erase操作数组在不断缩短
			}
		}
		return nums.size();
	}
};
```