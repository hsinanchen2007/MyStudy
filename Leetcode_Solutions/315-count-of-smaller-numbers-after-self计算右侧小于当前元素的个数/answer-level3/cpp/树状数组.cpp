### 解题思路
还是按照之前的思路，给原数组排序，因为是右边的所有数据，所有从后往前遍历，就是获取sum[rank]即可。
树状数组，两个函数Read和ADD，熟练lowBit操作，代码相比于线段树更加简单。

### 代码

```cpp
class Solution {
public:

int lowBit(int x)
{
	return x&(-x);
}

int Read(vector<int>& treeNum, int x)
{
	int ans = 0;
	while (x > 0) {
		ans += treeNum[x];
		x -= x&(-x);
	}
	return ans;
}

void Add(vector<int>& treeNum, int x, int val, int max)
{
	while(x <= max) {
		treeNum[x] += val;
		x += lowBit(x);
	}
}

vector<int> countSmaller(vector<int>& nums) {
	if (nums.empty()) {
		return vector<int>();
	}
	vector<int> sortedNum(nums);
	map<int, int> rankMap;
	sort(sortedNum.begin(), sortedNum.end());
	int index = 1;
	int lastNum = sortedNum[0];
	for (auto num: sortedNum) {
		if (lastNum != num) {
			index++;
			lastNum = num;
		}
		rankMap[num] = index;
	}
	vector<int> treeNum(index + 1, 0);
	vector<int> results;
	for (int i = nums.size() -1 ; i >=0; i--) {
		int result = Read(treeNum, rankMap[nums[i]] - 1);
		results.insert(results.begin(), result);
		Add(treeNum, rankMap[nums[i]], 1, index);
	}
	return results;
}
};
```