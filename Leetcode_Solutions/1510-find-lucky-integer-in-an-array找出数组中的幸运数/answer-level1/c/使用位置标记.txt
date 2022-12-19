### 解题思路
直接使用位置标记即可

### 代码

```c
#define MAX_SIZE 500
int findLucky(int *arr, int arrSize)
{
    int sum[MAX_SIZE + 1];

    memset(sum, 0x0, sizeof(sum));
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > MAX_SIZE) {
            continue;
        }
        sum[arr[i]]++;
    }

    for (int i = MAX_SIZE; i > 0; i--) {
        if (sum[i] == i) {
            return i;
        }
    }
    return -1;
}
```