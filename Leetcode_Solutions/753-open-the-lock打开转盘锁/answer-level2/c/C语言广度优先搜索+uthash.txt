### 解题思路
速度不快，空间也不占优，但是好歹是写出来了，真是费劲，将已经查过的点加入deadends表这点没想到
一开始的想法就是暴力用广度优先搜索遍历所有可能的节点，但是超时，然后又想差一遍存在队列中的扫描过的节点找是否有重复的，剪枝的想法是对的，但是效率太低了。
正确的做法是将查过的点加入deadends表，但是其实遍历这个表也是不现实的也是会超时。
既然如此我就改用哈希表存储deadends节点，查找过的点也加入这个哈希表中，这样一来就不超时了。

### 代码

```c
// 下方是uthash的结构，没什么特殊的，注意字符串是用HASH_ADD_STR
struct hash_node {
    char name[5];
    UT_hash_handle hh;
};
struct hash_node *g_hash = NULL;

struct hash_node *findNode (char *name) {
    struct hash_node *s;
    HASH_FIND_STR(g_hash, name, s);
    return s;
}
void addNode (char *name) {
    struct hash_node *s;
    HASH_FIND_STR(g_hash, name, s);
    if (s == NULL) {
        s = (struct hash_node*)malloc(sizeof(struct hash_node));
        strcpy(s->name, name);
        HASH_ADD_STR(g_hash, name, s);
    }
    return;
}
void deleteAll() {
    struct hash_node *current, *tmp;
    HASH_ITER(hh, g_hash, current, tmp) {
        HASH_DEL(g_hash, current);
        free(current);
    }
    return;
}
// 获取下面几个节点
char **getNextStr (int site, char *ori)
{
    char **ret = (char **)malloc(sizeof(char*) * 2);
    int num = ori[site] - '0';
    int plus, minus;
    plus = (num + 1) % 10;
    if (num != 0) {
        minus = num - 1;
    } else if (num == 0){
        minus = 9;
    }
    ret[0] = (char *)malloc(sizeof(char) * 5);
    ret[1] = (char *)malloc(sizeof(char) * 5);
    strcpy(ret[0], ori);
    strcpy(ret[1], ori);
    ret[0][site] = plus + 48;
    ret[1][site] = minus + 48;
    return ret;
}

void bfs(char **queue, char * target, int start, int end, int *level, int *ans)
{
    int qLen = end - start;
    int startFlag = start;
    int endFlag = end;
    // 队列为空则退出，几乎是所有广度优先搜索的退出条件
    if (qLen == 0) {
        return;
    }
    // 层次++
    (*level)++;
    int i, j, k;
    // 遍历该层节点
    for (i = startFlag; i < endFlag; i++) {
        // 如果在哈希表中，则跳过
        if (findNode(queue[i]) != NULL) {
            start++;
            continue;
        }
        // 如果是目标节点，记录结果并返回
        if (strcmp(queue[i], target) == 0) {
            *ans = (*level);
            return;
        }
        // 将子节点加入队列，注意要判断新增节点是否已经查过，即是否在哈希表中
        for (j = 0; j < 4; j++) {
            char **temp = getNextStr(j, queue[i]);
            if (findNode(temp[0]) == NULL) {
                queue[end++] = temp[0];
            }
            if (findNode(temp[1]) == NULL) {
                queue[end++] = temp[1];
            }
        }
        start++;
        // 将该节点加入哈希表
        addNode(queue[i]);
    }
    // 继续广度优先搜索
    bfs(queue, target, start, end, level, ans);
    return;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    // 用于广度优先搜索的模拟队列的字符串数组
    char **queue = (char **)malloc(sizeof(char *) * 50000);
    int i;
    // 将deadends表的内容加入哈希表
    for (i = 0; i < deadendsSize; i++) {
        addNode(deadends[i]);
    }
    // 根节点入队
    queue[0] = (char *)malloc(sizeof(char) * 5);
    queue[0] = "0000";
    int start = 0;
    int end = 1;
    int level = 0;
    int ans = -1;
    // 广度优先搜索
    bfs(queue, target, start, end, &level, &ans);
    if (ans > 0) {
        ans -= 1;
    }
    deleteAll();
    return ans;
}
```