### 解题思路
> 典型的并查集求分组数;
- 1. 先初始化分组;
- 2. 遍历关系,更新分组信息,合并有关系的分组;
- 3. 统计合并后的分组情况, 输出结果;

### 代码

```c
#define MAX_STUDENTS_NUM 201
int g_id2Group[MAX_STUDENTS_NUM];

void InitGroups(int n)
{
    for (int i = 0; i < n; i++) {
        g_id2Group[i] = i;
    }
}

int FindId2Groups(int id)
{
    if (id == g_id2Group[id]) {
        return id;
    }
    g_id2Group[id] = FindId2Groups(g_id2Group[id]); // 压缩关系深度
    return g_id2Group[id];
}

void UpdateGroups(int **M, int MSize, int *MColSize)
{
    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < MColSize[i]; j++) {
            if (M[i][j]) {
                g_id2Group[FindId2Groups(i)] = FindId2Groups(j);
            }
        }
    }
}

int GetGroupNums(int groups[MAX_STUDENTS_NUM])
{
    int count = 0;
    for (int i = 0; i < MAX_STUDENTS_NUM; i++) {
        if (groups[i]) {
            count++;
        }
    }
    return count;
}

int findCircleNum(int **M, int MSize, int *MColSize)
{
    int groups[MAX_STUDENTS_NUM] = {0};  // 记录分组id
    InitGroups(MSize);
    UpdateGroups(M, MSize, MColSize);
    // 更新统计每个最终分组中的成员数
    for (int i = 0; i < MSize; i++) {
        groups[FindId2Groups(i)]++;
    }
    return GetGroupNums(groups);
}
```

# 运行情况
```
执行用时 :32 ms, 在所有 C 提交中击败了93.18%的用户
内存消耗 :6.6 MB, 在所有 C 提交中击败了100.00%的用户
```