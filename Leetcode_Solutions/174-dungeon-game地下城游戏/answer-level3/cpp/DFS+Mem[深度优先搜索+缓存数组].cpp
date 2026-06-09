### 解题思路
本体直接用DFS进行递归，递归时需要注意对应节点的递推关系，很容易得到：
f(m,n) = dungeon[m][n] + min(f(m+1,n), f(m, n+1));

此外对于如果f(m,n) > 0，需要做特殊处理，此时说明到这个地方来了之后，他到终点根本就不需要花费额外的血量了，那么直接把血量变为0 即可。

接着用memVec来存储计算下来的中间值，避免重复计算，memVec[m][n]就代表从m,n这个点到终点的f(m,n)需要的血量。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> memVec;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        for (int i = 0;i < dungeon.size(); i++) {
            vector<int> vec;
            for( int j = 0; j < dungeon[0].size(); j++) {
                vec.push_back(0);
            }
            memVec.push_back(vec);
            vec.clear();
        }
        return dfs(dungeon, 0, 0, dungeon.size(), dungeon[0].size()) + 1;  //这里最小是0 所以生命值要+1;
    }
    int dfs(vector<vector<int>>& dungeon, int beginX, int beginY, int endX, int endY) {
        if (beginX >= endX || beginY >= endY) {
            return INT_MAX;
        }
        if (memVec[beginX][beginY] != 0) {
            return memVec[beginX][beginY];
        }
        //退出条件
        if (beginX == endX - 1 && beginY == endY - 1) {
            if (dungeon[beginX][beginY] >= 0) {
                //如果最后一个数 > 0
                return 0;
            } else {
                return -dungeon[beginX][beginY];
            }
        }
        //开始递归
        int rightMin = dfs(dungeon, beginX, beginY + 1, endX, endY);
        int downMin = dfs(dungeon, beginX + 1, beginY, endX, endY);
        //开始判断
        int needMin = min(rightMin, downMin) - dungeon[beginX][beginY];
        //判断这里需要的生命值是否是小于0的
        int result = needMin < 0 ? 0 : needMin;
        memVec[beginX][beginY] = result;
        return result;
    }
};
```