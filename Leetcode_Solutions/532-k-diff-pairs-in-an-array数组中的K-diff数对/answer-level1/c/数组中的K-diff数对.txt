### 解题思路
1. 先进行排序
2. 把k=0的情况单列出来，循环求数对，如果有重复的1，1，1，1情况，ans只加一次
3. 如果k！=0，把数组中的重复元素删除，之后在i+1~i+k中寻找符合的数

### 代码

```c
int cmp(int *a,int *b){
    return *a>*b;
}
int findPairs(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof(int),cmp);
    int i=1,j=0,size,ans=0;
    if(k==0){
        for(i=1;i<numsSize;i++){
            if(i<numsSize&&nums[i]==nums[i-1]) ans++;
            while(i<numsSize&&nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
    for(i=1;i<numsSize;i++){
        if(nums[i]==nums[i-1]) j++;
        else nums[i-j]=nums[i];
    }
    size=i-j;
    for(i=0;i<size;i++){
        for(j=i+1;j<=i+k&&j<size;j++){
            if(nums[j]-nums[i]==k) ans++;
        }
    }
    return ans;
}
```