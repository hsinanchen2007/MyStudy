### 解题思路
顺序遍历记录每个距离车上负载情况

### 代码

```c
#define MAX_PATH 1001
void comp(void *a, void *b)
{
    int *pA = *(int **)a;
    int *pB = *(int **)b;

    if (pA[1] == pB[1]) {
        return pA[2] - pB[2];
    }

    return pA[1] - pB[1];
}
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    //思路1：暴力搜索，顺序遍历记录每个距离车上负载情况
    int nums[MAX_PATH] = {0}; //记录每个距离上车上负载情况
    //printf("tripsSize:%d\n", tripsSize);
    //qsort(trips, tripsSize, sizeof(int) * 3, comp);
    int n, s, e;
    for (int i = 0; i < tripsSize; i++) {
        n = trips[i][0];
        s = trips[i][1];
        e = trips[i][2];

        //e下车了，不需要加n
        for (int j = s; j < e; j++) {
            nums[j] += n;
            // printf("nums[%d]: %d\n", j, nums[j]);
            if (nums[j] > capacity) {
                return false;
            }
        }
    }

    return true;
}
```