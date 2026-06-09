第一反应就是**动态规划**。

**1. 从左上到右下去考虑(错误的想法))**
这题卡在从左上角往右下角做动态规划了，看错在第41个测试案例就知道肯定是算法有问题了。。。后来想清楚了，如果你从左上角往右下角做动态规划，你必须要两个数组
```
//最小最初生命值
vector<vector<int>> dp (row,vector<int>(column));
//当前生命值
vector<vector<int>> hp (row,vector<int>(column));
```
这就有一个尴尬的地方，动态规划应该只用一个dp，为了算法要多一个hp，你在取舍是左到右还是上到下的时候，你第一反应是哪个dp小取哪个，但是有可能hp也会对判断造成干扰
```
[[1,-3,3],[0,-2,0],[-3,-3,-3]]
```
倘若只看两行的话，必然是只用2，但是这样子涉及到第三行出来的结果就是5，而不是正确答案3，这就是hp影响到了判断的一个特殊情况，虽然可能当前到某个格子时，你选择的路线是所需要的起始血量最小的，但是有可能有另一条路线所需要的起始血量只是比你选择的路线血量略高一点，但是那条路线的hp就高出很多，这时候就没有办法去判断。 

以下是错误代码(卡在第41个测试案例)
```
class Solution {
public:
int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
	int row=dungeon.size(),column=dungeon.at(0).size();
	//最小最初生命值
	vector<vector<int>> dp (row,vector<int>(column));//TODO:把初始值去掉
	//当前生命值
	vector<vector<int>> hp (row,vector<int>(column));
	if (dungeon.at(0).at(0)<0)
	{
		hp.at(0).at(0)=1;
		dp.at(0).at(0)=1-dungeon.at(0).at(0);
	}
	else
	{
		dp.at(0).at(0)=1;
		hp.at(0).at(0)=1+dungeon.at(0).at(0);
	}
	for (int i=1;i<column;++i)
	{
		hp.at(0).at(i)=hp.at(0).at(i-1)+dungeon.at(0).at(i);
		if (hp.at(0).at(i)>0)
			dp.at(0).at(i)=dp.at(0).at(i-1);
		else
		{
			dp.at(0).at(i)=dp.at(0).at(i-1)+1-hp.at(0).at(i);
			hp.at(0).at(i)=1;
		}
	}
	for (int i=1;i<row;++i)
	{
		hp.at(i).at(0)=hp.at(i-1).at(0)+dungeon.at(i).at(0);
		if (hp.at(i).at(0)>0)
			dp.at(i).at(0)=dp.at(i-1).at(0);
		else
		{
			dp.at(i).at(0)=dp.at(i-1).at(0)+1-hp.at(i).at(0);
			hp.at(i).at(0)=1;
		}
	}
	int dp_right,hp_right,dp_down,hp_down;
	for (int i=1;i<row;++i)
		for (int j=1;j<column;++j)
		{
			hp_right=hp.at(i).at(j-1)+dungeon.at(i).at(j);
			if (hp_right>0)
				dp_right=dp.at(i).at(j-1);
			else
			{
				dp_right=dp.at(i).at(j-1)+1-hp_right;
				hp_right=1;
			}
			hp_down=hp.at(i-1).at(j)+dungeon.at(i).at(j);
			if (hp_down>0)
				dp_down=dp.at(i-1).at(j);
			else
			{
				dp_down=dp.at(i-1).at(j)+1-hp_down;
				hp_down=1;
			}
			if (dp_right<dp_down)
			{
				dp.at(i).at(j)=dp_right;
				hp.at(i).at(j)=hp_right;
			}
			else if (dp_right>dp_down)
			{
				dp.at(i).at(j)=dp_down;
				hp.at(i).at(j)=hp_down;
			}
			else
			{
				//dp.at(i).at(j)=dp_down;
				dp.at(i).at(j)=dp_right;
				hp.at(i).at(j)=max(hp_right,hp_down);
			}
		}
	return dp.at(row-1).at(column-1);
}
};
```


***所以要换一种方法，只能存在一个数组dp的算法，所以就用到了从右下角到左上角反过来的动态规划***

**2. 我们用从右下到左上反过来动态规划**
这样子只需要一个数组
```
//当前格子到达公主需要的最小生命值
vector<vector<int>> dp (row,vector<int>(column));
```
注意的是血量最小为1，所以如果出现计算出<=0的情况就都要赋值为1
动态方程
dp.at(i).at(j)=min(dp.at(i+1).at(j)-dungeon.at(i).at(j),dp.at(i).at(j+1)-dungeon.at(i).at(j));

代码(AC)
```
class Solution {
public:
int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
	int row=dungeon.size(),column=dungeon.at(0).size();
	//当前格子到达公主需要的最小生命值
	vector<vector<int>> dp (row,vector<int>(column));
	dp.at(row-1).at(column-1)=dungeon.at(row-1).at(column-1)<0?1-dungeon.at(row-1).at(column-1):1;
    for (int i=row-2;i>=0;--i)
    {
        dp.at(i).at(column-1)=dp.at(i+1).at(column-1)-dungeon.at(i).at(column-1);
        if (dp.at(i).at(column-1)<=0)
            dp.at(i).at(column-1)=1;
    }
    for (int i=column-2;i>=0;--i)
    {
        dp.at(row-1).at(i)=dp.at(row-1).at(i+1)-dungeon.at(row-1).at(i);
        if (dp.at(row-1).at(i)<=0)
            dp.at(row-1).at(i)=1;
    }
    for (int i=row-2;i>=0;--i)
        for (int j=column-2;j>=0;--j)
        {
            dp.at(i).at(j)=min(dp.at(i+1).at(j)-dungeon.at(i).at(j),dp.at(i).at(j+1)-dungeon.at(i).at(j));
            if (dp.at(i).at(j)<=0)
                dp.at(i).at(j)=1;
        }
	return dp.at(0).at(0);
}
};
```

如果有不懂可以评论问我
觉得还行的可以去[个人github仓库](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution)给个星星哦
