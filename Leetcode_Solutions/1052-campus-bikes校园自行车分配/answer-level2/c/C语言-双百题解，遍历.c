1、将所有自行车加入队列；
2、计算每个自行车距离最近的工人，把自行车分配给该工人；
3、如果自行车分配的工人已经分配了自行车，且该自行车距离该工人的距离小于之前已经分配的距离，则更新，把已经分配的自行车重新放回队列；
4、如果自行车分配的工人已经分配了自行车，且该自行车距离该工人的距离等于之前等于分配的距离，计算该工人对应的自行车ID是不是小于已经分配自行车ID，满足则更新，把已经分配的自行车重新放回队列；
5、如果自行车分配的工人已经分配了自行车，且该自行车距离该工人的距离等于之前已经分配的距离，计算该自行车ID分配的工人ID是否小于已经分配的工人ID，满足则更新，把已经分配的自行车重新放回队列；
![image.png](https://pic.leetcode-cn.com/c3ea79bc62e7ce108d09f3b84f3815ed5d33de7dcca4051b875beced02f2456f-image.png)

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXLEN 2000
int *g_Color = NULL;
int *g_res = NULL;
int g_que[MAXLEN] = {0};
int *g_distanse = NULL;
int *g_Bike = NULL;
int g_head = 0;
int g_tail = 0;
void PushQue(int id)
{
    if(g_Color[id] == 1) {
        return;
    }
    g_Color[id] = 1;
    g_que[g_tail++] = id;
    return;
}

void PopQue(int *id)
{
    *id = g_que[g_head++];
    return;
}

int GetNum()
{
    return g_tail - g_head;
}

void bfs(int** workers, int workersSize, int* workersColSize,  int** bikes, int bikesSize, int id)
{
    int min = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < workersSize; i++) {
        int distance = abs(workers[i][0] - bikes[id][0]) + abs(workers[i][1] - bikes[id][1]);
        if (distance < min ) {
            if (g_distanse[i] > distance) {
                min = distance;
                minIndex = i;
            }else if (g_distanse[i] == distance && i < g_Bike[id]) {//距离相同，但是自行车ID更小
                min = distance;
                minIndex = i;
            }else if (g_distanse[i] == distance && id < g_res[i]) {//距离相同，但是工人ID更小
                min = distance;
                minIndex = i;
            }
        }
    }
    //所有人都分配了自行车，该自行车距离所有人都远
    if (min == INT_MAX) {
        return;
    }
    /*如果之前已经分配自行车，当前发现更合理的，需要将已经放入的自行车拿出来重新加入队列，并去除颜色*/
    if(g_res[minIndex] != INT_MAX) {
        g_Color[g_res[minIndex]] = 0;
        PushQue(g_res[minIndex]);
    }
    g_res[minIndex] = id; 
    g_Bike[id] = minIndex;
    g_distanse[minIndex] = min;
    return;
}
int* assignBikes(int** workers, int workersSize, int* workersColSize, int** bikes, int bikesSize, int* bikesColSize, int* returnSize){
    g_head = 0;
    g_tail = 0;
    memset(g_que,0,sizeof(int) * MAXLEN);

    g_Color = malloc(sizeof(int *) * bikesSize);
    memset(g_Color,0,sizeof(int *) * bikesSize);

    g_res = malloc(sizeof(int *) * workersSize);
    memset(g_res,0,sizeof(int *) * workersSize);

    g_Bike = malloc(sizeof(int *) * bikesSize);
    memset(g_Bike,0,sizeof(int *) * bikesSize);

    g_distanse = malloc(sizeof(int *) * workersSize);
    for(int i = 0; i < workersSize; i++) {
        g_res[i] = INT_MAX;
        g_distanse[i] = INT_MAX;
    }

    /*所有自行车ID加入队列*/
    for(int i = 0; i < bikesSize; i++) {
        PushQue(i);
    }
    
    while(g_tail > g_head) {
        int num = GetNum();
        for(int i = 0; i < num; i++) {
            int id;
            PopQue(&id);
            bfs(workers, workersSize, workersColSize, bikes, bikesSize, id);
        }
    }
    free(g_Color);
    free(g_distanse);
    free(g_Bike);
    *returnSize = workersSize;
    return g_res;
}
```
