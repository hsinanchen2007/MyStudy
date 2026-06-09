# 解法：广搜加优先队列
1. 得承认思考的过程中有语言形态这回事儿，比如我把题意凝结成标题的一句话，确实启发了我的思考。
2. 之所以采用广搜是因为在搜索的路上，能达到同一点的两条路径实际上会有一样的结果，因此可以合并。所以中间点的状态有价值，可以使得每个点只需遍历一次即可。
```
class Solution {
public:
struct cmp {
	bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>>&p2) {
		return p1.first > p2.first ? true : false;
	}
};

int swimInWater(vector<vector<int>>& grid) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> minHeap;
	int res=0;
	int szG = grid.size();
	if (szG < 1) return 0;
	bool hash[50][50]={false};
    vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
	minHeap.push(pair<int, pair<int, int>>(grid[0][0], pair<int, int>(0, 0)));
	while (!minHeap.empty()) {
		pair<int, pair<int, int>> tmp = minHeap.top();
		minHeap.pop();
		int x = tmp.second.first, y = tmp.second.second;
		res = tmp.first > res ? tmp.first : res;
		if (x == szG - 1 && y == szG - 1) { break; }
		hash[x][y] = 1;
        for(int i=0;i<4;i++){
            int nextx=x+dirs[i][0];
            int nexty=y+dirs[i][1];
            if(nextx>=0&&nextx<szG&&nexty>=0&&nexty<szG&&(!hash[nextx][nexty])){
                minHeap.push(pair<int, pair<int, int>>(grid[nextx][nexty], pair<int, int>(nextx, nexty)));               
                }
            }		
	    }
	return res;
    }
};
```
