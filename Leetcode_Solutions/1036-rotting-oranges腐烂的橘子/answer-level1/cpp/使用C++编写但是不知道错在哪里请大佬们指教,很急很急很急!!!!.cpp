如下代码的思路就是遍历四个方向如果臭的橘子四周存在好的橘子则好的橘子变为坏的橘子，当遍历了一个回合后再重新遍历思路是再重新找有没有好的橘子如果存在坏的橘子则返回-1
三个提供实例均可通过但提交却不能通过
![p0.PNG](https://pic.leetcode-cn.com/fb585179b84380aa2bd154d46638759e5d2c4f472c1fe6c0f66f46dfef3a2bf3-p0.PNG)

![p1.PNG](https://pic.leetcode-cn.com/97473d82e1cc31c9f9377ffe262f94cb2a846be480c397b1313cd77e7c283c04-p1.PNG)

![P2.PNG](https://pic.leetcode-cn.com/9681377aec1971397f05d3244a1e27e01a771798c8cbbd28a1878f86e225cf10-P2.PNG)

但最后提示如下实例无法通过
![P3.PNG](https://pic.leetcode-cn.com/cdf3db6b7de268100f96d8ef12ab060bf707e30ebc0ba3d76d662295bbca9ee4-P3.PNG)

这让我百思不得其解请指教

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //就是所有的橘子变成臭得步骤
		int step = 0;
		//前提条件应该是至少所有都要变成臭的才记步数
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
                //发现有丑橘子
				if (grid[i][j] == 2) {
                    int temp1=0, temp2=0, temp3=0, temp4=0;
					if (i + 1 > 0 && i + 1 < grid.size() && grid[i + 1][j] == 1) {
                        temp1 = grid[i + 1][j];
						grid[i + 1][j] = 2;
					}

					if (i - 1 > 0 && i - 1 < grid.size() && grid[i - 1][j] == 1) {
                        temp2 = grid[i - 1][j];
						grid[i - 1][j] = 2;
					}

				    if (j + 1 > 0 && j + 1 < grid[0].size() && grid[i][j+1] == 1) {
                        temp3 = grid[i][j+1];
						grid[i ][j+1] = 2;
					}

				    if (j - 1 > 0 && j - 1 < grid[0].size() && grid[i][j-1] == 1) {
                        temp4 = grid[i][j-1];
						grid[i][j-1] = 2;
					}
                      
                   if ((i + 1 > 0 && i + 1 < grid.size() && temp1==1&&grid[i + 1][j] == 2) 
						|| (i - 1 > 0 && i - 1 < grid.size() && temp2 == 1&&grid[i - 1][j]                              == 2)
						|| (j + 1 > 0 && j + 1 < grid[0].size()&&temp3==1 && grid[i][j + 1]                             == 2)
						|| (j - 1 > 0 && j - 1 < grid[0].size() && temp4 == 1 && grid[i][j                             - 1] == 2)) {
						step++;
					}
				}

               
			}
		}

		//再次遍历只能为臭的或者没臭的
        
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					step = -1;
					break;
				}
			}
		}
        
		return step;
    }
};