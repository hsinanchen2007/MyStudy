奇怪的是两种方法都是执行用时12ms，内存9.7MB，无差，均为O(N)

# 1. **由前置后**（动态规划）(推荐)
*记录下在已有n个数字的基础下，可以最多再加上几个数字，设为max_number_of_additions*
方法是遍历一次数组，
每次前进一个位置，即当前已经判断的数组包括了上一个位置了，所以最多可以加上的数字就要-1。
**对于数值不为0的位置**，更新max_number_of_additions，
(如果当前位置i，加上，最多可以加上几个数字的个数即max_number_of_additions，和大于nums_size的话必定成功可直接返回true)
**而对于数值为0的位置**，即判断此时max_number_of_additions是否为0即可，即已经不能再额外加数字了，可直接返回false

# 2.**由后置前**
*初始想法1:*
从后往前找，找到一个为0的地方，例如{···,1,0,0,2,···}，记录下当前这部分0的左右位置，然后找这块前面一个数字的最大跳跃是否能跳跃过这块0。
但是有可能例子为{···,10,1,0,0,2,···}，即前一个有可能跳不过这部分0，但是再往前面找有可能有能跳的过去的。

*改进想法2(依然有坑)*
从后往前找，找到一个为0的地方，例如{···,0,10,1,0,0,2,···}，记录下当前这部分0的左右位置，然后找这块前面的数字，直到遍历到为0为止，这一块不为0的数中的最大跳跃是否能跳跃过这块0。
但是有另外一种可能，即{···20,0,0,1,1,0,0,2,···},即可能往前找第一部分不为0的数字时跳不过去，还得往前继续找，前面有可能有一个跳跃能够一下子跳跃多个部分的0

*最终办法*
增加一个判断基准，即从后往前遍历中，当前位置下已经是成功的为1，不确定是否成功(即想法2中那种遍历了一个不为0的块没找到能够跳跃的数字，还找接着往前找的时候)为2，失败为0
最后循环完如果基准为1，即返回true，如果基准为2，即遍历完还没有找到能够跳跃的位置，即也为失败。

代码一:由前置后
```
@author: [@LZH_Yves](/u/lzh_yves/)
//由前置后
class Solution {
public:
bool canJump(vector<int>& nums)
{
	int nums_size=nums.size();
	if (nums_size<2)
		return true;
	else if (nums.at(0)==0)
		return false;
	int max_number_of_additions=0;
	for (int i=0;i<nums_size;++i)
	{
		--max_number_of_additions;
		if (nums.at(i)!=0)
		{
			max_number_of_additions=max(max_number_of_additions,nums.at(i));
			if (i+max_number_of_additions>=nums_size-1)
				return true;
		}
		else if (max_number_of_additions==0)
			return false;
	}
    //最后一个return没有任何意义
    return false;
}
};
```

代码二：由后置前
```
@author: [@LZH_Yves](/u/lzh_yves/)
//由后置前
class Solution {
public:
bool canJump(vector<int>& nums)
{
	int nums_size=nums.size();
	if (nums_size<2)
		return true;
	else if (nums.at(0)==0)
		return false;
	//judge,1:成功,2:可能成功,0:失败
	int the_empty_right,judge=1;
	for (int i=nums_size-2;i>0;--i)
		if(nums.at(i)==0)
		{
			if (judge==1)
				the_empty_right=i;
			while(i>0 && nums.at(i-1)==0)
				--i;
			judge=0;
			while(i>0 && nums.at(i-1)!=0)
			{
				--i;
				if (nums.at(i)>the_empty_right-i)
				{
					judge=1;
					break;
				}
			}
			if (judge==1)
				continue;
			else if (i>0 && nums.at(i-1)==0)
				judge=2;
		}
	if (judge!=1)
		return false;
	else
		return true;
}
};
```