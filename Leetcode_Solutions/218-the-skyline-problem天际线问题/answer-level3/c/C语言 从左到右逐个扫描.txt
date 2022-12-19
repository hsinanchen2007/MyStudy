### 解题思路
每个建筑分为左open边和右close边，从左到右逐个处理所有的边即可
算是一种解法吧
![image.png](https://pic.leetcode-cn.com/a8c6bf7a93070e1816c82e2f88b9a4a0409a82f2fb6fc7e4a2692031119e7843-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MY_OK 0
#define MY_FAIL (-1)
#define MY_MAX 20000

#define MY_2 2

#define MY_OPEN 1
#define MY_CLOSE 2

typedef struct {
    int **rlt;
    int cnt;
    int *returnColumnSizes;
} MyRlt;
void rFree(MyRlt *r)
{
    int i;
    if (r->rlt != NULL) {
        for (i = 0; i < MY_MAX; i++) {
            if (r->rlt[i] != NULL) {
                free(r->rlt[i]);
                r->rlt[i] = NULL;
            }
        }
        r->rlt = NULL;
    }
    return;
}
int rInit(MyRlt *r)
{
    int i;
    r->rlt = (int**)calloc(MY_MAX, sizeof(int*));
    if (r->rlt == NULL) {
        return MY_FAIL;
    }
    r->returnColumnSizes = (int*)calloc(MY_MAX, sizeof(int));
    if (r->returnColumnSizes == NULL) {
        rFree(r);
        return MY_FAIL;
    }
    for (i = 0; i < MY_MAX; i++) {
        r->rlt[i] = (int*)calloc(MY_2, sizeof(int));
        if (r->rlt[i] == NULL) {
            rFree(r);
            return MY_FAIL;
        }
        r->returnColumnSizes[i] = MY_2;
    }
    r->cnt = 0;
    return MY_OK;
}
void rAddOne(MyRlt *r, int pos, int h)
{
    r->rlt[r->cnt][0] = pos;
    r->rlt[r->cnt][1] = h;
    r->cnt++;
    return;
}
void rAdd(MyRlt *r, int pos, int h)
{
    int *lastPos;
    int *lastH;
    int preH;
    //printf("pos = %d, h = %d\n", pos, h);
    if (r->cnt == MY_MAX) {
        printf("rAdd r->cnt == MY_MAX\n");
        return;
    }
    if (r->cnt == 0) {
        rAddOne(r, pos, h);
        return;
    }
    lastPos = &(r->rlt[r->cnt - 1][0]);
    lastH = &(r->rlt[r->cnt - 1][1]);
    if (pos != *lastPos) {
        rAddOne(r, pos, h);
        return;
    }
    if (*lastH != 0 && h != 0) {
        *lastH = *lastH > h ? *lastH : h;
        return;
    }
    if (*lastH == 0 && h != 0) {
        preH = r->rlt[r->cnt - 2][1];
        if (preH == h) {
            r->cnt--;
            return;
        }
        *lastPos = pos;
        *lastH = h;
        return;
    }
    if (*lastH != 0 && h == 0) {
        *lastH = 0;
        return;
    }
    return;
}

typedef struct {
    int pos;
    int h;
    int inx;
    int type;
    UT_hash_handle hh;
} MyVL;

typedef struct {
    MyVL vl[MY_MAX];
    int cnt;
    MyVL *hh_vl;
    int maxh;
} MyStatus;
void sFree(MyStatus *s)
{
    HASH_CLEAR(hh, s->hh_vl);
    return;
}
MyStatus g_status;
void sAddVL(MyStatus *s, MyVL *vl)
{
    if (s->cnt == MY_MAX) {
        printf("sAddVL buffer is not enough\n");
        return;
    }
    s->vl[s->cnt] = *vl;
    s->cnt++;
    return;
}
int cmp(const void *a, const void *b) 
{
    MyVL *pa = (MyVL*)a;
    MyVL *pb = (MyVL*)b;
    if (pa->pos != pb->pos) {
        return pa->pos > pb->pos;
    }
    return pa->inx > pb->inx;
}

void sInit(MyStatus *s, int** buildings, int buildingsSize, int* buildingsColSize)
{
    int i;
    MyVL vl;
    s->cnt = 0;
    
    for (i = 0; i < buildingsSize; i++) {
        vl.pos = buildings[i][0];
        vl.h = buildings[i][MY_2];
        vl.type = MY_OPEN;
        vl.inx = i;
        sAddVL(s, &vl);
        vl.pos = buildings[i][1];
        vl.h = buildings[i][MY_2];
        vl.type = MY_CLOSE;
        vl.inx = i;
        sAddVL(s, &vl);
    }
    qsort(s->vl, s->cnt, sizeof(MyVL), cmp);
    s->hh_vl = NULL;
    return;
}
void procCalMax(MyStatus *s)
{
    MyVL *cur;
    MyVL *tmp;
    int maxh = INT_MIN;
    HASH_ITER(hh, s->hh_vl, cur, tmp) {
        maxh  = maxh > cur->h ? maxh : cur->h;
    }
    s->maxh = maxh;
    return;
}
void procOpen(MyStatus *s, MyRlt *r, MyVL *vl)
{
    //printf("open");
    if (HASH_CNT(hh, s->hh_vl) == 0) {
        rAdd(r, vl->pos, vl->h);
        HASH_ADD_INT(s->hh_vl, inx, vl);
        return;
    }
    if (vl->h <= s->maxh) {
        HASH_ADD_INT(s->hh_vl, inx, vl);
        return;
    }
    rAdd(r, vl->pos, vl->h);
    HASH_ADD_INT(s->hh_vl, inx, vl);
    return;
}
void procClose(MyStatus *s, MyRlt *r, MyVL *vl)
{
    MyVL *open;
    //printf("close");
    HASH_FIND_INT(s->hh_vl, &(vl->inx), open);
    if (open == NULL) {
        printf("procClose err, inx = %d\n", vl->inx);
    }
    HASH_DEL(s->hh_vl, open);
    procCalMax(s);
    if (HASH_CNT(hh, s->hh_vl) == 0) {
        rAdd(r, vl->pos, 0);
        return;
    }
    if (vl->h > s->maxh) {
        rAdd(r, vl->pos, s->maxh);
        return;
    }
    return;
}
void proc(MyStatus *s, MyRlt *r)
{
    int i;
    MyVL *vl;
    
    for (i = 0; i < s->cnt; i++) {
        procCalMax(s);
        vl = &s->vl[i];
        if (vl->type == MY_OPEN) {
            procOpen(s, r, vl);
        } else {
            procClose(s, r, vl);
        }
    }
    return;
}
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    MyRlt r;
    sInit(&g_status, buildings, buildingsSize, buildingsColSize);
    rInit(&r);
    proc(&g_status, &r);
    sFree(&g_status);
    *returnSize = r.cnt;
    *returnColumnSizes = r.returnColumnSizes;
    return r.rlt;
}
```