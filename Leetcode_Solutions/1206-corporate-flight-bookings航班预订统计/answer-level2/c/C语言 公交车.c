### 解题思路
看大佬的公交车思路。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    int* answer = (int *)malloc(sizeof(int) * n);
    int* count = (int *)malloc(sizeof(int) * n);
    memset(answer, 0, sizeof(int) * n);
    memset(count, 0, sizeof(int) * n);
    for (int i =0; i < bookingsSize; i++) {
        //如果不包含最后一站，可以下车，如果包含最后一站，只上车不下车
        if (*(*(bookings + i) + 1) != n) {
            *(count + *(*(bookings + i) + 0) - 1) = *(count + *(*(bookings + i) + 0) - 1) + *(*(bookings + i) + 2);
            *(count+(*(*(bookings + i)+1)))=*(count+(*(*(bookings+i)+1)))-*(*(bookings+i)+2);
        } else {
            *(count + *(*(bookings + i) + 0) - 1) = *(count + *(*(bookings + i) + 0) - 1) + *(*(bookings + i) + 2);
        }
    }
    *answer  = *count;
    for (int j = 1;j < n;j++) {
        *(answer + j) = *(answer + j - 1) + *(count+j);
    }
    *returnSize = n;
    return answer;
}
```