#  求众数
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

```
输入: [3,2,3]
输出: 3
```

示例 2:

```
输入: [2,2,1,1,1,2,2]
输出: 2
```

<hr>

##  解法1：排序的方法

```
class Solution {
public:
	static bool cmp(const int &a, const int &b)
	{
		return a < b;
	}
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++)
		{
			int count = i;//起始位置
			while (i < nums.size() - 1)
			{
				if (nums[i] == nums[i + 1])
					i++;
				else break;
			}
			count = i - count + 1;//计算数目
			if (count > floor(nums.size() / 2))
				return nums[i];
		}
		return 0;
	}
};
```
写完以后发现这个方法好笨，既然排序了，又存在众数，说明众数一定会在中间的位置

##  优化：

```
class Solution {
public:
	static bool cmp(const int &a, const int &b)
	{
		return a < b;
	}
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		return nums[nums.size()/2];
	}
};
```

##  解法2：
从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(res==nums[i])
                count++;
            else
            {
                count--;
                if(count==0)
                    res=nums[i+1];
            }
        }
        return res;
    }
};
```

