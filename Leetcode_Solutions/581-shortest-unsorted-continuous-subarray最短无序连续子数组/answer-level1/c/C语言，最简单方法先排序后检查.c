### 解题思路
之前的删了，重写的。
1、先进行排序，让数组升序；
2、从前向后，寻找第一个与之前序列不同的元素所在位置begin
3、从后向前遍历 , ,end
4、相减返回begin-end+1。如果已经有序就返回0
### 代码

```c
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int findUnsortedSubarray(int* nums, int numsSize){
    int begin=0;int end=0;
    int *numscpy=(int*)malloc(numsSize*sizeof(int));
    memcpy(numscpy,nums,sizeof(int)*numsSize);
    qsort(numscpy,numsSize,sizeof(int),compare);
    for(int i=0;i<numsSize;i++){
        if(numscpy[i]!=nums[i]){
            begin=i;
            break;
        }
    }
    for(int i=numsSize-1;i>=0;i--){
        if(numscpy[i]!=nums[i]){
            end=i;
            break;
        }
    }
    if(begin==end){
        return 0;
    }
    return end-begin+1;
}
```