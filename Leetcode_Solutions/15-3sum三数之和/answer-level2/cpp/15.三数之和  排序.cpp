看到其他答案说这道题的重点是去重，我觉得我的想法挺简单就写一下。

两种特殊情况：
1. nums的长度小于3 直接返回[]
2. 存在[0,0,0]，则将[0,0,0]加入结果中

排序：
首先对nums数组进行排序，方便去重。

map：
将nums存储在map中，数值为键，下标为值。若有重复数字，只存储第一个出现的，其余跳过。
map用于方便查找第三个数

去重：
**先考虑前两个数是否重复**
因为按从左到右的顺序，所以只用考虑是否与上一组重复（也就是像1,1,2这种连数的情况）
也就是判断nums[i]==nums[i-1]和nums[j]==nums[j-1]
对于j要考虑:若j=i+1 那么nums[j]=nums[j-1]也是合法的
`if ((j != i + 1 && nums[j] == nums[j - 1])|| (i != 0 && nums[i] == nums[i - 1])) continue;`

**再考虑第三个数是否重复**
因为第三个数是用map的find查找的，没有一定的顺序，所以要考虑与以前每一组是否重复，而以前的组的前两个数的下标一定小于j。
也就是说，只要查找到的第三个数的下标小于j，就舍掉。
而如果相等 则说明第三个数和第二个数相等，只需判断第二个数是否有两个（或更多个，不影响结果），即只需判断nums[j+1]==nums[j]

代码如下
```
vector <int> add;
vector <vector<int> > result;
map<int, int> Find;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());//排序
        result.clear();Find.clear();//全部清除
        
        if(nums.size()<3)//特殊情况，数组长度小于3
        return result;

		int i, j, target, p;

		for (i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])//重复数字只记录第一次
				continue;
			Find.insert({ nums[i],i });
		}

		for(i=0;i<nums.size();i++)
			for (j = i + 1; j < nums.size()-1; j++)
			{
				if ((j != i + 1 && nums[j] == nums[j - 1])|| (i != 0 && nums[i] == nums[i - 1]))
					continue;

				target = 0 - nums[i] - nums[j];
				
                if(nums[i]==0&&nums[j]==0&&nums[j+1]==0)//特殊情况[0,0,0]
                {
                    add.clear();
                    add.push_back(0);add.push_back(0);add.push_back(0);
                    result.push_back(add);continue;
                }

				if (Find.find(target) != Find.end())
				{
					add.clear();
					if (Find.find(target)->second <j)
						continue;
                    if(Find.find(target)->second==j)
                        if(j+1>=nums.size()||nums[j+1]!=target)
                        continue;
                        
					add.push_back(nums[i]); add.push_back(nums[j]); add.push_back(target);sort(add.begin(),add.end());
					result.push_back(add);
				}
				else
					continue;
			}

		return result;
    }
};
```
