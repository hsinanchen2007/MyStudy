### 解题思路
hashmap

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res{ 0,0 };
		map<int, int> mapNumber;

		int index = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			if (mapNumber.find(target - *it) == mapNumber.end()) {
				mapNumber.insert(pair<int, int>(*it, index));
				index++;
			}
			else {
				res[0] = mapNumber[target - *it];
				res[1] = index;
				return res;
			}
		}
        return res;

    }
};
```