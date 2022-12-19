这里采用方法3完成；
```

int cmpfunc (const void *a, const void *b)
{
    return ( *(int*)a > *(int*)b );
}

int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    /*
        方法1：暴力;
        方法2：DFS + 剪枝;
        方法3：排序 + 双指针;
    */
    int** res = (int**)malloc(sizeof(int*) * 50000); 
    int* col = (int*)malloc(sizeof(int) * 50000); //保存res中各个数组的长度 的数组

    int l = 0;
    int r = numsSize - 1;
    int count = 0;

    //特殊处理
    if (!nums || numsSize <= 1){
        *returnColumnSizes = 0;
        *returnSize = 0;
        return res;
    }

    //排序
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    //双指针
    while(l < r){
        if (nums[l] + nums[r] > target){
            r--;
        }else if(nums[l] + nums[r] < target){
            l++;
        }else{
            res[count] = (int*)malloc(sizeof(int)*2);
            res[count][0] = nums[l];
            res[count][1] = nums[r];
            col[count] = 2;
            l++;
            r--;
            count++;
        }
    }

    *returnSize = count;//返回数组个数 
    *returnColumnSizes = col;//返回数组 表示每个数组中的长度
    return res;
}


```
