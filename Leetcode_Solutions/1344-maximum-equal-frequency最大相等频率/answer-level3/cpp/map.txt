### 解题思路
首先是获取最长的**前缀**，采用的方式是从后往前一次遍历，一个一个的删除，找到一个满足条件的子序列，直接return；
建立两个哈希表，首先将每个元素出现的次数拿出来，构成一个整体nums的次数+set<int>的哈希表；
注意满足条件的情况：
1、当只有一种长度类型时，如果所有的num[i]都相同，满足要求；如果所有num都不一样，满足条件；
2、除此之外满足条件的必须要是两种长度，如果长度小的那个map元素，长度为1，且里面之后一个num，满足条件；如果剩余两种长度类型本来就差1，然后大的那个长度类型只包含一个元素，也可以满足条件；

逻辑比较复杂，需要把所有情况理清除。

### 代码

```cpp
class Solution {
public:
	bool IsEqualFreq(map<int, set<int>>& lengthNumMap) 
	{
		if (lengthNumMap.size() == 1) {
			auto pNumTimes = lengthNumMap.begin();
			if (pNumTimes->second.size() == 1) {
				return true;
			}
            if (pNumTimes->first == 1) {
                return true;
            }
		}
		if (lengthNumMap.size() == 2) {
			auto pNumTimes = lengthNumMap.begin();
            auto pNumTimesEnd = lengthNumMap.rbegin();
			if (pNumTimes->first == 1 && pNumTimes->second.size() == 1) {
                return true;
            }
			if (abs(pNumTimesEnd->first - pNumTimes->first) == 1 && pNumTimesEnd->second.size() == 1) {
				return true;
			}
		}
		return false;
	}
    int maxEqualFreq(vector<int>& nums) {
        map<int, int> numTimes;
		if (nums.empty()) {
			return 0;
		}
		for (auto num : nums) {
			if (numTimes.find(num) == numTimes.end()) {
				numTimes[num] = 1;
			} else {
				numTimes[num]++;
			}
		}
		map<int, set<int>> lengthNumMap;
		for (auto pNumTimes = numTimes.begin(); pNumTimes != numTimes.end(); pNumTimes++) {
			lengthNumMap[pNumTimes->second].insert(pNumTimes->first);
		}
		for (int i = nums.size() - 1; i > 0; i--) {
			if (IsEqualFreq(lengthNumMap)) {
				return (i+1);
			}
			for (auto pNumTimes = lengthNumMap.begin(); pNumTimes != lengthNumMap.end(); pNumTimes++) {
				if (pNumTimes->second.find(nums[i]) != pNumTimes->second.end()) {
					if (pNumTimes->first != 1) {
						lengthNumMap[pNumTimes->first - 1].insert(nums[i]);
					}
					pNumTimes->second.erase(pNumTimes->second.find(nums[i]));
					if (pNumTimes->second.empty()) {
						lengthNumMap.erase(pNumTimes);
					}
					break;
				}
			}
		}
		return 1;
    }
};
```