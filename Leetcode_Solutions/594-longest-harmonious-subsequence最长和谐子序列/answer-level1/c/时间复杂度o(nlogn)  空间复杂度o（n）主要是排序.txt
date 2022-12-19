### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int findLHS(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int i=0;
    int j;
    int count;
    int max=0;
    int flag;
    while(i<numsSize){
        flag=0;
        count=0;
        int temp=nums[i];
        while(i<numsSize&&nums[i]==temp){
            count++;
            i++;
        }
        j=i;
        while(i<numsSize&&nums[i]==temp+1){
            flag=1;
            i++;
            count++;
        }
        if(flag==1)
            max=count>max?count:max;
        i=j;
    }
    return max;
}
```