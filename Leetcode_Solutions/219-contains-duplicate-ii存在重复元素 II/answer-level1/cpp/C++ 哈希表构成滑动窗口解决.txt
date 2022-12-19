### 解题思路
利用哈希表构成滑动窗口
1、维护一个哈希表，里面始终最多包含k个元素，当出现重复值时说明k距离内存在重复元素
2、每次遍历一个元素则将其加入到哈希表中，如果哈希表的大小大于k，则移除最先添加的数字
思路参考自官方和[@guanpengchn](/u/guanpengchn/)

### 代码

```cpp
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int,int> umap;//哈希表，键为nums[i]，值为i，该hash的size为k；利用该哈希表形成一个滑动窗口
		for (int i = 0; i < nums.size(); i++)
		{
			if (umap.find(nums[i])!=umap.end())//如果hash表中能找到重复元素，说明存在
			{
				return true;
			}
			umap.insert(make_pair(nums[i],i));//向hash表中添加元素
			if (umap.size()>k)//哈希表大小超过k，则删除最旧的元素/最先添加的元素
			{
				umap.erase(nums[i - k]);
			}
		}
		return false;
	}
};
```