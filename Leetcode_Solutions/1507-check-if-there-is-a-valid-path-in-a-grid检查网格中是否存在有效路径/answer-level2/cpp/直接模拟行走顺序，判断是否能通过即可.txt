先记录一些单元格属性，然后直接模拟行走顺序。
要记录哪些单元格的属性呢？
先定义个方向。下面代码中0表示上方，1表示右方，2表示下方，3表示左方。
单元格在某个方向有没有进出口？下面代码中记为tong，tong[i][j]表示第i+1种street的j方向有无进口。
当知道进入的进口方向时，该单元格的出口是什么，进一步的直接给出知道进口方向时，下一个走到的单元格的进口方向是什么？下面代码中记为next，next[i][j]表示从第i+1种street的j方向进入，出口连接的下一个单元格的进入方向为next[i][j]，-1表示没有该方向进口。
当知道进入的进口方向时，下一个走到的单元格的位置相对于该单元格的偏移是多少。下面代码中记为dx、dy，dx[i]、dy[i]表示以方向i为进口的单元格与上一个单元格的方位关系。
知道这些属性，我们就能模拟行走顺序啦。
以下为代码，注释中有判断是否能走到底的具体说明。
![image.png](https://pic.leetcode-cn.com/8f074bb680a1c70d775bb9c36a738682cac88997154b86030dc5971792419244-image.png)

**代码**
```C++ []
class Solution {
public:
	bool hasValidPath(vector<vector<int>>& grid) {
		//方向说明：0表示上方，1表示右方，2表示下方，3表示左方。
		//tong[i][j]表示第i+1种street的j方向有无进口
		vector<vector<bool>> tong = { {0,1,0,1},{1,0,1,0},{0,0,1,1},{0,1,1,0},{1,0,0,1},{1,1,0,0} };
		//next[i][j]表示从第i+1种street的j方向进入，出口连接的下一个单元格的进入方向为next[i][j]，-1表示没有该方向进口。
		vector<vector<int>> next = { {-1,1,-1,3},{0,-1,2,-1},{-1,-1,1,0},{-1,0,3,-1},{1,-1,-1,2},{3,2,-1,-1} };
		//dx[i]、dy[i]表示以方向i为进口的单元格与上一个单元格的方位关系。
		vector<int> dx = { 1,0,-1,0 };
		vector<int> dy = { 0,-1,0,1 };
		int start;
		for (int s = 0; s < 4; s++) {
			if (!tong[grid[0][0] - 1][s])
				continue;
			bool flag = true;
			start = s;	//以s为左上角单元格的入口
			int i = 0, j = 0;
			while (i != (int)grid.size() - 1 || j != (int)grid[0].size() - 1) {
				if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {	//超出矩阵范围，false
					flag = false;
					break;
				}
				if (!tong[grid[i][j] - 1][start]) {	//start方向没有进口，false
					flag = false;
					break;
				}
				start = next[grid[i][j] - 1][start];
				i = i + dx[start];
				j = j + dy[start];
			}
			if (!flag)	//若flag为false，则说明提前退出了，继续下一个s。
				continue;
			if (!tong[grid[i][j] - 1][start])	//判断是否通到了最后一单元格，start方向没有进口，false
				flag = false;
			if (flag)	//以s为左上角单元格入口能得到通路，返回true
				return true;
		}		
		return false;
	}
};
```
