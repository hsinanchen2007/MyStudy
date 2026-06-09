### 解题思路
> 主要有两种场景, 一种是只有一个环, 没有入度为2的点; 另一种是有入度为2的点, 则必然需要删除这个入度为2的边的一个; 具体步骤如下:
- 1. 检查是否有入度为2的点, 记录 导致入度为2的 u, v中的 v ;
- 2. 使用并查集检查所有边, 假设删除最后一个入度为2的边, 第一个边正常处理即可;
- 2.1 遇到形成环的点时, 判定 是否是有入度为2的点的场景, 如果没有, 则当前成环的就是 需要的结果;
- 2.2 如果有入度为2的点, 则当前删除第二组还会导致成环, 说明应该删除的目标是 第一组 u,v;

### 代码

```c
#define MAX_GROUPS_COUNT 1001
int g_groups[MAX_GROUPS_COUNT];

void InitGroups()
{
    for (size_t i = 0; i < MAX_GROUPS_COUNT; i++) {
        g_groups[i] = i;
    }
}

int Find(int id)
{
    if (id == g_groups[id]) {
        return id;
    }
    return g_groups[id] = Find(g_groups[id]);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRedundantDirectedConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
    if (edges == NULL || edgesColSize == NULL || returnSize == NULL) {
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int) * 2);
    if (result == NULL) {
        return NULL;
    }

    InitGroups();
    int twoDegreeUv[2][2];
    int removeFirst = 0;
    int twoDegreeV = MAX_GROUPS_COUNT;
    int degrees[MAX_GROUPS_COUNT] = {0};
    int u, v, uGroupId, vGroupId;
    // 寻找2度节点
    for (int i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];
        degrees[v] += 1;
        if (degrees[v] == 2) {
            twoDegreeV = v;
            break;
        }
    }
    int saveDegreeCount = 0;
    for (int i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];
        if (v == twoDegreeV) {
            twoDegreeUv[saveDegreeCount][0] = u;
            twoDegreeUv[saveDegreeCount][1] = v;
            saveDegreeCount += 1;
        }
        if (v == twoDegreeV && saveDegreeCount == 2) {
            // 跳过第二组, 检查是否有异常;
            continue;
        }
        uGroupId = Find(u);
        vGroupId = Find(v);
        if (uGroupId == vGroupId) {
            removeFirst = 1;
            if (twoDegreeV != MAX_GROUPS_COUNT) {
                // 未删除第1组有问题, 说明应该删除第1组
            } else {
                twoDegreeUv[0][0] = u;
                twoDegreeUv[0][1] = v;
                break;
            }
        }
        g_groups[vGroupId] = uGroupId;
    }
    if (removeFirst) {
        result[0] = twoDegreeUv[0][0];
        result[1] = twoDegreeUv[0][1];
    } else {
        result[0] = twoDegreeUv[1][0];
        result[1] = twoDegreeUv[1][1];
    }
    *returnSize = 2;
    return result;
}
```


### time
```
执行用时 :8 ms, 在所有 C 提交中击败了97.73%的用户
内存消耗 :6 MB, 在所有 C 提交中击败了100.00%的用户
```