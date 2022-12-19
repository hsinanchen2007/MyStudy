#  模拟行走机器人
机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：

-2：向左转 90 度
-1：向右转 90 度
1 <= x <= 9：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物。

第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])

如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。

返回从原点到机器人的**最大欧式距离的平方**。

 

示例 1：

```
输入: commands = [4,-1,3], obstacles = []
输出: 25
解释: 机器人将会到达 (3, 4)
```

示例 2：

```
输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
输出: 65
解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
```

<hr>

##  解：
思路：
- 用变量a标志方向，北0 东1 南2 西3
- 用变量flag判断是否被障碍物挡住，挡住为true，未挡住为false，初始为false
- 当前进时，找到离得最近的障碍物，并判断是否会撞上障碍物，不会则前进，会则在障碍物前停住，并更改flag为true。直到commands的操作为转向才继续前进
- 每次前进动态更新欧式距离 maxn=x^2^+y^2^;
```
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int a = 0;//方向
		int x = 0;//机器人的x坐标
		int y = 0;机器人的y坐标
		int maxn = 0;//最大欧式距离
        int mindes;//最近的障碍物某一坐标
        bool flag=false;//标志是否被障碍物挡住
		for (int i = 0; i < commands.size(); i++)
		{
            if(flag && commands[i]!=-1 && commands[i]!=-2)//被障碍物挡住，停止前进
                continue;
			if (commands[i] == -1)
			{
				a = (a + 1) % 4;
                flag=false;
				continue;
			}
			if (commands[i] == -2)
			{
				a = (a + 3) % 4;
                flag=false;
				continue;
			}
			int k = 0;
			if (a == 0)//北方向
			{
                mindes=INT_MAX;
				for (; k < obstacles.size(); k++)
				{
					if (obstacles[k][0] == x && obstacles[k][1]>y)
                    {
                        mindes=min(mindes,obstacles[k][1]);
                    }
				}
				if (mindes!=INT_MAX)
				{
					if (mindes > (y + commands[i]))
						y += commands[i];
					else
					{
						y = mindes - 1;
                        flag=true;
					}
				}
				else y += commands[i];
				maxn = max(maxn, x*x + y * y);
				continue;
			}
			if (a == 1)//东方向
			{
                mindes=INT_MAX;
				for (; k < obstacles.size(); k++)
				{
					if (obstacles[k][1] == y && obstacles[k][0]>x)
                    {
                        mindes=min(mindes,obstacles[k][0]);
                    }
				}
				if (mindes!=INT_MAX)
				{
					if (mindes > (x + commands[i]))
						x += commands[i];
					else
					{
						x = mindes - 1;
                        flag=true;
					}
				}
				else x += commands[i];
				maxn = max(maxn, x*x + y * y);
				continue;
			}
			if (a == 2)//南方向
			{
                mindes=INT_MIN;
				for (; k < obstacles.size(); k++)
				{
					if (obstacles[k][0] == x && obstacles[k][1]<y)
					{
                        mindes=max(mindes,obstacles[k][1]);
                    }
				}
				if (mindes!=INT_MIN)
				{
					if (mindes < (y - commands[i]))
						y -= commands[i];
					else
					{
						y = mindes + 1;
                        flag=true;
					}
				}
				else y -= commands[i];
				maxn = max(maxn, x*x + y * y);
				continue;
			}
			if (a == 3)//西方向
			{
                mindes=INT_MIN;
				for (; k < obstacles.size(); k++)
				{
					if (obstacles[k][1] == y && obstacles[k][0]<x)
					{
                        mindes=max(mindes,obstacles[k][0]);
                    }
				}
				if (mindes!=INT_MIN)
				{
					if (mindes < (x - commands[i]))
						x -= commands[i];
					else
					{
						x = mindes + 1;
                        flag=true;
					}
				}
				else x -= commands[i];
				maxn = max(maxn, x*x + y * y);
				continue;
			}
		}
		return maxn;
	}
};
```
该代码主要是在查找障碍物花的时间较长。

##  优化：用set集合加快查找速度

```
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        //每个方向前进时的坐标增量
        int x = 0, y = 0；//机器人的坐标
        int di = 0;//方向 北0 东1 南2 西3

        set<pair<int,int>> obstacleSet;//存放障碍物的集合
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

        int ans = 0;//最大欧式距离
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }
};
```

