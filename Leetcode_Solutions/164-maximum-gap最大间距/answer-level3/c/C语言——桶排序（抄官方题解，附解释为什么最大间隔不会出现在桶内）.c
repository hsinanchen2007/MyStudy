### 解题思路
桶排序。
1，C语言声明结构体函的时候不能初始化！
2，好多人不明白为什么只考虑桶间间隔，而不考虑桶内间隔。
其实在定义桶大小和个数的时候，就保证了分配之后桶内相邻间隔必然小于有效的桶间数的最大间隔。
桶的大小：（最大数-最小数）/（数组大小-1）。（如果桶大小为0，则设为1）
桶的个数：（最大数-最小数）/ 桶的大小 +1。

这是可以证明的，我们用反证法来解释。
假设存在一个这样一个桶，桶内数的间隔大于有序数组内相邻数的最大间隔，那就说明有序数组内相邻数的最大间隔必然小于桶的大小。
也就是说有序数组内所有相邻数的间隔都小于桶的大小，换句话说，数组的大小必然大于桶的个数！
这是不可能的。
因为桶的个数定义为（最大数-最小数）/ 桶的大小 +1，这个定义保证即使所有相邻数间隔为1（此时桶大小为1），桶的个数也才等于数组个数，正好一个桶一个数。而一旦存在相邻数间隔大于1，假设现在桶的大小还是1，那么此时桶的个数就必然大于数组个数。这与之前的假设得出的结论相悖。
证毕！

### 代码

```c
#define MAXINTEGER 2147483647
#define MININTEGER 0

#define MAX(a,b) ((a>b) ? a : b)
#define MIN(a,b) ((a<b) ? a : b)

typedef struct{
    bool used;
    int maxval;
    int minval;
}Bucket; //C语言结构体定义不能初始化！

int maximumGap(int* nums, int numsSize){
    if(numsSize < 2)
        return 0;
    
    Bucket* buckets;
    int bucketSize, bucketNum, bucketIndex;
    int nmax=MININTEGER, nmin=MAXINTEGER;
    int premax, maxdiff, i;

    for(i=0; i<numsSize; i++){
        nmax = MAX(nmax, nums[i]);
        nmin = MIN(nmin, nums[i]);
    }

    if(nmax == nmin)
        return 0;
    else{
        bucketSize = MAX(1, (nmax - nmin) / (numsSize-1));
        bucketNum = (nmax - nmin) / bucketSize + 1;
    }

    buckets = (Bucket *)malloc(sizeof(Bucket) * bucketNum);
    for(i=0; i<bucketNum; i++){
        buckets[i].used = false;
        buckets[i].maxval = MININTEGER;
        buckets[i].minval = MAXINTEGER;
    }

    for(i=0; i<numsSize; i++){
        bucketIndex = (nums[i] - nmin) / bucketSize;
        buckets[bucketIndex].used = true;
        buckets[bucketIndex].maxval = MAX(buckets[bucketIndex].maxval, nums[i]);
        buckets[bucketIndex].minval = MIN(buckets[bucketIndex].minval, nums[i]);
    }

    premax = nmin;
    maxdiff = 0;
    for(i=0; i<bucketNum; i++){
        if(buckets[i].used == false)
            continue;
        
        maxdiff = MAX(maxdiff, buckets[i].minval - premax);
        premax = buckets[i].maxval;
    }

    return maxdiff;
}
```