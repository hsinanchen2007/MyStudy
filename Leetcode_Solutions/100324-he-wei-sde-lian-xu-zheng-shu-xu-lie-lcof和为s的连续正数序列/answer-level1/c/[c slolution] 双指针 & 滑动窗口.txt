### 解题思路



### 代码

```c
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    if(target <= 0 ){
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*)*target);
    *returnColumnSizes = (int*)malloc(sizeof(int)*target);

    *returnSize  = 0;

    int left = 1 , right = 1 , sum = 0 , len = target /2;
    while(left <= len){
        if(sum == target){
            res[*returnSize] = (int*)malloc(sizeof(int) * (right - left));
            (*returnColumnSizes)[*returnSize] = right - left ;
            for(int  i = left ; i < right; i++){
                res[*returnSize][i-left] = i; 
            }
            (*returnSize)++;
            sum -= left;
            left++;
        }
        if(sum < target){
            sum += right;
            right++;
        }
        if(sum > target){
            sum -= left;
            left++;
        }
    }

    return res;
}
```