### 解题思路
我的程序耗时和内存都不是最好的，但是想法比较简单。首先需要将组别为-1的项目都创建一个新组，该组只有它本身。接下来要确定组别之间的优先级和组内的优先级，先遍历beforeItems数组，对于
beforeItems[i][j],i和j为项目，若i和j属于同组，则可以确定组内优先级关系，若i和j不同组，则可以确定小组之间优先级关系，接下来先对每个组进行拓扑排序，再对不同组进行拓扑排序。
![image.png](https://pic.leetcode-cn.com/56571eee9be9c690e1b4efdbd32881abe03c9662850383594ccd2a8569d4c8b2-image.png)


### 代码

```cpp
class Solution {
public:
struct tpnod//拓扑排序的节点结构体声明
{
	vector<int>next1;//组外的优先级比该节点小的节点索引，维护不同的小组排序后的优先级关系
	vector<int>ingnext;//组内的优先级比该节点小的节点索引，维护同一小组的任务排序后的优先级关系
	int deg = 0;//不同组间的在完成该节点之前需要完成的任务数
	int igdeg = 0;//组内的在完成该节点之前需要完成的任务数
};
tpnod nos[30001];
tpnod itogroup[30001];//小组的数组，每个单元都是一个小组，可能不只m个，因为新创建了一些小组，但一定不会超过30000；
vector<int>grouptoi[30001];//维护同一个组的项目
vector<int>ingroup[30001];//维护同一组的不同项目之间的顺序

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
	int numOfG = m;//numOfG为包括创建的新组的组数
	vector<int>res;
	for (int i = 0; i < group.size(); i++)
	{
		if (group[i] != -1)
			grouptoi[group[i]].push_back(i);
		else//否则创建新组
		{
			grouptoi[numOfG].push_back(i);
			group[i] = numOfG;
			numOfG++;//创建后加一
		}
	}
	for (int i = 0; i < beforeItems.size(); i++)
	{
		for (int j = 0; j < beforeItems[i].size(); j++)
		{
			if (group[beforeItems[i][j]] == group[i])//在同一组就看作组内项目优先级关系
				nos[i].igdeg++, nos[beforeItems[i][j]].next1.push_back(i);
			else itogroup[group[i]].deg++,//在不同组就看作组之间的优先级关系，因为同组的肯定是聚在一起的
				itogroup[group[beforeItems[i][j]]].next1.push_back(group[i]);
		}
	}
	for (int i = 0; i < numOfG; i++)//确定不同小组组内项目优先级顺序
	{
		queue<int>q;
		for (int j = 0; j < grouptoi[i].size(); j++)
		{
			if (nos[grouptoi[i][j]].igdeg == 0)
				q.push(grouptoi[i][j]);
		}
		int cnt2 = 0;
		while (!q.empty())
		{
			cnt2++;
			int tp2 = q.front();
			ingroup[i].push_back(tp2);
			q.pop();
			for (int j = 0; j < nos[tp2].next1.size(); j++)
			{
				nos[nos[tp2].next1[j]].igdeg--;
				if (nos[nos[tp2].next1[j]].igdeg == 0)//在该节点之前的工作处理完了就把该节点放入队列
					q.push(nos[tp2].next1[j]);
			}
		}
		if (cnt2 != grouptoi[i].size())//判断是否矛盾
		{
			return res;//res此时为空
		}
	}
	queue<int>q;
	for (int i = 0; i < numOfG; i++)
		if (itogroup[i].deg == 0)
			q.push(i);
	int cnt3 = 0;
	int tp7;
	vector<int>grorder;
	while (!q.empty())//之前已经处理好了不同小组优先级关系，现在开始确定不同小组的顺序。
	{
		tp7 = q.front();
		grorder.push_back(tp7);
		q.pop();
		cnt3++;
		for (int i = 0; i < itogroup[tp7].next1.size(); i++)
		{
			(itogroup[itogroup[tp7].next1[i]].deg)--;
			if (itogroup[itogroup[tp7].next1[i]].deg == 0)
				q.push(itogroup[tp7].next1[i]);
		}
	}
	if (cnt3 != numOfG)//判断是否矛盾
	{
		return res;//res此时为空
	}
	for (int i = 0; i < numOfG; i++)
	{
		for (int j = 0; j < ingroup[grorder[i]].size(); j++)
			res.push_back(ingroup[grorder[i]][j]);// , cout << ingroup[grorder[i]][j] << " ";
	}
	return res;
    }
};
```