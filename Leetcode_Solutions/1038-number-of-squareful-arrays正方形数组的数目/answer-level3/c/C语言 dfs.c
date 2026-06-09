### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *a, const void *b){
    return *(int *)a > *(int *)b;
}

void dfs(int *A, int ASize, int *res, int *visited, int *result, int idx)
{
    
    if (idx == ASize) { // 得到一个结果
        
        (*res)++;
        return;
    }
    
    for (int i = 0; i < ASize; i++) {
        if (visited[i] == 0) {
            if (i > 0 && A[i] == A[i - 1] && visited[i - 1] == 0) { //如果当前元素和前一个元素相同时，如果前一个元素没有选，那么当前元素也不选 【2，2，2】
                continue;
            }
            if(idx > 0 && sqrt(result[idx - 1] + A[i]) != (int)sqrt(result[idx - 1] + A[i])) { //不是完全平方数
                continue;
            }

            result[idx] = A[i];
            visited[i] = 1;
            dfs(A, ASize, res, visited, result, idx + 1);
            visited[i] = 0;
        }
    }
}

int numSquarefulPerms(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmp);
    
    int *visited = (int *)calloc(ASize, sizeof(int));
    int *result = (int *)malloc(ASize * sizeof(int));
    int res = 0;
    
    dfs(A, ASize, &res, visited, result, 0);
    return res;
    
}
```