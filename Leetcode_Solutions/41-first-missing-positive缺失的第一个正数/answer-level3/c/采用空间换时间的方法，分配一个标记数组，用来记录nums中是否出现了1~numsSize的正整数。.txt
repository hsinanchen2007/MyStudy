### 解题思路
此处撰写解题思路

### 代码

```c
int firstMissingPositive(int* nums, int numsSize){
    int i;
    int *B = (int*)malloc(sizeof(int)*numsSize);//标记数组
    memset(B,0,sizeof(int)*numsSize);//赋初值为0
    for(i = 0;i<numsSize;i++){
        if(nums[i]>0 && nums[i]<=numsSize){
            B[nums[i]-1]=1;//若nums[i]的值介于1~numsSize，则标记数组
        }
    }
    //遍历数组
    for(i=0;i<numsSize;i++){
        if(B[i]==0) break;
    }
    return i+1;
}
```