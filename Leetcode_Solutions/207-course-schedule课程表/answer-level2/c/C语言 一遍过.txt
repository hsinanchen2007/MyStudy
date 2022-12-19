### 解题思路
图拓扑排序

![image.png](https://pic.leetcode-cn.com/cc1f82149e22f8f6719913c2d501510ae3ec577cde215d52400a7a747da53c63-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_BASE_SIZE 512

struct MyItem {
    struct MyItem **list;
    int cnt;
    int inCnt;
    int size;
    int known;
    int num;
};
struct MyMap {
    int numCourses;
    struct MyItem *items;
};
void itemFree(struct MyItem *item)
{
    if (item == NULL) {
        return;
    }
    if (item->list != NULL) {
        free(item->list);
        item->list = NULL;
    }
    item->cnt = item->size = 0;
    return;
}
int itemInit(struct MyItem *item, int num)
{
    item->size = MY_BASE_SIZE;
    item->list = (struct MyItem**)calloc(item->size, sizeof(struct MyItem*));
    if (item->list == NULL) {
        return MY_FAIL;
    }
    item->cnt = 0;
    item->inCnt = 0;
    item->known = 0;
    item->num = num;
    return MY_OK;
}
int itemAdd(struct MyItem *item, struct MyItem *toItem)
{
    if (item->cnt == item->size) {
        printf("buffer is not enough");
        return MY_FAIL;
    }
    item->list[item->cnt] = toItem;
    item->cnt++;
    toItem->inCnt++;
    return MY_OK;
}
void mapFree(struct MyMap *map)
{
    int i;
    if (map == NULL) {
        return;
    }
    for (i = 0; i < map->numCourses; i++) {
        itemFree(&map->items[i]);
    }
    return;
}
int mapInit(struct MyMap *map, int numCourses)
{
    int i, ret;
    map->numCourses = numCourses;
    map->items = (struct MyItem*)calloc(map->numCourses, sizeof(struct MyItem));
    if (map->items == NULL) {
        return MY_FAIL;
    }
    for (i = 0; i < numCourses; i++) {
        ret = itemInit(&map->items[i], i);
        if (ret != MY_OK) {
            mapFree(map);
            return MY_FAIL;
        }
    }
    return MY_OK;
}
int procMap(struct MyMap *map, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    int i, ret;
    int from, to;
    for (i = 0; i < prerequisitesSize; i++) {
        from = prerequisites[i][0];
        to = prerequisites[i][1];
        ret = itemAdd(&(map->items[from]), &(map->items[to]));
        if (ret != MY_OK) {
            return MY_FAIL;
        }
    }
    return MY_OK;
}
struct MyItem* pGetNoInItem(struct MyMap *map)
{
    int i;
    struct MyItem* ret = NULL;
    for (i = 0; i < map->numCourses; i++) {
        ret = &map->items[i];
        if (ret->known == 0 && ret->inCnt == 0) {
            ret->known = 1;
            return ret;
        }
    }
    return NULL;
}
void pItemTo(struct MyItem* item)
{
    int i;
    struct MyItem* to = NULL;
    for (i = 0; i < item->cnt; i++) {
        to = item->list[i];
        to->inCnt--;
    }
    return;
}
int proccess(struct MyMap *map)
{
    int i;
    struct MyItem *item = NULL;
    for (i = 0; i < map->numCourses; i++) {
        item = pGetNoInItem(map);
        if (item == NULL) {
            return MY_FAIL;
        }
        pItemTo(item);
    }
    return MY_OK;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int ret;
    bool rlt;
    struct MyMap map;
    ret = mapInit(&map, numCourses);
    if (ret != MY_OK) {
        return false;
    }
    ret = procMap(&map, prerequisites, prerequisitesSize, prerequisitesColSize);
    if (ret != MY_OK) {
        mapFree(&map);
        return false;
    }
    rlt = proccess(&map) == MY_OK;
    mapFree(&map);
    return rlt;
}
```