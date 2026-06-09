没找到C语言的写法，参考官方题解的思路，弄2个hash表实现了一下，分享给各位。
注：那个obj可以不使用，两个hash表直接用全局变量，很省事。
执行结果：通过
显示详情
执行用时 :164 ms, 在所有 C 提交中击败了97.56%的用户
内存消耗 :35.1 MB, 在所有 C 提交中击败了100.00%的用户
```
typedef struct a {
    int idx;
    char station[11];
    int time;
    UT_hash_handle hh;
} IdInfo;
typedef struct b {
    char station[21]; /* 进站+出站字符串 */
    double sum;
    int num;
    UT_hash_handle hh;
} StationInfo;
typedef struct {
    int val;  /* 未使用 */
} UndergroundSystem;
IdInfo *g_map1;
StationInfo *g_map2;
UndergroundSystem* undergroundSystemCreate()
{
    g_map1 = NULL;
    g_map2 = NULL;
    return NULL;
}
void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t)
{
    IdInfo *h;
    HASH_FIND_INT(g_map1, &id, h);
    if (h == NULL) {
        h = calloc(1, sizeof(IdInfo));
        h->idx = id;
        strcpy(h->station, stationName);
        h->time = t;
        HASH_ADD_INT(g_map1, idx, h);
    } else {
        strcpy(h->station, stationName);
        h->time = t;
    }
}
void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t)
{
    char name[21] = {0};
    IdInfo *h1;
    StationInfo *h2;
    HASH_FIND_INT(g_map1, &id, h1);
    strcpy(name, h1->station);
    strcat(name, stationName);
    HASH_FIND_STR(g_map2, name, h2);
    if (h2 == NULL) {
        h2 = calloc(1, sizeof(StationInfo));
        strcpy(h2->station, name);
        h2->sum += (t - h1->time);
        h2->num++;
        HASH_ADD_STR(g_map2, station, h2);
    } else {
        h2->sum += (t - h1->time);
        h2->num++;
    }
    HASH_DEL(g_map1, h1); /* 此人已出站，进站信息已无用 */
    free(h1);
}
double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation)
{
    StationInfo *h2; 
    char name[21] = {0};
    strcpy(name, startStation);
    strcat(name, endStation);
    HASH_FIND_STR(g_map2, name, h2);
    if (h2 == NULL) {
        return 0;
    }
    return (h2->sum / h2->num);
}
void undergroundSystemFree(UndergroundSystem* obj)
{
    IdInfo *h1, *tmp1;
    HASH_ITER(hh, g_map1, h1, tmp1) {
        HASH_DEL(g_map1, h1);
        free(h1);
    }
    StationInfo *h2, *tmp2;
    HASH_ITER(hh, g_map2, h2, tmp2) {
        HASH_DEL(g_map2, h2);
        free(h2);
    }
}
```
