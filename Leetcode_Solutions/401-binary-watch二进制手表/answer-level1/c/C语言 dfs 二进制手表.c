### 解题思路
`led[10]` 表示10个灯分别代表的数字
`visited[10]` 每一次遍历，一个灯只能亮一次

`void dfs(int num, char **res, int *returnSize, int hour, int min, int pos)`
`num` 还要亮几个灯
`hour` 目前亮的灯表示的小时
`min` 目前亮的灯表示的分钟
`pos` 目前遍历到led数组的什么位置，因为一个灯只能用一次，所以下次遍历要从pos+1位置遍历

### 代码

```c
#define MAX_SIZE 1024
int led[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
int visited[10] = {0};

void dfs(int num, char **res, int *returnSize, int hour, int min, int pos)
{
    if (num == 0) { // 得到一个有效时间
        //
        if (hour > 9) {
            res[*returnSize] = (char *)calloc(6, sizeof(char));
        } else {
            res[*returnSize] = (char *)calloc(5, sizeof(char));
        }
        if (min > 9) {
            sprintf(res[*returnSize], "%d:%d", hour, min);
        } else {
            sprintf(res[*returnSize], "%d:0%d", hour, min);
        }
        (*returnSize)++;
        return;
    }


    for (int i = pos; i < 10; i++) {
        /*
        if (visited[i] == 0) {
            visited[i] = 1;
            if (i >= 4 && min + led[i] < 60) { // min
                dfs(num - 1, res, returnSize, hour, min + led[i], i + 1);
            } else if (i < 4 && hour + led[i] < 12) {
                dfs(num - 1, res, returnSize, hour + led[i], min, i + 1);
            }
            visited[i] = 0;
        }
        */

        if (visited[i] == 1) {
            continue;
        }
        if (i >= 4 && min + led[i] < 60) { // min
            visited[i] = 1;
            dfs(num - 1, res, returnSize, hour, min + led[i], i + 1);
            visited[i] = 0;
        } else if (i < 4 && hour + led[i] < 12) {
            visited[i] = 1;
            dfs(num - 1, res, returnSize, hour + led[i], min, i + 1);
            visited[i] = 0;
        }

    }
}

char ** readBinaryWatch(int num, int* returnSize){
    char **res = (char **)malloc(MAX_SIZE * sizeof(char *));

    *returnSize = 0;
    dfs(num, res, returnSize, 0, 0, 0);
    
    return res;
}
```