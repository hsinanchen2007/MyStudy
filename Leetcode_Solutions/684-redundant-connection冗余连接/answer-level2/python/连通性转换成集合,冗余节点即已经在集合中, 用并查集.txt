### 解题思路
> 连通图,可以转换成一个连通的集合, 冗余的边表示 两个顶点已经在集合中了; 一边构建连通集合一边检查, 遇到冗余的直接输出; 打败100%

### 代码

```c [groups1-c]
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
int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
    if (edges == NULL || edgesColSize == NULL || returnSize == NULL) {
        return NULL;
    }
    int *result = (int*)malloc(sizeof(int) * 2);
    if (result == NULL) {
        return NULL;
    }
    
    InitGroups();
    int u, v, uGroupId, vGroupId;
    for (int i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];
        uGroupId = Find(u);
        vGroupId = Find(v);
        if (uGroupId == vGroupId) {
            result[0] = u;
            result[1] = v;
            break;
        }
        g_groups[uGroupId] = vGroupId;
    }

    *returnSize = 2;
    return result;
}
```

```python3 [groups1-python3]
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        groups = [i for i in range(1001)]

        def find(x):
            if x == groups[x]:
                return x
            groups[x] = find(groups[x])
            return groups[x]

        for u, v in edges:
            ug = find(u)
            vg = find(v)
            if ug == vg:
                return [u, v]
            groups[vg] = ug
        # should not run to here!!!
        return [0, 0]
```

# 运行情况
```
执行用时 :4 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.6 MB, 在所有 C 提交中击败了100.00%的用户

执行用时 :60 ms, 在所有 Python3 提交中击败了79.95%的用户
内存消耗 :14.2 MB, 在所有 Python3 提交中击败了5.26%的用户
```