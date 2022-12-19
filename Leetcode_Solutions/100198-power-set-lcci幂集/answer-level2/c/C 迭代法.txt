看懂下面这个迭代的过程，基本上就可以做出来了。

[[]] --> [[],[1]] --> [[],[1],[2],[1,2]] --> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
1：初始是空，子集合长度是0
2、双重循环，遍历列表中的每一个元素，对当前集合中的每一个子集合，加入该元素，形成新的子集，该子集的长度要记录下来。


```
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = 0;
        return NULL;
    }


    int size = (int) pow(2, numsSize);
    *returnSize = size;
   
    int *p = *returnColumnSizes = (int*)calloc(size, sizeof(int));
    int** ret = (int**) calloc(size, sizeof(int*));
    for (int i = 0; i < size; i++) {
        ret[i] = (int*) calloc(numsSize, sizeof(int));
        p[i] = 0;
    }

    g_total = 0;
    ret[0] = NULL; // 初始为空
    p[0] = 0;       //初始列宽为0
    g_total = 1;
    for (int level = 0; level < numsSize; level++) {
        //对集合里面的每一个集合进行处理,每个集合的长度为p[j] 
        int next = g_total;   
        for (int j = 0; j < g_total; j++) {
            // printf("next = %d level = %d, j = %d, g_total = %d, p[%d] = %d\n", next, level, j, g_total, j, p[j]); 
            
            for (int k = 0; k < p[j]; k++) {
                ret[next][k] = ret[j][k];
            }
            // 对每一个集合增加操作
            ret[next][p[j]] = nums[level];

            p[next] = p[j] + 1;
            next++;
        }  
        g_total = next;       
    }

    return ret;
}
```
