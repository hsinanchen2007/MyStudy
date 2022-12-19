**全排列的特点**
    - 每个数字都必须使用一次
    - 每个数字不能重复使用
根据全排列的特点，可以采用回溯法遍历所有可能的结果，对于不同状态下的递归，元素的被选情况都不一样。因此，可以用for loop来遍历选择那些没有被选择的数字。

**回溯法三大步骤**
    - choose
    - explore
    - unchoose  
首先，所有的元素都是unchoose的。可以choose当前可以选择元素，然后在此状态下，递归（设为递归A）决定下一状态的选取。当递归A结束返回时(可能是找到了结果返回，也可能是当前状态找不到结果，总之返回了)) 。要将choose的元素改成unchoose，也就是一个元素要经过unchoose - choose - unchoose.比如，我完成一件事情需要三个步骤(D - E - F)。当步骤A采取某种措施(如措施t)，递归到措施E。当步骤A不采取措施t时，递归到步骤E。然后再根据步骤E采取或不采取某种措施，递归到F。遍历完所有的空间状态。另外，base case（递归出口） 是仅当有n个数的排列选了n个数字之后，将其状态记录下来。

```
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
