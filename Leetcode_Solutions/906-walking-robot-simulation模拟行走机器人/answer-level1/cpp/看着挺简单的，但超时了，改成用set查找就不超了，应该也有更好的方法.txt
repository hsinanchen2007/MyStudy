直接一步步求位置。
三种操作，左转右转不用计算距离的平方，直走只需在该操作结束后计算距离的平方，因为一条线段上距离原点最远的点一定是两端点之一。
然而居然给我报了超时，然后就把`find(obstacles.begin(),obstacles.end(),tmp)!=obstacles.end()`改成了用set来查找，这样利用红黑树查找比直接vector中查找快了一点，终于过了。
那么问题来了，这题应该不会对数据结构要求这么高吧？是否能更加简化算法的计算步骤呢？我就算直接判断是否有障碍物在线段中间，也要对每个障碍物查找过去，在障碍物很多的时候应该反而计算步骤更多啊！有大佬解答疑惑吗？
```
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		vector<vector<int>> direction = { {0,1},{1,0},{0,-1},{-1,0} };
		int d = 0;	//当前方向的下标
		set<vector<int>> s;
		for (int i = 0; i < obstacles.size(); i++) {
			s.insert(obstacles[i]);
		}
		int max = 0, x = 0, y = 0;	//最远距离的平方，当前位置的横纵坐标
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == -1)
				d = (d + 1) % 4;	//向右转
			else if (commands[i] == -2)
				d = (d + 3) % 4;	//向左转
			else {
				for (int j = 0; j < commands[i]; j++) {
					x += direction[d][0];
					y += direction[d][1];
					vector<int> tmp = { x,y };
					if (s.find(tmp) != s.end()) {
						x -= direction[d][0];
						y -= direction[d][1];
						break;
					}
				}
				if (max < x * x + y * y)
					max = x * x + y * y;
			}
		}
		return max;
	}
};
```
