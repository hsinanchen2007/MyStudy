### 解题思路
1.先DFS一遍计算各节点的叶子数量（该步应该可以与下面的流程合并，但是我没有做）
2.再DFS一遍计算能够达到目标节点的沿途节点的子节点数乘积，因为肯定只有一条路，所以不怕算重复了
3.判断如果能够到达目标节点就计算概率，否则返回0；
### 代码

```c
bool DFS(int** edges, int edgesSize, int parNum, int currentNum, int target, int t, int level, int *ans, int *childNum) {
    int i;
    bool isPath = false;
    // 如果遍历层数已经超过了最大跳数，或已经到了目标节点但是还有子节点并还要往下跳，返回false
    if (level > t || (currentNum == target && level < t && childNum[currentNum] > 0)) {
        return false;
    }
    // 到达节点返回true
    if (currentNum == target) {
        return true;
    }
    // DFS子节点
    for (i = 0; i < edgesSize; i++) {
        // 如果为true说明能够到达目标节点，计算沿途各节点的子节点数量乘积
        if (edges[i][0] == currentNum && edges[i][1] != parNum) {
            isPath = DFS(edges, edgesSize, currentNum, edges[i][1], target, t, level + 1, ans, childNum);
            if (isPath == true) {
                (*ans) *= childNum[currentNum];
                return true;
            }
        } else if (edges[i][1] == currentNum && edges[i][0] != parNum) {
            isPath = DFS(edges, edgesSize, currentNum, edges[i][0], target, t, level + 1, ans, childNum);
            if (isPath == true) {
                *ans *= childNum[currentNum];
                return true;
            }
        }

    }

    return false;
}
void DFS2(int** edges, int edgesSize, int parNum, int currentNum, int *childNum)
{
    int i;
    for (i = 0; i < edgesSize; i++) {
        // 找到子节点进行遍历
        if (edges[i][0] == currentNum && edges[i][1] != parNum) {
            // 统计子节点数量
            childNum[currentNum]++;
            DFS2(edges, edgesSize, currentNum, edges[i][1], childNum);
        } else if (edges[i][1] == currentNum && edges[i][0] != parNum) {
            childNum[currentNum]++;
            DFS2(edges, edgesSize, currentNum, edges[i][0], childNum);
        }
    }
    return;
}
double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    int *childNum =(int *)malloc(sizeof(int) * (n + 1));
    memset(childNum, 0, sizeof(int) * (n + 1));
    int ans = 1;
    bool isPath;
    // 先将每个节点的子节点数量记录下来，这块应该可以优化
    DFS2(edges, edgesSize, -1, 1, childNum);
    // 再遍历一次，计算概率
    isPath = DFS(edges, edgesSize, -1, 1, target, t, 0, &ans, childNum);
    // 如果为true则返回
    if (isPath) {
        return 1.0 / ans;
    }
    return 0;
}
```