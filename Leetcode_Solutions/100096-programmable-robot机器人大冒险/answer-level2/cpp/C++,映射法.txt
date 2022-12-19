平时嵌入式做的多，上来直接按照每一步行走后判断是否到终点或者障碍。。
发现超时了。。。。
planB:把路径全求出来，再把障碍物一个个来判断是否在路径上。。依然超时。
planC：发现机器人的路径是循环的，就如象棋里面的马走日一样。那是不是可以把那些障碍物和终点（他们可能会很远很远）都映射到这一小段路径中？
路径的长度就是指令的长度，也大大减少了查表的时间。
以下为代码（有点乱。。）

class Solution {
public:
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		final = vector<int>{ x,y };
		for(int i=0;i<command.length();i++)
		{
			take_next_move(command, i);
		}
		if (!ispath(final))//判断终点是否在路径
			return false;
		while (!obstacles.empty())//判断障碍是否在路径
		{
			vector<int> ob = obstacles.back();
			obstacles.pop_back();
			if (ob[0] > x || ob[1] > y)
				continue;
			if (ispath(ob))
				return false;
		}
		return true;
	}
private:
	bool move=1;
	vector<int> pos = vector<int>{0,0};
	vector<int> final;
	vector<vector<int>> path;
	void take_next_move(string s, int index)
	{
		path.push_back(pos);
		if (s[index] == 'U')
			pos[1]++;
		else if (s[index] == 'R')
			pos[0]++;
	}
	bool ispath(vector<int> ob)//判断该点映射后是否在路径上
	{
		int n = ob[0] / pos[0];
		ob[0] = ob[0] % pos[0];
		ob[1] = ob[1] - pos[1] * n;
		vector<vector<int>>::iterator result = find(path.begin(), path.end(), ob);
		if (result != path.end())
			return true;
		else
			return false;
	}
};