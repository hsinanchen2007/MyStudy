### 解题思路
太久不用hash表，有些手生。
常用的哈希表一般用map或者二维数组实现。
map的话直接用键值可以索引每一个元素，更为方便。
使用二维数组实现的话，这里用的是vector<pair<int,int> >hashlist[10005];
哈希表的第一维用于索引要查询数据到限定范围，通过哈希函数分割数组中各个值，使其均匀分布。在索引到的第二维数组列表中具体查找是否存在要索引的确切值。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   		vector<int>ans;
		vector<pair<int,int> >hashlist[10005];
		
		for(int i = 0;i < nums.size();i++)
		{
			int b = target - nums[i];
			int hashsize = (b + 10005) % 10005;
			if(hashlist[hashsize].size() != 0)
			{
				for(int j = 0;j < hashlist[hashsize].size();j++)
					if(hashlist[hashsize][j].first == b){
					ans.push_back(hashlist[hashsize][j].second);
					ans.push_back(i);
					return ans;
				}
			}
			hashsize = (nums[i] + 10005) % 10005;
			pair<int,int>a;
			a.first = nums[i];
			a.second = i;
			hashlist[hashsize].push_back(a);
		}
	return ans;
    }

};
```