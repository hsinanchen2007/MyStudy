#### BFS：
1. BFS 每走一步，会把下一步能走的格子加入队列
2. 按顺序走完这一步所有的可能，队列里就剩下下一步所有的可能
3. 当走到终点时，就是最少步骤
4. 每走一步，还会使用 set 来记录已经走到过的格子的坐标
5. 把下一步加入队列前，检查，重复的就不用进队列了

#### 分析：
1. 如果这道题没有人，箱子自己走，那么只需要了解BFS，就可以解决了
2. 如果有人存在，把人的状态同时记录下来
3. 当人走到箱子的格子上，把箱子沿同一方向移动，如果箱子位置合法，那就是推动箱子了

#### 问题和解决：
同时记录人和箱子的状态，会有一些问题要解决
1. 因为人也动，箱子也动，但是只有箱子动才算步数，所以加入队列的顺序，并不是步数顺序了
   所以需要一个记录步数，同时记录人和箱子的坐标，还可以排序的队列
   使用 priority_queue（优先队列）解决。
   ```C++ []
	priority_queue<vector<size_t>, vector<vector<size_t>>, greater<vector<size_t>>> pq;
   ```
   队列中的数据是 `vector<size_t>`
   优先队列会使用 `vector<vector<size_t>>` 来保存 `vector<size_t>`
   设置为升序存储 `greater<vector<size_t>>`
   > 其中 `vector<size_t>` 保存的内容是：
   > [0] 当前状态最小推箱子次数
   > [1] 人的坐标 x
   > [2] 人的坐标 y
   > [3] 箱子的坐标 x
   > [4] 箱子的坐标 y
2. set 怎么调整
   `set<vector<size_t>>` 用人和箱子的坐标来做记录
   > [0] 人的坐标 x
   > [1] 人的坐标 y
   > [2] 箱子的坐标 x
   > [3] 箱子的坐标 y
   
#### 解题思路：
1. 定义优先队列
2. 将原始数据中的人和箱子坐标提取出来，地图还原成通路
3. 将起始状态存入队列
4. 定义 set
5. 将起始状态存入 set
6. 定义方向数组
7. 开始 bfs 吧，`while (!pq.empty())`
8. 对人移动，检查合法性
9. 检查人是否走到箱子上
   91. 移动箱子，检查合法性
   92. 步数 +1
10. 判断箱子是否到终点，返回步数
11. 检查 set，移动后是否重复，记录 set
12. 如果 bfs 没结果，无法到达终点，返回 -1

#### 模拟：
<![1.png](https://pic.leetcode-cn.com/75a7e4607a7e1f52e1688653044e26724fe6d925a00332cc942d34bacacfab81-1.png),![2.png](https://pic.leetcode-cn.com/7136acce77c99d08e82ee4fb9e26d9777d9d542502dabf3fc700f6674a0f32d4-2.png),![3.png](https://pic.leetcode-cn.com/fe645ef1a768e577dfef4e4201080f95e60c884f4bc9f8819c16bb62eaa2ba06-3.png),![4.png](https://pic.leetcode-cn.com/326b9d2771787448358dc83dbe3b35b771030674b93cb771ff824b42a67c2a5d-4.png),![5.png](https://pic.leetcode-cn.com/4f94704e022c15d71bd581ae2b4623e931a0e00d9b0ee77009a0b3129b60cf7d-5.png)>

做了几张图帮助理解一下，虽然只有开始的几步，但是如果理解了，后面脑补就可以了。  

> 可以看到，当从队列中取出一个状态，4 种情况有一种情况是推动箱子，另一种是箱子没动人动。
> 当 4 种情况中合理的都加入队列后，根据优先队列的排序，下一个状态是优先箱子没动人动的情况。
> 因为题目的最终目的是求最少的箱子移动步数，所以只要箱子没动，步数都不增加，那么优先级就会高
> 所以 bfs 才能按照步数作为参考


#### 答题
```C++ []
int minPushBox(vector<vector<char>>& grid) 
{
	// pq，[0]当前状态最小推箱子次数 [1]人的坐标x [2]人的坐标y [3]箱子的坐标x [4]箱子的坐标y
	priority_queue<vector<size_t>, vector<vector<size_t>>, greater<vector<size_t>>> pq;
	size_t m = grid.size();
	size_t n = grid[0].size();

	vector<size_t> a(5, 0);
	for (size_t x = 0; x < m; x++)
	{
		for (size_t y = 0; y < n; y++)
		{
			if (grid[x][y] == 'S')
			{
				a[1] = x;
				a[2] = y;
				grid[x][y] = '.';
			}
			else if (grid[x][y] == 'B')
			{
				a[3] = x;
				a[4] = y;
				grid[x][y] = '.';
			}
		}
	}
	pq.push(a);

	set<vector<size_t>> dist;
	dist.insert({ a[1], a[2], a[3], a[4] });
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!pq.empty())
	{
		auto v = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			vector<size_t> next_s = { v[1] + dx[i], v[2] + dy[i] };
			if (next_s[0] >= m || next_s[1] >= n || grid[next_s[0]][next_s[1]] == '#')
			{
				continue;
			}
			vector<size_t> next_b = { v[3], v[4] };
			size_t d = v[0];
			if (next_s == next_b)
			{
				next_b[0] += dx[i];
				next_b[1] += dy[i];
				if (next_b[0] >= m || next_b[1] >= n || grid[next_b[0]][next_b[1]] == '#')
				{
					continue;
				}
				d++;
			}
			if (grid[next_b[0]][next_b[1]] == 'T')
			{
				return (int)d;
			}

			if (dist.find({next_s[0], next_s[1], next_b[0], next_b[1]}) != dist.end())
			{
				continue;
			}
			dist.insert({ next_s[0], next_s[1], next_b[0], next_b[1] });
			pq.push({ d, next_s[0], next_s[1], next_b[0], next_b[1] });
		}
	}
	return -1;
}
```



#### 致谢：

感谢 `小白二号` [@scut_dell](/u/scut_dell/) 的竞赛题解，让我学到了这种解法。  
我学会之后，再详细的讲解，分享给他人。

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  


