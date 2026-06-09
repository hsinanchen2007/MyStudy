### 解题思路
此处撰写解题思路
1、根据DFS算法找指定level朋友；
2、把朋友看的视频保存并排序，排序算法：先比较频率，频率相等则比较字符串大小；
3、按顺序输出结果即可。

### 代码
代码比较多，还可以把变量优化一下，凑合看一下吧。

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_LEN 10240
#define FREAND_LEN 100

typedef struct {
    char result[10];
    int count;
} watchedVideo;

watchedVideo g_video[MAX_LEN] = {0};

int g_friend[FREAND_LEN] = {0};
int g_pos = 0;

void dfs(int** friends, int friendsSize, int* friendsColSize, int id, int index, int level, int *visit) {
    int i;

    if (index == level) {
        for (i = 0; i < friendsColSize[id]; i++) {
            if (visit[friends[id][i]] == 0) {
                visit[friends[id][i]] = 1;
                g_friend[g_pos++] = friends[id][i];
            }
        }

        return;
    }
    /* 这里一定要先标记再DFS（存在二级朋友也是一级朋友的场景），否则用例只能通过一部分 */
    visit[id] = 1;
    for (i = 0; i < friendsColSize[id]; i++) {
        if (visit[friends[id][i]] == 0) {
            visit[friends[id][i]] = 1;
        }
    }

    for (i = 0; i < friendsColSize[id]; i++) {
        dfs(friends, friendsSize, friendsColSize, friends[id][i], index + 1, level, visit);
    }
}

bool isVideoExist(char *str, int num) {
    int i;

    for (i = 0; i < num; i++) {
        if (strcmp(str, g_video[i].result) == 0) {
            g_video[i].count++;
            return true;
        }
    }

    return false;
}

int cmp(watchedVideo *a, watchedVideo*b) {
    if (a->count > b->count) {
        return 1;
    } 

    if (a->count == b->count) {
        if (strcmp(a->result, b->result) > 0) {
            return 1;
        }
    }

    return 0;
}

char ** watchedVideosByFriends(char *** watchedVideos, int watchedVideosSize, int* watchedVideosColSize, int** friends, int friendsSize, int* friendsColSize, int id, int level, int* returnSize){
    char **res = NULL;
    int visit[FREAND_LEN] = {0};
    int i, j, temp;

    g_pos = 0;
    memset(g_friend, 0, sizeof(g_friend));
    dfs(friends, friendsSize, friendsColSize, id, 1, level, visit);

    *returnSize = 0;
    memset(g_video, 0, sizeof(g_video));
    for (i = 0; i < g_pos; i++) {
        temp = g_friend[i];
        for (j = 0; j < watchedVideosColSize[temp]; j++) {
            if (isVideoExist(watchedVideos[temp][j], *returnSize) == false) {
                strcpy(g_video[(*returnSize)++].result, watchedVideos[temp][j]);
            }
        }
    }

    qsort(g_video, *returnSize, sizeof(watchedVideo), cmp);
    res = (char **)malloc(sizeof(char *) * MAX_LEN);
    for (i = 0; i < *returnSize; i++) {
        res[i] = (char *)malloc(sizeof(char) * 10);
        strcpy(res[i], g_video[i].result);
    }

    return res;
}
```