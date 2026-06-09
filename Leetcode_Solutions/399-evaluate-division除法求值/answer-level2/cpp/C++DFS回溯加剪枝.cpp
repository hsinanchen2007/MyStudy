执行用时 :4 ms, 在所有 C++ 提交中击败了92.22%的用户
内存消耗 :10.5 MB, 在所有 C++ 提交中击败了15.63%的用户
//出现的字符串作为一个顶点在图的顶点中单独顶点存储权值1.0,由给定的两个顶点之间的关系做边，如a/b=2.0
//ans[a][a]=1.0,ans[b][b]=1.0,ans[a][b]=2.0,ans[b][a]=1/2.0,没有直接联系的两个顶点只要构成一个连通分量就可求解：如已知//a/b,b/c,则a/c=a到c上路径权值的乘积

`class Solution {
public:
   bool mark = false;
int findvertax(vector<string>vertax, string s)
{
	for (int i = 0;i < vertax.size();i++)
	{
		if (vertax[i] == s)
			return i;//在顶点集中查找有无顶点，有则返回数组下标
	}
	return -1;
}
void DFS(vector<vector<double>>G, int x, int y, vector<bool>&visted, vector<int>&result)
{//通过DFS找到这条路径
	int i = 0;
	visted[x] = true;
	result.push_back(x);
	for ( i = 0;i < G.size();i++)
	{
		if (mark == true)
		{//找到终点回溯（剪枝）
			break;
		}
		if (x != i && G[x][i] != -1.0&&visted[i] != true)
		{
			if (i == y)
			{
				mark = true;
			}
			DFS(G, i, y, visted, result);
		}
	}
	if (mark != true)
		result.pop_back();
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	vector<double>ans;
	vector<string>vertax;
	int n = equations.size(), i = 0,j=0, index = 0;
	for (i = 0;i < n;i++)
	{
		if (findvertax(vertax, equations[i][0]) == -1)
			vertax.push_back(equations[i][0]);
		if (findvertax(vertax, equations[i][1]) == -1)
			vertax.push_back(equations[i][1]);
	}//确定顶点集
	//建图
	int m = vertax.size(), a = 0, b = 0;
	double num = 1.0;
	vector<bool>visted(m, false);//DFS作为访问数组
	vector<vector<double>>G(m, vector<double>(m, -1.0));
	vector<int>result;
	for (i = 0;i < n;i++)
	{
		a = findvertax(vertax, equations[i][0]);
		b = findvertax(vertax, equations[i][1]);
		G[a][a] = 1.0;
		G[b][b] = 1.0;
		G[a][b] = values[i];
		G[b][a] = 1 / values[i];
	}
	for (i = 0;i < queries.size();i++)
	{
				num = 1.0;
				mark = false;
				for (j = 0;j < visted.size();j++)
				{
					visted[j] = false;
				}
				result.clear();
				a = findvertax(vertax, queries[i][0]);
				b = findvertax(vertax, queries[i][1]);
				if (a == -1 || b == -1)
				{
					ans.push_back(-1.0);
					continue;
				}
				if (a != -1 && b != -1 && a == b)
				{
					ans.push_back(1.0);
					continue;
				}
				DFS(G, a, b, visted, result);
        if(result.empty())
        {
            ans.push_back(-1.0);
            continue;
        }
				for (index= 0;index < result.size()-1;index++)
				{
					num *= G[result[index]][result[index+1]] ;
				}
				ans.push_back(num);
	}
	return ans;
}
};`