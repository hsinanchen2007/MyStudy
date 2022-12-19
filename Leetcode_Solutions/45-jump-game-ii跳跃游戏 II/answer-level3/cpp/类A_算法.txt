基于贪心算法，延伸的A*算法
设初始位置为A
1. 求出位置A跳跃后可到达的位置中下一步能走的距离
2. 下一步能走的距离 加上 到达下一步位置的这个位置和初始位置A的距离
3. 如果新的>=旧的就更新
```
例子{3,2,1}
[0]为位置A
到[1]总代价为nums.at(1)+(1-初始位置即0)
到[2]总代价为nums.at(2)+(2-初始位置即0)
二者相等，但记住>=就要更新，所以选择到[2]而不是去[1]
```
代码
```
 #author: Zhenghao-Liu 
class Solution {
public:
int jump(vector<int>& nums) 
{
    int nums_size=nums.size(),jump_times=0;
	if (nums_size<=1)
		return jump_times;
	int now_position=0,max_distance,best_choice_distance,best_choice_position;
	while (now_position<nums_size-1)
	{
		max_distance=nums.at(now_position);
		if (now_position+max_distance>=nums_size-1)
			return jump_times+1;
		best_choice_distance=0;
		for (int i=1;i<=max_distance && now_position+i<nums_size;++i)
			if (best_choice_distance<=nums.at(now_position+i)+i)
				{
					best_choice_distance=nums.at(now_position+i)+i;
					best_choice_position=i;
				}
		++jump_times;
		now_position=now_position+best_choice_position;
	}
	return jump_times;
}
};
```
