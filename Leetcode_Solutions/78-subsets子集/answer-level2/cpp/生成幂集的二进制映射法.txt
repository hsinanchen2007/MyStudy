### 解题思路
本题仅需要利用幂集和二进制的一一对应关系，即建立幂集下标和二进制值的一一映射：
当下标的二进制值第i位为1，则代表该子集包含原集合的第i个元素，
这样，只需要枚举所有的二进制值，每次循环按位取与判断该子集所含1的位置，即可知道该子集
所含的原集合元素

### 代码

```cpp
class Solution {
public:
  
   vector<int> subset(vector<int>& nums, int i)
{
	vector<int> temp;
	int numsize = nums.size();
	for (int j = 0; j < numsize; j++)
	{
		if (i & (1 << j))
			temp.push_back(nums[j]);
	}
	return temp;
}

    vector<vector<int>> subsets(vector<int>& nums) {
        int numsize = nums.size();
	    vector<vector<int>> sets;
	    for(int i=0;i<(1<<numsize);i++)
		   sets.push_back(subset(nums, i));
        return sets;
    }
};
```