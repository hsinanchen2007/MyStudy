// 计数法
```
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int count[3] = { 0 };
		for (auto i : nums) {
			assert(i>=0 && i<=2);
			count[i]++;
		}
		int sortedIndex = 0;
		for (int i=0; i < sizeof(count)/sizeof(count[0]) ; i++) {
			while (count[i] > 0) {
				nums[sortedIndex] = i;
				sortedIndex++;
                count[i]--;
			}
		}
	}
};
```

//三路快排
```
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = 0;
		int two = nums.size()-1;
		for (int i = 0; i <= two;) {
			if (nums[i] == 0) {
				swap(nums[i], nums[zero]);
				i++;
				zero++;
			}
			else if (nums[i] == 1) {
				i++;
			}
			else {
				assert(nums[i] == 2);
				swap(nums[i], nums[two]);
				two--;
			}
		}
	}
};
```
