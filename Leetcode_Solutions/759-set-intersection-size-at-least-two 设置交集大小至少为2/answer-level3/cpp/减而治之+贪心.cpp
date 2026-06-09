一开始算法只能击败20%，经修改后可以击败100%，然鹅在LeetCode美国站下仍然只有52.44%......
题目要求使得所有区间都至少与S有两个相交，那么可以考虑降低问题的规模，也就是说这些区间里，有可能一部分是另外一部分的子区间，只要满足子区间，就可以满足大的区间，要寻找这些区间，可以先对数据进行排序，排序的规则是首先比较两个区间的起始位置，小的排前边，若出现二者相等，则比较终止位置，同样是小的排前边。这样排序后，除非两个区间完全相同，否则排在前边的区间一定不是后边区间的子区间，而排在后边的区间有可能是前边的子区间。我们倒着对整个数据intervals进行筛选，筛选出最终需要进行计算的区间small。
问题规模缩小后，观察剩余的区间，无非就是有交集和无交集，由于我们希望集合S的元素尽可能少，也就是希望多个区间共用一些元素，这样的话，我们可以采取贪心策略，每次都取区间最后的一个或两个元素，这样下一个区间甚至是下下个区间就可以共用这些元素了。这样在遍历每一个区间时，就要先查看是否有本区间内的元素已经在S中了，若有则跳过，若没有则根据贪心策略将区间末尾的元素加入S。本例采用map进行计数，每次遍历区间均要循环遍历该map，也是因为这个才会大量耗时，应该可以使用数组或者直接记录最后一次取的元素值来降低时间复杂度。
```
bool Compare(vector<int>&a, vector<int>&b)
{
	if (a[0] < b[0])
		return true;
	else if (a[0] == b[0])
	{
		if (a[1] < b[1])
		{
			return true;
		}
		return false;
	}
	return false;
}
/*
1:前者包含后者  a1..a2..b2..b1
2:后者包含前者  a2..a1..b1..b2
3:没有包含关系  
*/
int isSub(int a1,int b1,int a2,int b2)
{
	int result = 3;
	if (a1 <= a2&&b1 >= b2)
	{
		result = 1;
	}
	else if (a2 <= a1&&b2 >= b1)
	{
		result = 2;
	}
	return result;
}

int intersectionSizeTwo(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end(), Compare);
	int n = intervals.size();
	int last = n-1;
	vector<vector<int>> small;
	small.push_back(intervals[last]);
	for (int i = n-2; i >= 0; i--)
	{
		int flag = isSub(intervals[last][0], intervals[last][1], intervals[i][0], intervals[i][1]);
		if (flag == 3)			//无包含关系
		{
			small.push_back(intervals[i]);
			last = i;
		}
		else if (flag == 1)		//当前区间小于上次区间
		{
			small.pop_back();
			small.push_back(intervals[i]);
			last = i;
		}
	}
	n = small.size();
	map<int,int> m;
	
	for (int i = n - 1; i >= 0;i--)
	{
		int num = 0;		//已经有的值
		for (auto itor = m.begin(); itor != m.end(); itor++)
		{
			if (itor->first < small[i][0])			//小于当前区间
			{
				continue;
			}
			else if (itor->first > small[i][1])		//大于当前区间
			{
				break;
			}
			else
			{
				num++;
				if (num == 2)						//如果已经有两个了
				{
					break;
				}
			}
		}
		if (num == 0)								//选择最后两个
		{
			m[small[i][1]] = 1;
			m[small[i][1] - 1] = 1;
		}
		else if (num == 1)							//选择最后一个
		{
			m[small[i][1]] = 1;
		}
	}
	return m.size();
}
```
按照上述思路进行修改，只保存最后两个加入S的元素，算法运行速度提升很明显，击败了100%的用户。

![微信截图_20190609215837.jpg](https://pic.leetcode-cn.com/dc21676dc1e5ebae591201c59d819edebc5e167dfdd7be06817d6ba2a10e9067-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190609215837.jpg)
修改部分如下：
```
int intersectionSizeTwo(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end(), Compare);
	int n = intervals.size();
	int last = n-1;
	vector<vector<int>> small;
	small.push_back(intervals[last]);
	for (int i = n-2; i >= 0; i--)
	{
		int flag = isSub(intervals[last][0], intervals[last][1], intervals[i][0], intervals[i][1]);
		if (flag == 3)			//无包含关系
		{
			small.push_back(intervals[i]);
			last = i;
		}
		else if (flag == 1)		//当前区间小于上次区间
		{
			small.pop_back();
			small.push_back(intervals[i]);
			last = i;
		}
	}
	n = small.size();
	queue<int> S;
	
	int lastone = small[n-1][1], beforelastone = small[n - 1][1] -1;			//记录最后一个和倒数第二个选入S的元素
	S.push(lastone);
	S.push(beforelastone);														

	for (int i = n - 2; i >= 0;i--)
	{
		if (lastone >= small[i][0] && beforelastone < small[i][0])
		{
			beforelastone = lastone;
			lastone = small[i][1];
			S.push(lastone);
		}
		else if (lastone < small[i][0])
		{
			beforelastone = small[i][1] - 1;
			lastone = small[i][1];
			S.push(lastone);
			S.push(beforelastone);
		}
	}
	return S.size();
}
```
