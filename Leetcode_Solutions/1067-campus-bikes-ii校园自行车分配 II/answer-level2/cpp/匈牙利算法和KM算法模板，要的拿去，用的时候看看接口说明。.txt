暂时没发现bug，如果有bug的话希望能反馈一下，谢谢。
我刷题还总结了一些其他的算法模板和数据结构模板，要的私聊，毕竟重复的轮子复制粘贴有助于提高效率。
```
class Hungarian
{
	/* 接口说明 ：
	前提:二分图 ：|Y|>=|X|

	Hungarian_match(Boys,Girls,love)
	|Y|=Boys
	|X|=Girls
	返回最大匹配数
	love是用领接表表示的图 love[u]={v1,v2,v3} u 是Y中的点， {v1,v2,v3}是 X 中点，表示u有三个邻接点 
	重点：节点编号都是从0开始 ,0<=u<=|Y|-1  , 0<=v<=|X|

	get_match()
	返回匹配结果：match[x]=y表示 x的匹配对象是y


	int Hungarian_best_match(vector<vector<int>>&love)//用邻接矩阵表示的图 主要是有权值的话，矩阵方便，两个点没有边的话，权值请用INT_MAX 或 INT_MIN 表示
	|Y|=love.size();
	|X|=love[0].size();
	返回权值最大匹配
	如果想要返回权值最小匹配，输入的权值矩阵权值全部取反,同时对返回结果也取反就是最小匹配了。

	get_match()
	返回匹配结果：match[y]=x表示 y的匹配对象是x ，match[y]==-1 表示y没有匹配对象
	*/
public:
	int Hungarian_match(int Boys,int Girls,vector<vector<int>>&love)//输入连个点集 另一个是从X 到Y的所有边 |X|>=|Y|    目的是给所有的Y尽可能匹配对象
	{//没有权值的用邻接表表示
		match.resize(Girls, -1);
		visited_girl.resize(Girls);
		int match_cnt = 0;
		for (int b = 0; b < Boys; b++)
		{
			visited_girl.assign(Girls, false);
			match_cnt += find_cross_path(b, love);
		}
		return match_cnt;//最大匹配数
	}
	int Hungarian_best_match(vector<vector<int>>&love)//如果两个节点之间没有边，weight=INT_MIN love 为两人之间的好感度
	{
		int Boys = love.size();
		int Girls = love[0].size();
		ex_girl.resize(Girls, 0);
		ex_boy.resize(Boys, 0);

		visited_girl.resize(Girls);
		visited_boy.resize(Boys);

		gap.resize(Boys);
		match.resize(Boys, -1);

		for (int g = 0; g < Girls; g++)
		{
			gap.assign(Boys, INT_MAX);
			while (true)
			{
				visited_boy.assign(Boys, false);
				visited_girl.assign(Girls, false);
				if (find_cross_path_in_equal_subgraph(g, love))
					break;
				int min_gap = INT_MAX;
				for (int b = 0; b < Boys; b++)
				{
					if (!visited_boy[b])
						min_gap = min(min_gap, gap[b]);
				}
				for (int g = 0; g < Girls; g++)
				{
					if (visited_girl[g])
						ex_girl[g] -= min_gap;
				}
				for (int b = 0; b < Boys; b++)
				{
					if (visited_boy[b])
						ex_boy[b] += min_gap;
					else
						gap[b] -= min_gap;
				}
			}
		}
		int best_match = 0;
		for (int b = 0; b < Boys; b++)
		{
			if (match[b] != -1)//并不是所有男生都有女友
				best_match += love[b][match[b]];
		}
		return best_match;
	}
	vector<int>get_match()
	{
		return match;
	}
private:
	vector<int>ex_girl;// expect 期望值
	vector<int>ex_boy;
	vector<bool>visited_boy;
	vector<bool>visited_girl;
	vector<int>match;//match[b]=g 表示 b 的女友是 g
	vector<int>gap;
	bool find_cross_path(int b, vector<vector<int>>&love)//love[b]={g1,g2}表示b有好感的女生有g1，g2
	{
		for (auto g : love[b])
		{
			if (!visited_girl[g])
			{
				visited_girl[g] = true;
				if (match[g] == -1 || find_cross_path(match[g], love))
				{
					match[g] = b;
					return true;
				}
			}
		}
		return false;
	}
	bool find_cross_path_in_equal_subgraph(int g, vector<vector<int>>&love)
	{
		int Boys = love.size();
		visited_girl[g] = true;
		for (int b = 0; b < Boys; b++)
		{
			if (love[b][g] > INT_MIN||love[b][g]<INT_MAX)//两人之间有好感度
			{
				if (visited_boy[b])
					continue;
				int cur_gap = ex_girl[g] + ex_boy[b] - love[b][g];
				if (cur_gap == 0)
				{
					visited_boy[b] = true;
					if (match[b] == -1 || find_cross_path_in_equal_subgraph(match[b], love))
					{
						match[b] = g;
						return true;
					}
				}
				else
				{
					gap[b] = min(gap[b], cur_gap);
				}
			}
		}
		return false;
	}
};
```
