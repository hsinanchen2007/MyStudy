### 解题思路


### 代码

```cpp
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		unordered_map<int, int> hashMap(nums.size());//需要初始化大小
		for (vector<int>::iterator it=nums.begin();it!=nums.end();it++)
		{
			if (hashMap.find(*it)==hashMap.end())//如果该数字不存在
			{
				hashMap[*it] = 1;
			}
			else//存在该数字,则直接返回
			{
				return *it;
			}
		}
		return -1;//这里不能省略，否则会编译出错
	}
};
```