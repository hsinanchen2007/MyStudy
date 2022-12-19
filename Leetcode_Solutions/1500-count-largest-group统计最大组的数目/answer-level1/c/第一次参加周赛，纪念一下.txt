### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_LEM 1000

int caculate(int num)
{
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int countLargestGroup(int n)
{
    int tmp[MAX_LEM] = { 0 };
    int index;
    int end = MAX_LEM - 1;
    int max = 1;

    for (int i = 1; i <= n; i++) {
        index = caculate(i);
        tmp[index]++;
    }

    qsort(tmp, MAX_LEM, sizeof(int), cmp);
    while (tmp[end] == tmp[end - 1]) {
        max++;
        end--;
    }

    return max;
}
```