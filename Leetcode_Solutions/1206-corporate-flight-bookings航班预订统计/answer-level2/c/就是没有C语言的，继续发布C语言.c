![image.png](https://pic.leetcode-cn.com/f89f08334654dfa8316ccf4d8c35f88c27e70a804aadb521ef0bd6cdca326cfd-image.png)
```
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    int *ans = (int *)calloc(n, sizeof(int));
    *returnSize = 0;
    int m = bookingsSize;
    //
    int *up = (int *)calloc(n+1, sizeof(int));
    int *down = (int *)calloc(n+1, sizeof(int));
    for (int j = 0; j < m; j++) {
        up[bookings[j][0]] += bookings[j][2];
        down[bookings[j][1]] += bookings[j][2];
    }
    ans[0] = up[1];
    (*returnSize)++;
    for (int i = 2; i < n+1; i++) {
        ans[i-1] = up[i] - down[i-1] + ans[i-2];
        (*returnSize)++;
    }
    free(up);
    free(down);
    return ans;
}

```
