### 解题思路

![image.png](https://pic.leetcode-cn.com/5f28055efc19f5b593fd0f114210b588a6ebe4e7bdbf8d122a70aea002986006-image.png)

参考[https://leetcode-cn.com/problems/task-scheduler/solution/621-ren-wu-diao-du-qi-cshi-xian-kuai-su-pai-xu-tan/](https://leetcode-cn.com/problems/task-scheduler/solution/621-ren-wu-diao-du-qi-cshi-xian-kuai-su-pai-xu-tan/)

### 代码

```c
#define ARRSIZE 26

int cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

int leastInterval(char* tasks, int tasksSize, int n)
{
    if (!tasks || tasksSize <= 0) return 0;
    int mallocSize = sizeof(int) * ARRSIZE;
    int* m = (int*)malloc(mallocSize);
    int i;
    memset(m, 0, mallocSize);
    for (i = 0; i < tasksSize; i++) {
        m[tasks[i] - 'A']++;
    }
    qsort(m, ARRSIZE, sizeof(int), cmp);
    int time = 0;
    while (m[0] > 0) {
        i = 0;
        while (i <= n) {
            if (m[0] == 0) {
                break;
            }
            if (i < ARRSIZE && m[i] > 0) {
                m[i]--;
            }
            time++;
            i++;
        }
        qsort(m, ARRSIZE, sizeof(int), cmp);
    }
    free(m);
    return time;
}
```