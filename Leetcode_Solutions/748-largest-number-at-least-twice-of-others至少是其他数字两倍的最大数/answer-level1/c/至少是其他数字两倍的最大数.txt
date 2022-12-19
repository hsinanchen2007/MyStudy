先新建一个数组sort，把nums的内容复制进去，然后用快排降序排列sort数组里的内容，此时sort[0]为最大值，sour[1]为第二大的值，因此只需判断sort[0]是否大于等于两倍的sort[1]即可，大于则查询nums中sort[0]的位置并返回该索引，不满足则返回-1。
代码如下：
```
int cmp(const int *a,const int *b) {
    return -(*(int *)a - *(int *)b);
}
int dominantIndex(int* nums, int numsSize){
    if(numsSize == 0) {
        return -1;
    }
    if(numsSize == 1){
        return 0;
    }
    int *sort = (int*)malloc(numsSize*sizeof(int));
    for(int i = 0;i<numsSize;i++) {
        sort[i] = nums[i];
    }
    qsort(sort,numsSize,sizeof(int),cmp);
    if(sort[0] >= 2*sort[1]) {
        for(int i = 0;i <numsSize;i++) {
            if(nums[i] == sort[0]) {
                return i;
            }
        }
    }
    return -1;

}
```
执行用时 :
4 ms

内存消耗 :
6.9 MB
