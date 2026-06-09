//1.定义一个指针指向开辟的内存空间
//2.两次f循环寻找

### 代码 C语言描述
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *result=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    result[0]=-1;
    result[1]=-1;
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[j] == target-nums[i]){
                result[0]=i;
                result[1]=j;   
                return  result;
            }
        }
    }
    return result;
}
