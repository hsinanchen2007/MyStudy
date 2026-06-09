### 解题思路
基于207题
![image.png](https://pic.leetcode-cn.com/c0e9c6de73c6c5d06a4c34393cdc09fdca9458f3d5c594477a7f414f0725b71a-image.png)

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
struct MyRlt {
	int *rlt;
	int cnt;
	int size;
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
        from = prerequisites[i][1];
        to = prerequisites[i][0];
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
int proccess(struct MyMap *map, struct MyRlt *rlt)
{
    int i;
    struct MyItem *item = NULL;
    for (i = 0; i < map->numCourses; i++) {
        item = pGetNoInItem(map);
        if (item == NULL) {
            return MY_FAIL;
        }
		rlt->rlt[rlt->cnt++] = item->num;
        pItemTo(item);
    }
    return MY_OK;
}
void rltFree(struct MyRlt *rlt)
{
	if (rlt == NULL) {
		return;
	}
	if (rlt->rlt != NULL) {
		free(rlt->rlt);
		rlt->rlt = NULL;
	}
	return;
}
int rltInit(struct MyRlt *rlt, int numCourses)
{
	rlt->size = numCourses;
	rlt->rlt = (int*)calloc(rlt->size, sizeof(int));
	if (rlt->rlt == NULL) {
		return MY_FAIL;
	}
	rlt->cnt = 0;
	return MY_OK;
}
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int ret;
    struct MyRlt rlt;
    struct MyMap map;
	ret = rltInit(&rlt, numCourses);
    ret |= mapInit(&map, numCourses);
    if (ret != MY_OK) {
		rltFree(&rlt);
		mapFree(&map);
        return false;
    }
    ret = procMap(&map, prerequisites, prerequisitesSize, prerequisitesColSize);
    if (ret != MY_OK) {
		rltFree(&rlt);
        mapFree(&map);
        return false;
    }
    ret = proccess(&map, &rlt);
    if (ret != MY_OK) {
		*returnSize = 0;
		rltFree(&rlt);
		mapFree(&map);
		return NULL;
	};
    mapFree(&map);
	*returnSize = rlt.cnt;
    return rlt.rlt;
}
```