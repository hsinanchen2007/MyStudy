### 解题思路
使用队列进行广度优先遍历：
1、零点入队
2、将头节点出队，并向右和向下（向左和向上不需要考虑，从零点开始会覆盖到）查找节点；如果该节点满足条件则入队。
入队条件：1）节点不超过边界 2）字面和小于k 3）节点没有访问过

### 代码

```cpp
class Solution {
private:
int sumNum(int n){
    int res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

public:
int movingCount(int m, int n, int k) {
    int matrix[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }
    int total = 0;
    int direction[2][2] = {{0, 1},{1, 0}};
    queue<pair<int, int> > que;
    if(k < 0)
        return 0;
    que.push(make_pair(0, 0));
    matrix[0][0] = 1;
    total = 1;
    while(!que.empty()){
        pair<int ,int> p = que.front();
        que.pop();
        int row = p.first;
        int col = p.second;

        for(int i = 0; i < 2; i++){
            int r = row + direction[i][0];
            int c = col + direction[i][1];
            if(r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] != 0 || sumNum(r) + sumNum(c) > k) //入队条件
                continue;
            que.push(make_pair(r, c));
            matrix[r][c] = 1;
            total += 1;
        }
    }

    return total;
}

};
```