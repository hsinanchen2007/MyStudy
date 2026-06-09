- 子集
    对于n个数字的子集，不必每个数字都选，即当前数字可选可不选。那么仅当我扫描到最后一个数了。才把生成的子集记录下来。可以采用一个index变量来记录当前扫描到哪个元素。当index等于数组的长度的时候，记录该子集。

- 回溯
    - choose 
    - explore
    - unchoose
choose是选择当前元素作为子集，explore是根据当前选的状态去递归决定下一个选不选。unchoose是不选该元素，则其explore是在当前不选的情况下，去递归决定下一个状态选不选

```
void helper(int* nums, int numsSize, int* cur, int index, int ele_num, int* reindex, int* A, int** result){
    if(index == numsSize){
        result[*reindex] = (int*)malloc(sizeof(int) * ele_num);
        for(int i=0;i<ele_num;i++){
            result[*reindex][i] = cur[i];
        }
        A[*reindex] = ele_num;
        *reindex += 1;
        return;
    }
    cur[ele_num] = nums[index];
    ele_num += 1;
    helper(nums, numsSize, cur, index+1, ele_num, reindex, A, result);
    ele_num -=1;
    helper(nums, numsSize, cur, index+1, ele_num, reindex, A, result);
}



int** subsets(int* nums, int numsSize, int* returnSize,  int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * 10000);
    if(numsSize ==0) return result;
    int cur[10000];
    int A[10000];
    int index = 0;
    int reindex = 0;
    int ele_num = 0;
    helper(nums, numsSize, cur, index, ele_num, &reindex, A, result);
    *returnSize = reindex; 
    *returnColumnSizes = (int*) malloc(sizeof(int) * reindex);
    for(int i=0;i<reindex;i++)
    // returnColumnSizes DID NOT MALLOC !!!!!!!!!!!
        (*returnColumnSizes)[i] = A[i];
    return result;
}
```


