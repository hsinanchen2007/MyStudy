### 解题思路
此处撰写解题思路

### 代码

```c

int comp(const void *a,const void *b){
    return *(long*)a-*(long*)b;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k){  //用稳定的排序的方法
long a[numsSize+1][2],i,b;
for(i=0;i<numsSize;i++){
    a[i][0]=nums[i]; a[i][1]=i;
}
qsort(a[0],numsSize,sizeof(long)*2,comp);
for(i=0;i<numsSize-1;i++){
    if(a[i][0]==a[i+1][0]){
        b=a[i][1]-a[i+1][1];
        if(abs(b)<=k) return true;
    }
}
return false;
}
```