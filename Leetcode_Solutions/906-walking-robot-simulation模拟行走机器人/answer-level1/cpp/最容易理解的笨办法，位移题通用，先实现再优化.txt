存在问题：
理解题意    
            1.如果遇到障碍物，就停在之前的点上，无法到达障碍物所在的那一点。
            2.求的是距离远点最大的距离，所以每次到达一个位置需要计算距离远点的欧式距离的平方。
知识点
            1.方向选择；按照 上->右->下->左四个方向，将x y 的变化量做为四个数组，成为如下程序中的direction变量；这么做的好         处是遇到 -1 就顺时针旋转（下标++）， 遇到-2就逆时针旋转（下标--），在纸上画出方向就非常好理解。
            2.查询障碍点方法；如果自己写for遍历的话会超出时间限制，这里我们选择set来查询，或者用hash map也是没有问题的，具          体函数调用很好记，百度即可。



```c++
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int x = 0;
		int y = 0;
		int dir_ = 0;   //北方向移动 下标为direction的 第0个 
		int ans = 0;
		int direction[4][2] = {             //4个方向坐标变化矩阵
			{0, 1},
			{1, 0},
			{0, -1},
			{-1, 0}
		};


		set<pair<int, int>> obs_set;            //方便查询操作
		for (int i = 0; i < obstacles.size(); i++) {
			obs_set.insert(make_pair(obstacles[i][0], obstacles[i][1]));
		}

		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == -1) {
				dir_ += 1;   // 0 , 1 , 2, 3    
				if (dir_ == 4) {            //也可以用大神的 (dir_ + 5) % 4
					dir_ = 0;
				}
			}
			else if (commands[i] == -2) {
				dir_ -= 1;
				if (dir_ == -1) {           //也可以用大神的 (dir_ + 3) % 4
					dir_ = 3;
				}
			}
			else {
				while (commands[i] != 0) {      //如果的得到的左边不是方向变化操作，就进行位移操作
					
					x += direction[dir_][0];
					y += direction[dir_][1];
					if (obs_set.find(make_pair(x, y)) == obs_set.end()) {
						//如果没有找到
						ans = max(ans, x * x + y * y);
						commands[i] --;

					}
					else {
						//如果到了障碍点
						x -= direction[dir_][0];
						y -= direction[dir_][1];
						break;
					}
				}
			}
		}
		/*cout << x << ',' << y << endl;*/
		return ans;
	}
};

```
