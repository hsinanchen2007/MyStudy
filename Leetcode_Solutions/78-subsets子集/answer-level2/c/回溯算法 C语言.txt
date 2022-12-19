**回溯递归**

```
void trackback(int* nums, int numsSize, int** res, int index, int** colSizes, int colnum, int* path, int* pos, int* num){
    memcpy(res[*num], path, numsSize*sizeof(int));
    colSizes[0][(*num)++] = colnum++;
    for(int i=index;i<numsSize;i++){
        path[(*pos)++] = nums[i];
        trackback(nums, numsSize, res, i+1, colSizes,colnum, path, pos, num);
        (*pos)--;
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // 申请分配结果数组res内存空间
    int N = pow(2,numsSize);
    *returnSize = N;
    int** res = (int**)malloc(N*sizeof(int*));
    returnColumnSizes[0] = (int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        res[i] = (int*)malloc(numsSize*sizeof(int));
    if(numsSize == 0) return res;
    // 申请分配中间路径数组path内存空间
    int* path = (int*)malloc(numsSize*sizeof(int));
    // pos为回溯指针，指向nums中数字，num指向结果数组向量顶部位置
    int pos = 0, num = 0;
    trackback(nums, numsSize, res, 0, returnColumnSizes, 0, path, &pos, &num);
    free(path);
    return res;
}
```
![image.png](https://pic.leetcode-cn.com/575ce0943853b0971c9f67a93817531dd5aa15e9a5a762a6ee5b6e0e02a0bc65-image.png)
