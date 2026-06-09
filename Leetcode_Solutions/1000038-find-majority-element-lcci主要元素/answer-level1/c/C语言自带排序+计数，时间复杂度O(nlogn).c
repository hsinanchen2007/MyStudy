### 解题思路
此处撰写解题思路

### 代码

```c

int compare(int *a,int *b){
    return *a-*b;
}
int majorityElement(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),compare);
    int maymain=nums[numsSize/2];
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==maymain)count++;
    }
    if(count>numsSize/2){
        return maymain;
    }
    return -1;
}
```