### 解题思路
先排序；
后面好理解了

### 代码

```c
int cmq(int*a,int*b){
    return *a-*b;
}

bool isStraight(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmq);
    int zero=0,bug=0;
    for(int i=numsSize-2;i>=0;i--){
        if(nums[i]){
            if(nums[i]==nums[i+1])
                return 0;
            else
                bug+=nums[i+1]-nums[i]-1;
        }
        else zero++;
    }
    return zero>=bug;
}
```