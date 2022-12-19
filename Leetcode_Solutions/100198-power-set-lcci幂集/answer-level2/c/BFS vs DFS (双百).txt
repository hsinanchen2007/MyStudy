### 解题思路
BFS
1.思路本质上是广度优先搜索法
2.要知道一个数组的子集 有 2^(数组个数)个 包含空集的话，例如[1,2,3]->有2^3=8个子集
3.例如[1,2,3]  开始先创建个仅包含空集的二维数组[[],]我们每次往里面添加一个数，大致思路如下（本质上就是二叉树(left是加上这个数，right是不加这个数)）
[[]] --> [[],[1]] --> [[],[1],[2],[1,2]] --> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
DFS
同样是二叉树思想，用递归的方式完成
### 代码
BFS
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ans,top=-1,*p,x;
    *returnSize = 1<<numsSize;
    ans = (int**)malloc(sizeof(int*)*(1<<numsSize));
    p = (int*)malloc(sizeof(int)*(1<<numsSize));
    p[++top] = 0;
    for (int i=0;i<numsSize;i++){
        x = top;
        for (int j=0;j<=x;j++){
            ans[++top] = (int*)malloc(sizeof(int)*(p[j]+1));
            p[top] = p[j] + 1;
            for (int k=0;k<p[j];k++)
                ans[top][k] = ans[j][k];
            ans[top][p[j]] = nums[i];
        }
    }
    *returnColumnSizes = p;
    return ans;
}
```
DFS
```c
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ans,top=-1,*p;
    ans = (int**)malloc(sizeof(int*)*(1<<numsSize));
    p = (int*)malloc(sizeof(int)*(1<<numsSize));
    p[++top] = 0;
    void DFS(int *arr,int arrSize,int index){
        if (index>=numsSize)
            return;
        int *new_arr;
        new_arr = (int*)malloc(sizeof(int)*(arrSize+1));
        for (int i=0;i<arrSize;i++)
            new_arr[i] = arr[i];
        new_arr[arrSize] = nums[index];
        p[++top] = arrSize + 1;
        ans[top] = new_arr;
        DFS(new_arr,arrSize+1,index+1);
        DFS(arr,arrSize,index+1); 
    }
    DFS(NULL,0,0);
    *returnSize = top + 1;
    *returnColumnSizes = p;
    return ans;
}
```