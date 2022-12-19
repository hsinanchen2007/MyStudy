### 解题思路
1.bfs计算出达到每个点的概率及最短时间
2.基于3种场景计算具体的概率
（1）若时间和到达时间相同，则直接计算概率
（2）若时间超过到该时间且成员数量为0，则计算概率
（3）其他情况都为0
注意点：图中的路径为双向的，通过1出发，去生成一张有向图，同时生成真实的成员数量。

### 代码

```c
#define MAX_NUM 100
typedef struct nodeInfo_ {
    int deep; /* 到该节点有多少种场景*/
    int time; /* 从节点1到该节点需要的时间*/
} nodeInfo;
double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    int matrix[MAX_NUM + 1][MAX_NUM + 1] = { 0 };
    int memNum[MAX_NUM + 1] = { 0 }; /*无向图中的成员数量，用于计算node的场景*/
    int realMem[MAX_NUM + 1] = { 0 }; /*有向图中的成员数量*/
    int flag[MAX_NUM + 1] = { 0 }; /*用于减枝，避免循环访问*/
    /* 图为无向图，此时2个方向都要任务存在路径 */
    for (int i = 0; i < edgesSize; i++) {
        matrix[edges[i][0]][edges[i][1]] = 1;
        matrix[edges[i][1]][edges[i][0]] = 1;
        memNum[edges[i][0]]++;
        memNum[edges[i][1]]++;
    }
    nodeInfo allNode[MAX_NUM + 1] = { 0 };
    /* bfs 计算 deep和time及有向图中的真实的成员数量*/
    int queue[MAX_NUM + 2];
    int start = 1;
    int begin = 0;
    int end = 0;
    queue[0] = 1;
    end++;
    allNode[1].deep = 1;
    flag[1] = 1;
    while (begin < end) {
        int node = queue[begin++];
        for (int i = 1; i < n + 1; i++) {
            if (matrix[node][i] == 1 && flag[i] == 0) {
                allNode[i].time = allNode[node].time + 1;
                allNode[i].deep = allNode[node].deep * memNum[node];
                realMem[node] = memNum[node];                
                queue[end++] = i;
                flag[i] = 1;
                memNum[i]--;
            }
        }
    }
    /* 1.若时间和到达时间相同，则直接计算概率*/
    /* 2.若时间超过到该时间且成员数量为0，则计算概率*/
    /* 3.其他情况都为0*/
    if (t == allNode[target].time) {
        return 1/(float)allNode[target].deep;
    } else if (realMem[target] == 0 && t > allNode[target].time) {
        return 1/(float)allNode[target].deep;
    } else {
        return 0.0;
    }
}
```