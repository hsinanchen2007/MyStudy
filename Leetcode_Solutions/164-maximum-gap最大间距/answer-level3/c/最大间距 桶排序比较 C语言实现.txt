参考其他桶排序的原理。

使用桶间比较思路，只需要记录桶内的最值就可以了。





```c
#define ID_MIN      0
#define ID_MAX      1
#define ID_VALID    2

static inline void GetEdgeValue(int *nums, int numsSize, int *min, int *max)
{
    *min = *max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (*max < nums[i]) {
            *max = nums[i];
        }
        if (*min > nums[i]) {
            *min = nums[i];
        }
    }
}

static inline void bucketAdd(int num, int *bucket)
{
    if (bucket[ID_VALID] == 0) {
        bucket[ID_MIN] = bucket[ID_MAX] = num;
        bucket[ID_VALID] = 1;
        return;
    }
    if (bucket[ID_MIN] > num) {
        bucket[ID_MIN] = num;
    }
    if (bucket[ID_MAX] < num) {
        bucket[ID_MAX] = num;
    }
}

static inline int bucketGetMaxDistance(int *bucket, int bucketCount)
{
    int i, max = 0, last_max, *p, *end;
    last_max = bucket[ID_MAX];
    end = bucket + bucketCount * 3;
    for (p = bucket + 3; p < end; p += 3) {
        if (p[ID_VALID]) {
            if (p[ID_MIN] - last_max > max) {
                max = p[ID_MIN] - last_max;
            }
            last_max = p[ID_MAX];
        }
    }
    return max;
}

int bucketMax(int *nums, int numsSize, int min, int bucketCount, int bucketGap)
{
    int max = 0;
    // 申请桶数组，每个桶放三个信息，最大值，最小值，和是否有效（是否存入过数据）
    int *p = calloc(sizeof(int) * 3, bucketCount);
    if (p == NULL) {
        LOG("out of memory");
        return -1;
    }
    // 依 (num-min)/gap作为桶的编号或者索引，将信息加入对应桶中。
    for (int i = 0; i < numsSize; i++) {
        bucketAdd(nums[i], p + ((nums[i] - min) / bucketGap) * 3);
    }
    // 在桶间查找最大差值 max(bucket[i].min - bucket[i-n].max), i-n为前一个有效的桶，所有桶都有数据情况下n始终为1。
    max = bucketGetMaxDistance(p, bucketCount);
    // 释放内存资源依然是个好习惯。
    free(p);
    return max;
}

int maximumGap(int *nums, int numsSize)
{
    int max, min, bucketGap, bucketCount, *p;
    if (numsSize <= 1) {
        return 0;
    }
    // 获取最大最小值。
    GetEdgeValue(nums, numsSize, &min, &max);
    // 如果max min差距小于1，说明无需继续了
    if (max - min <= 1) {
        return (max - min);
    }
    // 获取 桶间平均差距，向下取整即可
    bucketGap = (max - min) / (numsSize - 1);
    // 如果 差距为0，那么至少也是1吧。
    if (bucketGap == 0) {
        bucketGap = 1;
    }
    // 获取桶的数量
    bucketCount = (max - min + bucketGap) / bucketGap;
    return bucketMax(nums, numsSize, min, bucketCount, bucketGap);
}

```
