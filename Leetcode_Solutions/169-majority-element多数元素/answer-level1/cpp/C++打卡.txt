### 解题思路
使用hashmap存储数值出现的次数

### 代码

```cpp
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int>numCount;
		for (int i = 0; i < nums.size(); i++) {
			numCount[nums[i]]++;
		}

		int maxCount = 0, maxCountNum = 0;
		for (pair<int,int> cur : numCount) {
			if (cur.second > maxCount) {
				maxCount = cur.second;
				maxCountNum = cur.first;
			}
		}
		return maxCount > floor(nums.size() / 2) ? maxCountNum : -1;
	}
};
```