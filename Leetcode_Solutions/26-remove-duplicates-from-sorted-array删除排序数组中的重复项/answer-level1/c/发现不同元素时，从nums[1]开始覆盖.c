### 解题思路
此处撰写解题思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)return 0;
    int t=nums[0];int local=0;
    if(numsSize==1){return 1;}
    for(int i=0;i<numsSize;i++){
        if(t==nums[i]){continue;}
        else{nums[++local]=nums[i];t=nums[i];}
    }
    return local+1;
}
```