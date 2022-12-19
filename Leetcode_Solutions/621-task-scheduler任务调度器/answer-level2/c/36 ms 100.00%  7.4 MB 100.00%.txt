### 代码

```c
struct Task {
    int kind;
    int num;
};

int ComparTask(const void *a, const void *b)
{
    struct Task sa = *(struct Task *)a;
    struct Task sb = *(struct Task *)b;

    return sb.num - sa.num;
}
int leastInterval(char* tasks, int tasksSize, int n){
    struct Task t[26];
    int i;
    for (i = 0 ; i < 26; i++) {
        t[i].kind = i;
        t[i].num = 0;
    }

    for (i = 0; i < tasksSize; i++) {
        (t[tasks[i] - 'A'].num)++;
    }

    qsort(t, 26, sizeof(struct Task), ComparTask);

    int max = t[0].num;
    int maxNum = 0;
    for (i = 0 ; i < 26; i++) {
         if (t[i].num == max) {
             maxNum++;
         } else {
             break;
         }
    }

    //printf("%d %d", maxNum, max);

    int ret = (n + 1 - maxNum) * (max - 1) + max * maxNum;
    return ret > tasksSize ? ret : tasksSize;
}
```