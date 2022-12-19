### 解题思路
![1577356935(1).jpg](https://pic.leetcode-cn.com/a27d852cc9851a1de5f1a8310b514b11d160e013b2267541fe2661c281b48415-1577356935\(1\).jpg)
利用Map的特性 记录每个数字出现的次数 然后再最后遍历map 每个键对于的值（就是出现的次数） 是否大于 长度/3

### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
   int size = nums.size();
	map<int, int> Mpas;
	vector<int> res;
	if (!size) return res;
	if (size == 1)   return nums;
	for (int i = 0; i < size; i++)
	{
		auto iter = Mpas.find(nums[i]);
		if (iter == Mpas.end())
		{
			Mpas.insert(pair<int, int>(nums[i], 1));
		}
		else {
			Mpas[nums[i]] += 1;
		}
	}
	for (map<int, int>::iterator i = Mpas.begin(); i != Mpas.end(); i++)
	{
		if(i->second > (size / 3)) res.push_back(i->first);
	}

	return res;
    }
};
```