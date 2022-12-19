### 解题思路
利用数组作为哈希表计数，数组下标表示数字，对应存的数为个数，时间空间复杂度均为n,

### 代码

```cpp
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int n = nums.size();
		int* hash = new int[n];
		memset(hash, 0, n*sizeof(int));
		for (int i = 0; i<n; i++) {
			hash[nums[i]]++;
		}
		int result = -1;
		for (int i = 0; i<n; i++) {
			if (hash[i]>1) {
				result=  i;
				break;
			}
		}
        delete[]hash;
		return result;
	}
};
```