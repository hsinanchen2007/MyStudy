#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool dfs(int** graph, int* graphColSize, int* flag, int number, int color)
{
    flag[number] = color;
    for (int i = 0; i < graphColSize[number]; i++) {
        if (flag[graph[number][i]] == flag[number]) { // 如果就近的两个颜色相同，则直接返回false
            return false;
        }
        if (flag[graph[number][i]] == 0) {
            if (false == dfs(graph, graphColSize, flag, graph[number][i], 0 - color)) {
                return false;
            }
        }
    }
    return true;
}

// 判断是否为二分图
bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    // 图的遍历，遍历所有路径，然后染色
    int* flag = (int*)calloc(101, sizeof(int)); //0标识未染色，1为一种，-1为另一种;没法分割就表示flag会多路径下不一致

    for (int i = 0; i < graphSize; i++) {
        if (flag[i] == 0) {
            bool ret = dfs(graph, graphColSize, flag, i, 1);
            if (ret == false) {
                free(flag);
                return false;
            }
        }
    }
    free(flag);
    return true;
}