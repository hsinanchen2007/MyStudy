```
static int get_distance(int arr[], int n);
int minTotalDistance(int **grid, int row, int *col)
{
    if (row == 0 || *col == 0)
        return 0;

    int row_cnt[row];
    int col_cnt[*col];
    memset(row_cnt, 0, sizeof(row_cnt));
    memset(col_cnt, 0, sizeof(col_cnt));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < *col; j++) {
            if (grid[i][j] == 0)
                continue;
            row_cnt[i]++;
            col_cnt[j]++;
        }
    }

    return get_distance(row_cnt, row) + get_distance(col_cnt, *col);
}

static int get_distance(int arr[], int n)
{
    int pre_sum[n];
    pre_sum[0] = arr[0];
    int distance = (n - 1) * arr[0];

    for (int i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i - 1] + arr[i];
        distance += (n - 1 - i) * arr[i];
    }

    int min = distance;
    for (int i = n - 2; i >= 0; i--) {
        distance -= pre_sum[i];
        distance += (pre_sum[n - 1] - pre_sum[i]);
        min = (min < distance) ? min : distance;
    }

    return min;
}
```
