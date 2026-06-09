其实这道题机器人走的路线长度就是其当前坐标x和y的值的和，如果大家学过一些几何知识，知道L1平面的话就很好理解了。因为机器人永远不会走回头路，其实每次走的距离是command的长度。
也就是说x + y在每一回合后增加lengthOfCommand个数值。这样就可以利用这个知道如果要走到目标，会在第几回合走到，再一步步去分析看看能不能走到终点。

在得知终点在我们的路径上时，我们在分析障碍物是否在路径上就可以了。需要提醒的是，因为我们不会碰到比终点更远的障碍物，所以我们只需要分析坐标和小于终点坐标和的障碍物即可。

```
class Solution {
public:
   bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		int commandLength = command.length();
		const char* pt = command.c_str();
		int positionX(0), positionY(0);

		int numOfU(0), numOfR(0);

		for (int i = 0; i < commandLength; ++i)
		{
			if (pt[i] == 'U') numOfU++;
			else if (pt[i] == 'R') numOfR++;
		}
		bool isTargetOnPath = isPointOnPath(x, y, pt, commandLength, numOfU, numOfR);
		if (!isTargetOnPath) return false;
		int obSize = obstacles.size();
		int targetLength = x + y;
		for (int i = 0; i < obSize; ++i)
		{
			if (obstacles[i][0] + obstacles[i][1] < targetLength)
			{
				if (isPointOnPath(obstacles[i][0], obstacles[i][1], pt, commandLength, numOfU, numOfR))
				{
					return false;
				}
			}
		}
		return true;


	}

	bool isPointOnPath(int x, int y, const char* command, int lengthOfCommand, int numOfU, int numOfR)
	{
		int numOfRound = (x + y) / lengthOfCommand;
		int startX = numOfRound * numOfR;
		int startY = numOfRound * numOfU;

		for (int i = 0; i < lengthOfCommand; ++i)
		{
            if (x == startX && y == startY) return true;
			if (command[i] == 'U') startY++;
			else if (command[i] == 'R') startX++;			
		}
		return false;
	}
};
```
