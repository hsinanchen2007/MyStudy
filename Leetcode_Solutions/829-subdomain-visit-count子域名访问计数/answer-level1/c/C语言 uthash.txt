### 解题思路
就是个str hash
![image.png](https://pic.leetcode-cn.com/d70b626e4b58c648707b0d8a1db5ba3c4945bb7429042c222c435bc64f01a7c7-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_BASE_SIZE 300
#define MY_MAX_LEN 120

typedef struct {
    char *str;
    int cnt;
    UT_hash_handle hh;
} MyItem;

typedef struct {
    MyItem *items;
    int cnt;
    int size;
    MyItem *hh_item;
} MyStatus;
void sFree(MyStatus *s)
{
    MyItem *cur = NULL;
    MyItem *tmp = NULL;
    if (s->items == NULL) {
        return;
    }
    HASH_ITER(hh, s->hh_item, cur, tmp) {
        HASH_DEL(s->hh_item, cur);
    }
    free(s->items);
    s->items = NULL;
    return;
}
int sInit(MyStatus *s)
{
    s->size = MY_BASE_SIZE;
    s->items = (MyItem*)calloc(s->size, sizeof(MyItem));
    if (s->items == NULL) {
        printf("sInit s->items == NULL");
        return MY_FAIL;
    }
    s->cnt = 0;
    s->hh_item = NULL;
    return MY_OK;
}
void sAddHash(MyStatus *s, char *str, int cnt)
{
    MyItem *item = NULL;
    HASH_FIND_STR(s->hh_item, str, item);
    if (item != NULL) {
        item->cnt += cnt;
        return;
    }
    item = &s->items[s->cnt];
    item->cnt = cnt;
    item->str = str;
    HASH_ADD_STR(s->hh_item, str, item);
    s->cnt++;
    return;
}
void sAdd(MyStatus *s, char *domain)
{
    int cnt = 0;
    char str[MY_MAX_LEN];
    char *subStr = NULL;
    char *div = ".";
    int curInx = 0;

    if (sscanf(domain, "%d %s", &cnt, str) != 2) {
        printf("sAdd sscanf [%s]\n", domain);
        return;
    }
    curInx = strstr(domain, str) - domain;
    sAddHash(s, &domain[curInx], cnt);
    subStr = strtok(str, div);
    while (subStr != NULL && (curInx + strlen(subStr) < strlen(domain))) {
        curInx += strlen(subStr) + 1;
        sAddHash(s, &domain[curInx], cnt);
        subStr = strtok(NULL, div);
    }
    return;
}
char ** rInit(MyStatus *s, int* returnSize)
{
    int cnt = 0;
    char **rlt = NULL;
    MyItem *cur = NULL;
    MyItem *tmp = NULL;
    rlt = (char**)calloc(s->cnt, sizeof(int*));
    if (rlt == NULL) {
        printf("rInit rlt == NULL\n");
        *returnSize = 0;
        return NULL;
    }
    HASH_ITER(hh, s->hh_item, cur, tmp) {
        rlt[cnt] = (char*)calloc(MY_MAX_LEN, sizeof(char));
        if (rlt[cnt] == NULL) {
             printf("rInit rlt[%d] == NULL\n", cnt);
            *returnSize = 0;
            return NULL;
        }
        sprintf(rlt[cnt], "%d %s", cur->cnt, cur->str);
        cnt++;
    }
    *returnSize = cnt;
    return rlt;
}
char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize){
    int i, ret;
    char **rlt = NULL;
    MyStatus s = { 0 };
    if (cpdomainsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    ret = sInit(&s);
    if (ret != MY_OK) {
        *returnSize = 0;
        return NULL;
    }
    for (i = 0; i < cpdomainsSize; i++) {
        sAdd(&s, cpdomains[i]);
    }
    rlt = rInit(&s, returnSize);
    sFree(&s);
    return rlt;
}
```