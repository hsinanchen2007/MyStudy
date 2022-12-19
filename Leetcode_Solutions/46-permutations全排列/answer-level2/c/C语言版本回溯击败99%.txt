### 解题思路
**回溯算法三大步骤：**
1. `choose` 选择
2. `explore`拓展
3. `unchoose`(trackback) 回溯

- 选择部分

```
    path[index] = nums[i];
    visited[i] = 1;
    index += 1;
```
- 拓展(即此处采用递归实现)

```
    helper(nums, numsSize, visited, path, result, index, reindex);
```

- 回溯

```
    visited[i] = 0;
    index -= 1;
```

**需要注意的地方**
1. 必须遍历所有可能的结果，不要漏掉解
2. 避免重复选择某个元素(数字)，采用标记数组`visited`，标记当前choose时选取的元素，unchoose(trackback)时还原标记
3. 返回值为`int** `类型，可以理解为二维数组索引，必须采用malloc初始化返回数组，假如用二维数组初始化`int A[][]`，返回时会被系统回收


### 代码

```c
void helper(int* nums, int numsSize, int* visited, int* path, int **result, int index, int* reindex){
    for(int i=0;i<numsSize;i++){
        if(visited[i])  continue;
        path[index] = nums[i];
        visited[i] = 1;
        index += 1;
        if(numsSize == index) {
            result[*reindex]  = (int*) malloc(sizeof(int)*numsSize);
            for(int j=0;j<numsSize;j++){
                result[*reindex][j] = path[j];
            }
            *reindex = *reindex + 1;
        }
        helper(nums, numsSize, visited, path, result, index, reindex);
        visited[i] = 0;
        index -= 1;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int visited[numsSize];
    int path[numsSize];
    int index = 0;
    int reindex = 0;
    memset(visited, 0, sizeof(visited));
    int **result = (int**) malloc(sizeof(int*) * 10000);  
    helper(nums, numsSize, visited, path, result, index, &reindex);
    *returnSize = reindex;
    *returnColumnSizes = (int*) malloc(sizeof(int) * 10000);
    
    for(int i=0;i<reindex;i++){
        (*returnColumnSizes)[i] = numsSize; 
    }
    return result;
}

```