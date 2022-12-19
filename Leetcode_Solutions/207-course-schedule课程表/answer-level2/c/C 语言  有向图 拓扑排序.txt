### 解题思路
此处撰写解题思路
1. 邻接矩阵表示有向图，判断是否存在拓扑排序
2. 详细过程见代码注释
### 代码

```c
// 邻接矩阵表示有向图，判断是否存在拓扑排序

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    
    if (numCourses <= 0 || prerequisites == NULL || prerequisitesSize <= 0 || prerequisitesColSize == NULL) {
        return true; // 没有约束时，返回true
    }

    // 1. 建立邻接矩阵 二维数组
    int** graphArray = (int **)malloc(numCourses * sizeof(int*));
    memset(graphArray, 0, numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        graphArray[i] = (int *)malloc(numCourses * sizeof(int));
        memset(graphArray[i], 0, numCourses * sizeof(int));
    }

    // 二维数组初始化 [1, 0] 即表示0->1 的边
    for (int i = 0; i < prerequisitesSize; i ++) {
        int x = prerequisites[i][1];
        int y = prerequisites[i][0];
        graphArray[x][y] = 1;
    }

    // 2.建立数组，记录每个点的入度
    int* indegree = (int *)malloc(numCourses * sizeof(int));
    memset(indegree, 0 , numCourses * sizeof(int));

    //  求每个节点的入度 二维矩阵每一列的和即为每节点的入度
    for (int i = 0; i < numCourses; i++) {
        int degreeTemp = 0;
        for (int j = 0; j < numCourses; j++) {
            degreeTemp += graphArray[j][i]; // 列累加
        }
        indegree[i] = degreeTemp;
    }

    // 3.初始化栈 保存入度为0的节点
    int* stack = (int *)malloc(numCourses * sizeof(int));
    memset(stack, 0 , numCourses * sizeof(int));
    int stackIndex = -1; // 栈index

    // 入度为0的点入栈
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            stackIndex++;
            stack[stackIndex] = i;
        }
    }

    // 4. 循环，判断是否存在拓扑排序
    int count = 0; // 对输出顶点计数
    while (stackIndex != -1) {
        int curIndex = stack[stackIndex]; // 输出当前顶点
        stackIndex--;
        count++; // 计数加1

        // 对输出点的邻接点的入度-1
        for (int i = 0; i < numCourses; i++) {
            if (graphArray[curIndex][i] == 1) {
                indegree[i] = indegree[i] - 1; // 入度 - 1
                // 若入度为0，则入栈
                if (indegree[i] == 0) {
                    stackIndex++;
                    stack[stackIndex] = i;
                }
            }
        }
    }

    // 5. 判断结果 若count小于顶点数，则说明有环，不存在拓扑排序
    if (count < numCourses) {
        return false;
    }

    return true;
}
```