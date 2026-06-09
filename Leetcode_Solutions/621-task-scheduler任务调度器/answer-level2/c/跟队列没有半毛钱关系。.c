### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX 26
int leastInterval(char* tasks, int tasksSize, int n){
    int shortestTime = 0;
    int i;
    int index;
    int maxFre = 0;
    int maxCount = 0;
    int maxNum = 0;
    int hashMap[MAX] = { 0 };

    for (i = 0; i < tasksSize; i++) {
        index = tasks[i] - 'A';
        hashMap[index]++;
    }

    for (i = 0; i < MAX; i++) {
        if (hashMap[i] >= maxFre) {
            maxFre = hashMap[i];
        }
    }

    for (i = 0; i < MAX; i++) {
        if (hashMap[i] == maxFre) {
            maxCount++;
        }
    }

    //printf("maxFre = %d, n = %d, maxCount = %d.", maxFre, n, maxCount);

    shortestTime = (maxFre - 1) * (n + 1) + maxCount;

    if (tasksSize > shortestTime) {
        shortestTime = tasksSize;
    }

    return shortestTime;
}
```