### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <string.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize=2;
    int *res=(int *)malloc(sizeof(int)*2);
    memset(res,0,2*sizeof(int));
    int low=0,high=numbersSize-1;
    while(low<high){
        int c=numbers[low]+numbers[high];
        if(c>target){
            high--;
        }else if(c<target){
            low++;
        }else{
            res[0]=low+1;
            res[1]=high+1;
            break;
        }
    }
    return res;
}
```