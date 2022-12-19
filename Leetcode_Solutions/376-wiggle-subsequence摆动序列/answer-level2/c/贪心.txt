### 解题思路
此处撰写解题思路

### 代码

```c
int wiggleMaxLength(int* nums, int numsSize){
    int *ans=(int*)malloc(sizeof(int)*numsSize + 1);
    int i,j=0,da=0;
    if(numsSize==0) return 0;
    if(numsSize==1) return 1;
    ans[0]=nums[0];
    i=0;
    while(i < numsSize - 1 && nums[i]==nums[0]) i++;
    if(nums[0]<nums[i]) da=1;
    else da=0;
    for(i=1;i<numsSize;i++){
        if(da){
            if(nums[i]>ans[j]) ans[++j]=nums[i],da=0;
            else ans[j]=nums[i];
        }
        else{
            if(nums[i]<ans[j]) ans[++j]=nums[i],da=1;
            else ans[j]=nums[i];
        }
    }

    return j + 1;
}
```