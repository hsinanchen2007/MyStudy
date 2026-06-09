### 解题思路
写的一般，一开始少考虑的很多场景，题目理解也不深，出错后缝缝补补才AC，用时和内存都高的不行，仅供参考吧

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 判断是否为叶子节点，即是否还有包含此节点的未染色节点
bool isLeaf(char *** tickets, int ticketsSize, char *curStr, int *ticketsFlag)
{
    int i;
    int flag = true;
    if (ticketsSize == 0) return false;
    for (i = 0; i < ticketsSize; i++) {
        if (ticketsFlag[i] != 1 && (strcmp(tickets[i][0], curStr) == 0 || strcmp(tickets[i][1], curStr) == 0)) {
            flag = false;
            break;
        }
    }
    return flag;
}
int comp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
// 染色车票
int dreawTickets(int *ticketsFlag, char *curStr, char *childStr, char *** tickets, int ticketsSize)
{
    int i;
    for (i = 0; i < ticketsSize; i++) {
        if (ticketsFlag[i] == 0 && strcmp(tickets[i][0], curStr) == 0 && strcmp(tickets[i][1], childStr) == 0) {
            ticketsFlag[i] = 1;
            // 返回染色车票所在的位置是为了路径不对的时候回退染色
            return i;
        }
    }
    return 0;
}
// 判断车票是否都被染色
bool isClear(int ticketsSize, int *ticketsFlag) {
    int i;
    for (i = 0; i < ticketsSize; i++) {
        if (ticketsFlag[i] == 0) {
            return false;
        }
    }
    return true;
}
bool DFS(char *** tickets, int ticketsSize, char **ansArr, int* returnSize, char *curStr, int *ticketsFlag)
{
    int i, j, k;
    bool isTrue = false;
    // 判断节点是否有下一跳，即是否还有包含此节点的未染色节点
    if (isLeaf(tickets, ticketsSize, curStr, ticketsFlag) == true) {
        // 判断车票集合是否全都染色了，如果是代表行程完成，返回true
        if (isClear(ticketsSize, ticketsFlag)) {
            return true;
        }
        // 否则返回false;
        return false;
    }
    // 子节点集合，为了排序
    char **childStr = (char **)malloc(sizeof(char *) * 100);
    int childNum = 0;
    // 遍历车票集合，找出子节点集合
    for (i = 0; i < ticketsSize; i++) {
        if (ticketsFlag[i] != 1 && strcmp(tickets[i][0], curStr) == 0) {
            childStr[childNum] = (char *)malloc(sizeof(char) * 4);
            memcpy(childStr[childNum], tickets[i][1], sizeof(char) * 4);
            childNum++;
        }
    }
    // 子节点按照字符串排序
    qsort(childStr, childNum, sizeof(char *), comp);
    // 依次处理子节点集合中的节点，因为排序过，这样输出的结果就是正确顺序的
    for (i = 0; i < childNum; i++) {
        ansArr[(*returnSize)] = (char *)malloc(sizeof(char) * 4);
        memcpy(ansArr[(*returnSize)], childStr[i], sizeof(char) * 4);
        (*returnSize)++;
        // 染色车票
        j = dreawTickets(ticketsFlag, curStr, childStr[i], tickets, ticketsSize);
        // 深度优先搜索
        isTrue = DFS(tickets, ticketsSize, ansArr, returnSize, childStr[i], ticketsFlag);
        // 如果为true则说明行程完成，否则说明下一跳不应该是该子节点，需要回退结果和染色集合
        if (isTrue) {
            break;
        } else {
            ticketsFlag[j] = 0;
            (*returnSize)--;
        }
    }
    // 如果都被染色返回true，否则返回false
    return isClear(ticketsSize, ticketsFlag);
}
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    char **ansArr = (char **)malloc(sizeof(char *) * 1000);
    *returnSize = 0;
    // 为返回数组申请内存
    ansArr[*returnSize] = (char *)malloc(sizeof(char) * 4);
    // 第一个车站固定是 JFK
    ansArr[*returnSize] = "JFK";
    (*returnSize)++;
    if (ticketsSize == 0) {
        return ansArr;
    }
    // 车票集合染色数组，必须所有车票都被染色才说明旅程全部完成
    int *ticketsFlag = (int *)malloc(sizeof(int) * ticketsSize);
    memset(ticketsFlag, 0, sizeof(int) * ticketsSize);
    // 深度优先搜索
    DFS(tickets, ticketsSize, ansArr, returnSize, ansArr[0], ticketsFlag);

    return ansArr;
}
```