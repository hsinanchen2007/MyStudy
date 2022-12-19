### 解题思路
此处撰写解题思路

### 代码

```c
int cmq(const void *ca, const void *cb){
	return *(int*)ca - *(int*)cb;
}
int findLHS(int* nums, int numsSize){
    if(numsSize<2)
        return 0;
    qsort(nums,numsSize,sizeof(int),cmq);
    int max=0,t=*nums,j=0,*map=(int*)calloc(numsSize*2,sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(t==nums[i])
            map[j]++;        
        else if(t==nums[i]-1)
            map[++j]++;            
        else
            map[j+=2]++;            
        t=nums[i];
    }
    for(int i=0;i<numsSize*2-1;i++)
        if(map[i]&&map[i+1])    
            max=max>(map[i]+map[i+1])?max:(map[i]+map[i+1]);
    return max;
}
```