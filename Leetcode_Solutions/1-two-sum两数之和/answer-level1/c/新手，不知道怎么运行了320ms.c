### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(const int* nums,const int numsSize, const int target,int* returnSize){
    int i,j,*p;
    *returnSize=0;
    p=malloc(sizeof(int)*2);
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                p[0]=i;
                p[1]=j;
                *returnSize=2;
                break;            
            }
        }
        if(*returnSize!=0){
            break; 
        }
    }
        return p;
}
```