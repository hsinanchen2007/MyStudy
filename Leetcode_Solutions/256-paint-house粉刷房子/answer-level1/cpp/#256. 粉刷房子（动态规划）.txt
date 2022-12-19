### 状态转移方程
```
R[0] = cost[0][0]
B[0] = cost[0][1]
G[0] = cost[0][2]

R[1] = min(B[0], G[0]) + cost[1][0]
B[1] = min(R[0], G[0]) + cost[1][1]
G[1] = min(R[0], B[0]) + cost[1][2]

R[k] = min(B[k-1], G[k-1]) + cost[k][0]
B[k] = min(R[k-1], G[k-1]) + cost[k][1]
G[k] = min(R[k-1], B[k-1]) + cost[k][2]

result = min(R[n-1], B[n-1], G[n-1])
```

### 代码

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
    	int preR = 0;	int curR = 0;
    	int preB = 0;	int curB = 0;
    	int preG = 0;	int curG = 0;

    	for (int i = 0; i < costs.size(); i++) {
    		curR = min(preB, preG) + costs[i][0];
    		curB = min(preR, preG) + costs[i][1];
    		curG = min(preR, preB) + costs[i][2];
    		preR = curR;
    		preB = curB;
    		preG = curG;
    	}

    	return min(min(curR, curB), curG);
    }
};
```
### 总结
这道题关键在于记录三个维度的数据的迭代, 每轮迭代得到的值符合相邻颜色不能相同的要求，稍加修改还可以保存路径信息。

