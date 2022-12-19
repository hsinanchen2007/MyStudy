set容器的一个特点就是当插入元素 int i 等于容器 snums 中已有的某一元素 *it 时，插入无效，容器的size不变。
根据这一特点，想到可以将nums的元素逐一插入 set 容器 snums，当插入某一元素 nums[i] 而set的 size没有增加时，可以判定 nums[i] 为重复元素。


代码如下:
```
class Solution 
{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
    set<int> snums;
	int repeatNum;
	for (int i = 0; i < nums.size(); i++)
	{
		snums.insert(nums[i]);
		if (i+1 != snums.size())
		{
			repeatNum = nums[i];
			break;
		}
	}
	return repeatNum;
    }
};
```
