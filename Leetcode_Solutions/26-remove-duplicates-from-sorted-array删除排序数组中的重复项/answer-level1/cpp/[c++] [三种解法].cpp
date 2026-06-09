### 解题思路
解法一和解法二：面试经典考点erase
解法三：双指针

### 代码
解法一
```cpp
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty()) return 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] == nums[i]) {
				nums.erase(nums.begin() + i);
				i--;
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
	int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
		for (vector<int>::iterator it = nums.begin()+1; it != nums.end();) {
			if (*(it-1) == *it) {
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
解法三
```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int k = 1;
		for (int j = 1; j < nums.size(); j++) {
			if (nums[j] != nums[j - 1]) {
				nums[k++] = nums[j];
			}
		}
		return k;
	}
};
```
