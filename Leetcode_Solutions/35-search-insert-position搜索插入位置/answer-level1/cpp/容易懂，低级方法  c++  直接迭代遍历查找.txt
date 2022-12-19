### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=0;
        //如果排序数组中有目标值就直接返回    迭代遍历数组（也可以二分查找加快速度）		
		for(vector<int>::iterator it = nums.begin();it != nums.end();it++)  
		{
			if((*it) == target) 
			{
				return index;
			}
			index++;
		}
        //排序数组中不存在目标值
        /*
        1、先添加目标值到数组，然后重新排序
        2、迭代遍历数组然后直接返回（也可以二分查找加快速度）
        */
		nums.push_back(target);  //后插入
		sort(nums.begin(),nums.end());  //从小到大排序
		index = 0;
		for(vector<int>::iterator its = nums.begin();its != nums.end();its++)
		{
			if((*its) == target)
			{
				return index;
			}
			index++;
		}
		return 0;
    }
};
```