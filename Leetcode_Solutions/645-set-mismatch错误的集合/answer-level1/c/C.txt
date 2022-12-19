### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
     if(NULL == nums || 0 == numsSize ){
         *returnSize = 0;
         return NULL;
     }

     bool *flagArr = (bool*)malloc(sizeof(bool)*numsSize);
     memset(flagArr,0x00,sizeof(bool)*numsSize);
     static int ret[2] = {0};
     int i = 0;
     for(i = 0;i < numsSize;i++){
         if(flagArr[nums[i]-1]){
             ret[0] = nums[i];
         }
         else{
             flagArr[nums[i]-1] = true;
         }
     }

     for(i = 0;i < numsSize;i++){
         if(!flagArr[i]){
             ret[1] = i + 1;
             break;
         }
     }
     *returnSize = 2;
     return ret;
}
```