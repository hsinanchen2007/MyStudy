### 解题思路
虽然耗时和内存不太理想，但是这个方法通俗易懂。我个人感觉难点在于建树，首先定义结构体Node，一开始在Node数组tree中每个节点的next列表中包含所有相连节点，接着寻找在edge中出现次数最多的树作为根，以达到压缩路径的目的，从根开始，依次对next中的所有元素进行深度优先搜索，只访问节点对应的access中为false的节点，每访问一个节点，将其对应的access数组置为true，并将next中对应access为true的节点去掉，因为其已经在前面出现过了，所以不能作为下一节点。接着再用另一个深搜函数求出每个节点到其以下所有节点的距离之和，记为distDown，并记录其以下所有节点的个数，记为descendant。根节点到根节点以下所有节点距离和distDOwn即为其到所有节点距离和dist，此外，每两个相邻节点之间的状态转移关系在代码注释有**标注。
![image.png](https://pic.leetcode-cn.com/4dc0010cb1e1dd3e4529ae3589675da01fcb12a028dea3b256f61b74353ca500-image.png)

### 代码

```cpp
class Solution {
public:
struct Node
{
	vector<int>next;
	int descendant;//后代数
	int dist;//到所有节点距离和
	int distDown;//到其下所有的节点距离和。
};
void dfs(Node*tree,int curr,int root)//求distDown,即到其所有后代距离之和。
{
	if (tree[curr].next.size() != 0)
	{
		for (int i = 0; i < (tree[curr].next).size(); i++)
			dfs(tree, (tree[curr].next)[i],root);
	}
	if (tree[curr].next.size() == 0)
	{
		tree[curr].distDown = 0;
		tree[curr].descendant = 0;
	}
	else
	{
		tree[curr].distDown = 0;
		tree[curr].descendant = 0;
		for (int i = 0; i < tree[curr].next.size(); i++)
		{
			tree[curr].distDown +=  tree[tree[curr].next[i]].descendant + 1 + tree[tree[curr].next[i]].distDown;
			tree[curr].descendant+= tree[tree[curr].next[i]].descendant + 1;
		}
	}
}
void dfs2(Node*tree, int root, int curr,int lastDis,int sizeOfTree)
{
	if (curr != root)
	{
		int dis = lastDis - tree[curr].descendant - 1 + sizeOfTree - tree[curr].descendant - 1;//**每两个节点的dist的转移关                                                                                               //系
		tree[curr].dist = dis;
	}
	else
	{
		tree[curr].dist = tree[curr].distDown;//**根节点的distDown即为dist，因为所有节点均在其下。
	}
	for (int i = 0; i < tree[curr].next.size(); i++)
		dfs2(tree, root, (tree[curr].next)[i], tree[curr].dist, sizeOfTree);
}
void dfs3(bool*access, Node*tree,int curr)
{
	vector<int>re;
	access[curr] = true;
	for (int i = 0; i < (tree[curr].next).size(); i++)
	{
		if (!access[(tree[curr].next)[i]])
		{
			re.push_back((tree[curr].next)[i]);
		}
	}
	tree[curr].next = re;
	for (int i = 0; i < tree[curr].next.size(); i++)
	{
		dfs3(access, tree, (tree[curr].next)[i]);
	}
}
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if(N==0)
        {
            vector<int>re;
            return re;
        }
        if(N==1)
        {
            vector<int>re;
            re.push_back(0);
            return re;
        }
        Node*tree = new Node[N];
	int*count = new int[N];
	int root;
	vector<vector<int>>edge = edges;
	int max = 0;
	int max_i = 0;
	for (int i = 0; i < N; i++)
		count[i] = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		count[edges[i][0]]++;
		count[edges[i][1]]++;
		if (count[edges[i][0]] > max)
		{
			max = count[edges[i][0]];
			max_i = edges[i][0];
		}
		if (count[edges[i][1]] > max)
		{
			max = count[edges[i][1]];
			max_i = edges[i][1];
		}
	}
	root = max_i;
	for (int i = 0; i < edge.size(); i++)
	{
		tree[edge[i][0]].next.push_back(edge[i][1]);
		tree[edge[i][1]].next.push_back(edge[i][0]);
	}
	bool*access = new bool[N];
	for (int i = 0; i < N; i++)access[i] = false;
	dfs3(access, tree, root);//建树
	dfs(tree, root, root);//求每个节点的distDown
	dfs2(tree, root, root, 0, N);//求每个节点到所有节点的距离
    vector<int>re;
	for (int i = 0; i < N; i++)
		re.push_back(tree[i].dist);
    return re;
    }
};
```