### 解题思路
leetcode官方第三种方法的图形分析法很巧妙。

### 代码

```c
#define MAX_TASK_NUM 26

int compare(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

int leastInterval(char* tasks, int tasksSize, int n){
    int map[MAX_TASK_NUM] = { 0 };
    int i; 
    int maxTaskTime;
    int idleTime;
    for (i = 0; i < tasksSize; i++) {
        map[tasks[i] - 'A']++;
    }
    /* 由大到小排序 */
    qsort(map, MAX_TASK_NUM, sizeof(int), compare);

    maxTaskTime = map[0] - 1;
    idleTime = maxTaskTime * n;
    for (int i = 1; i < 26 && map[i] > 0; i++) {
        idleTime -= ((map[i] < maxTaskTime) ? map[i] : maxTaskTime);
    }
    return (idleTime > 0) ? (idleTime + tasksSize) : tasksSize;
}
```
### 执行结果
执行用时 :52 ms, 在所有 C 提交中击败了62.03%的用户
内存消耗 :6.1 MB, 在所有 C 提交中击败了100.00%的用户