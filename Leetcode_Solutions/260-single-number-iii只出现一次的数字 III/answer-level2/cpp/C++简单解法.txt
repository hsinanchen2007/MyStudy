思路比较简单，既然只出现一次，那么先定义一个名为count的变量统计同一个数在整个数组中出现的次数。如果同一个数与所有的数作比较除了它自己只出现一次的话，那么就将这个数字打印出来。



```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> revec; 
	    if (nums.size() == 0)
		    return revec;
	    for (int i = 0; i<nums.size(); i++)
	    {
	    	int count = 0;
	 	for (int j = 0; j < nums.size(); j++)
		{
			if (nums[i] == nums[j])
				count++;
		}
		if (count == 1)
			revec.push_back(nums[i]);
	    }
	    return revec;
    }
};
```


