### 解题思路
此处撰写解题思路
300个节点存储5分钟每秒的次数

记录：当前时间和上次的时间不相等时，肯定已经过了至少一个5分钟了，清空之前的计算，如果相等就累计
获取：对比上次记录的时间，小于300的就是5分钟之内的，累加起来输出

记录的复杂度O(1), 获取的复杂度O(n), 空间复杂度O(n), n为时长。


### 代码

```c
typedef struct {
    int cnt[300];
    int last_t[300];
} HitCounter;

/** Initialize your data structure here. */

HitCounter* hitCounterCreate() {
    HitCounter *res;
    res = (HitCounter *)malloc(sizeof(HitCounter));
    memset(res, 0, sizeof(HitCounter));
    return res;
}

/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {
    int p;

    p = timestamp % 300;
    if (obj->last_t[p] != timestamp) {
        obj->last_t[p] = timestamp;
        obj->cnt[p] = 1;
    } else {
        obj->cnt[p]++;
    }
}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) {
    int sum;
    sum = 0;
    for (int i = 0; i < 300; i++) {
        if (timestamp - obj->last_t[i] < 300) {
            sum += obj->cnt[i];
        }
    }
    return sum;
}

void hitCounterFree(HitCounter* obj) {
    free(obj);
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 
 * int param_2 = hitCounterGetHits(obj, timestamp);
 
 * hitCounterFree(obj);
*/
```