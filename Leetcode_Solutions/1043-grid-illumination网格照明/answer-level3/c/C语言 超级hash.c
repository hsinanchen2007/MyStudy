### 解题思路
对于c，难度可能在多维度hash的建立和使用上
判断条件并不是很复杂，hash的管理是个问题，代码比较长，但是有非常多的重复代码有待优化
说一下判断条件
1、x坐标相同
2、y坐标相同
3、斜线上。这个需要好好优化，
|x1-x0| = |y1-y0| => 
x1 - x0 = y1 - y0 或 x1 - x0 = y0 - y1 => 
x1 - y1 = x0 - y0 或 x1 + y1 = x0 + y0
最开始斜线判断，采用了穷举lamp，结果性能不行，后来增加了x-y和x+y两个哈希，才可以通过。
![image.png](https://pic.leetcode-cn.com/f397b774d54e900239bce29d40cc867b10d858e83c481c0f9fce877c241497e1-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_BASE_SIZE 20000
#define MY_OK 0
#define MY_FAIL (-1)
typedef struct {
    int x;
    int y;
} MyLampKey;
typedef struct {
    MyLampKey key;
    UT_hash_handle hh;
} MyLamp;
typedef struct {
    int x;
    int cnt;
    UT_hash_handle hh;
} MyXExist;
typedef struct {
    int y;
    int cnt;
    UT_hash_handle hh;
} MyYExist;
typedef struct {
    long long xdy;
    int cnt;
    UT_hash_handle hh;
} MyXdYExist;
typedef struct {
    long long xpy;
    int cnt;
    UT_hash_handle hh;
} MyXpYExist;
typedef struct {
    /* 灯 */
    MyLamp *l;
    MyLamp *hh_l;
    int l_size;
    int l_cnt;
    /* x坐标 */
    MyXExist *xl;
    MyXExist *hh_x;
    int xl_size;
    int xl_cnt;
    /* y坐标 */
    MyYExist *yl;
    MyYExist *hh_y;
    int yl_size;
    int yl_cnt;
    /* x - y */
    MyXdYExist *xdyl;
    MyXdYExist *hh_xdy;
    int xdyl_size;
    int xdyl_cnt;
    /* x + y */
    MyXpYExist *xpyl;
    MyXpYExist *hh_xpy;
    int xpyl_size;
    int xpyl_cnt;
} MyStatus;

void sFree(MyStatus *s)
{
    MyLamp *cl;
    MyLamp *tl;
    MyXExist *cx;
    MyXExist *tx;
    MyYExist *cy;
    MyYExist *ty;
    MyXdYExist *cxdy;
    MyXdYExist *txdy;
    MyXpYExist *cxpy;
    MyXpYExist *txpy;
    HASH_ITER(hh, s->hh_l, cl, tl) {
        HASH_DEL(s->hh_l, cl);
    }
    s->hh_l = NULL;
    HASH_ITER(hh, s->hh_x, cx, tx) {
        HASH_DEL(s->hh_x, cx);
    }
    s->hh_x = NULL;
    HASH_ITER(hh, s->hh_y, cy, ty) {
        HASH_DEL(s->hh_y, cy);
    }
    s->hh_y = NULL;
    HASH_ITER(hh, s->hh_xdy, cxdy, txdy) {
        HASH_DEL(s->hh_xdy, cxdy);
    }
    s->hh_xdy = NULL;
    HASH_ITER(hh, s->hh_xpy, cxpy, txpy) {
        HASH_DEL(s->hh_xpy, cxpy);
    }
    s->hh_xpy = NULL;

    if (s->l != NULL) {
        free(s->l);
        s->l = NULL;
    }
    if (s->xl != NULL) {
        free(s->xl);
        s->xl = NULL;
    }
    if (s->yl != NULL) {
        free(s->yl);
        s->yl = NULL;
    }
    if (s->xdyl != NULL) {
        free(s->xdyl);
        s->xdyl = NULL;
    }
    if (s->xpyl != NULL) {
        free(s->xpyl);
        s->xpyl = NULL;
    }

    return;
}
void sInitLampsAux(MyStatus *s, MyLampKey key)
{
    MyXExist *xitem = NULL;
    MyYExist *yitem = NULL;
    MyXdYExist *xdyitem = NULL;
    MyXpYExist *xpyitem = NULL;
    long long xdy = ((long long)key.x) - ((long long)key.y);
    long long xpy = ((long long)key.x) + ((long long)key.y);
    HASH_FIND_INT(s->hh_x, &key.x, xitem);
    if (xitem == NULL) {
        s->xl[s->xl_cnt].x = key.x;
        s->xl[s->xl_cnt].cnt = 1;
        HASH_ADD_INT(s->hh_x, x, (&s->xl[s->xl_cnt]));
        s->xl_cnt++;
    } else {
        xitem->cnt++;
    }
    HASH_FIND_INT(s->hh_y, &key.y, yitem);
    if (yitem == NULL) {
        s->yl[s->yl_cnt].y = key.y;
        s->yl[s->yl_cnt].cnt = 1;
        HASH_ADD_INT(s->hh_y, y, (&s->yl[s->yl_cnt]));
        s->yl_cnt++;
    } else {
        yitem->cnt++;
    }
    HASH_FIND(hh, s->hh_xdy, &xdy, sizeof(xdy), xdyitem);
    if (xdyitem == NULL) {
        s->xdyl[s->xdyl_cnt].xdy = xdy;
        s->xdyl[s->xdyl_cnt].cnt = 1;
        HASH_ADD(hh, s->hh_xdy, xdy, sizeof(xdy), (&s->xdyl[s->xdyl_cnt]));
        s->xdyl_cnt++;
    } else {
        xdyitem->cnt++;
    }
    HASH_FIND(hh, s->hh_xpy, &xpy, sizeof(xpy), xpyitem);
    if (xpyitem == NULL) {
        s->xpyl[s->xpyl_cnt].xpy = xpy;
        s->xpyl[s->xpyl_cnt].cnt = 1;
        HASH_ADD(hh, s->hh_xpy, xpy, sizeof(xpy), (&s->xpyl[s->xpyl_cnt]));
        s->xpyl_cnt++;
    } else {
        xpyitem->cnt++;
    }
    return;
}
int sInitLamps(MyStatus *s, int** lamps, int lampsSize, int* lampsColSize)
{
    int i;
    MyLampKey key;
    MyLamp *item = NULL;

    s->l_size = lampsSize;
    s->l = (MyLamp*)calloc(s->l_size, sizeof(MyLamp));
    if (s->l == NULL) {
        printf("sInitLamps s->l == NULL\n");
        return MY_FAIL;
    }
    s->l_cnt = 0;
    s->hh_l = NULL;
    for (i = 0; i < lampsSize; i++) {
        key.x = lamps[i][0];
        key.y = lamps[i][1];
        HASH_FIND(hh, s->hh_l, &key, sizeof(key), item);
        if (item != NULL) {
            continue;
        }
        s->l[s->l_cnt].key.x = key.x;
        s->l[s->l_cnt].key.y = key.y;
        HASH_ADD(hh, s->hh_l, key, sizeof(key), (&s->l[s->l_cnt]));
        s->l_cnt++;
        sInitLampsAux(s, key);
    }
    return MY_OK;
}
int sInitXLamps(MyStatus *s, int** lamps, int lampsSize, int* lampsColSize)
{
    int i;
    int x;
    s->xl_size = lampsSize;
    s->xl = (MyXExist*)calloc(s->xl_size, sizeof(MyXExist));
    if (s->xl == NULL) {
        printf("sInitXLamps s->xl == NULL\n");
        return MY_FAIL;
    }
    s->xl_cnt = 0;
    s->hh_x = NULL;
    return MY_OK;
}
int sInitYLamps(MyStatus *s, int** lamps, int lampsSize, int* lampsColSize)
{
    int i;
    int y;
    s->yl_size = lampsSize;
    s->yl = (MyYExist*)calloc(s->yl_size, sizeof(MyYExist));
    if (s->yl == NULL) {
        printf("sInitYLamps s->yl == NULL\n");
        return MY_FAIL;
    }
    s->yl_cnt = 0;
    s->hh_y = NULL;
    return MY_OK;
}
int sInitXdYLamps(MyStatus *s, int** lamps, int lampsSize, int* lampsColSize)
{
    int i;
    int y;
    s->xdyl_size = lampsSize;
    s->xdyl = (MyXdYExist*)calloc(s->xdyl_size, sizeof(MyXdYExist));
    if (s->xdyl == NULL) {
        printf("sInitXdYLamps s->xdyl == NULL\n");
        return MY_FAIL;
    }
    s->xdyl_cnt = 0;
    s->hh_xdy = NULL;
    return MY_OK;
}
int sInitXpYLamps(MyStatus *s, int** lamps, int lampsSize, int* lampsColSize)
{
    int i;
    int y;
    s->xpyl_size = lampsSize;
    s->xpyl = (MyXpYExist*)calloc(s->xpyl_size, sizeof(MyXpYExist));
    if (s->xpyl == NULL) {
        printf("sInitXpYLamps s->xpyl == NULL\n");
        return MY_FAIL;
    }
    s->xpyl_cnt = 0;
    s->hh_xpy = NULL;
    return MY_OK;
}
int sInit(MyStatus *s, int** lamps, int lampsSize, int* lampsColSize)
{
    int ret;
    ret = sInitXLamps(s, lamps, lampsSize, lampsColSize);
    ret |= sInitYLamps(s, lamps, lampsSize, lampsColSize);
    ret |= sInitXdYLamps(s, lamps, lampsSize, lampsColSize);
    ret |= sInitXpYLamps(s, lamps, lampsSize, lampsColSize);
    ret |= sInitLamps(s, lamps, lampsSize, lampsColSize);
    return ret;
}
typedef struct {
    int *rlt;
    int size;
    int cnt;
} MyRlt;
void rFree(MyRlt *r)
{
    if (r->rlt != NULL) {
        free(r->rlt);
        r->rlt = NULL;
    }
    return;
}
int rInit(MyRlt *r)
{
    r->size = MY_BASE_SIZE;
    r->cnt = 0;
    r->rlt = (int*)calloc(r->size, sizeof(int));
    if (r->rlt == NULL) {
        printf("rInit r->rlt == NULL\n");
        return MY_FAIL;
    }
    return MY_OK;
}
int rAdd(MyRlt *r, int status)
{
    if (r->cnt == r->size) {
        printf("rAdd buffer is not enough\n");
        return MY_FAIL;
    }
    r->rlt[r->cnt] = status;
    r->cnt++;
    return MY_OK;
}
int procX(MyStatus *s, int x)
{
    MyXExist *item = NULL;
    HASH_FIND_INT(s->hh_x, &x, item);
    return item == NULL ? MY_FAIL : MY_OK;
}
int procY(MyStatus *s, int y)
{
    MyXExist *item = NULL;
    HASH_FIND_INT(s->hh_y, &y, item);
    return item == NULL ? MY_FAIL : MY_OK;
}
/* 斜向 */
int procXY(MyStatus *s, int x, int y)
{
    MyXdYExist *xdyItem;
    MyXpYExist *xpyItem;
    long long xdy = (long long)x - (long long)y;
    long long xpy = (long long)x + (long long)y;

    HASH_FIND(hh, s->hh_xdy, &xdy, sizeof(xdy), xdyItem);
    if (xdyItem != NULL) {
        return MY_OK;
    }
    HASH_FIND(hh, s->hh_xpy, &xpy, sizeof(xpy), xpyItem);
    if (xpyItem != NULL) {
        return MY_OK;
    }
    return MY_FAIL;
}
void procLight(MyStatus *s, MyLampKey *key)
{
    MyLamp *item;
    MyXExist *xItem;
    MyYExist *yItem;
    MyLampKey lkey;
    MyXdYExist *xdyItem;
    MyXpYExist *xpyItem;
    long long xdy;
    long long xpy;
    int i, j;
    for (i = key->x - 1; i <= key->x + 1; i++) {
        for (j = key->y - 1; j <= key->y + 1; j++) {
            lkey.x = i;
            lkey.y = j;
            HASH_FIND(hh, s->hh_l, &lkey, sizeof(MyLampKey), item);
            if (item == NULL) {
                continue;
            }
            HASH_DEL(s->hh_l, item);
            HASH_FIND_INT(s->hh_x, &i, xItem);
            xItem->cnt--;
            if (xItem->cnt == 0) {
                HASH_DEL(s->hh_x, xItem);
            }
            HASH_FIND_INT(s->hh_y, &j, yItem);
            yItem->cnt--;
            if (yItem->cnt == 0) {
                HASH_DEL(s->hh_y, yItem);
            }
            xdy = (long long)lkey.x - (long long)lkey.y;
            xpy = (long long)lkey.x + (long long)lkey.y;
            HASH_FIND(hh, s->hh_xdy, &xdy, sizeof(xdy), xdyItem);
            if (xdyItem != NULL) {
                xdyItem->cnt--;
                if (xdyItem->cnt == 0) {
                    HASH_DEL(s->hh_xdy, xdyItem);
                }
            }
            HASH_FIND(hh, s->hh_xpy, &xpy, sizeof(xpy), xpyItem);
            if (xpyItem != NULL) {
                xpyItem->cnt--;
                if (xpyItem->cnt == 0) {
                    HASH_DEL(s->hh_xpy, xpyItem);
                }
            }
        }
    }
    return;
}
void proc(MyStatus *s, MyRlt *r, int** queries, int queriesSize, int* queriesColSize)
{
    int ret;
    int i;
    MyLampKey key;
    for (i = 0; i < queriesSize; i++) {
        key.x = queries[i][0];
        key.y = queries[i][1];
        if (procX(s, key.x) == MY_OK) {
            rAdd(r, 1);
            procLight(s, &key);
            continue;
        }
        if (procY(s, key.y) == MY_OK) {
            rAdd(r, 1);
            procLight(s, &key);
            continue;
        }
        if (procXY(s, key.x, key.y) == MY_OK) {
            rAdd(r, 1);
            procLight(s, &key);
            continue;
        }
        rAdd(r, 0);
    }
    return;
}
int* gridIllumination(int N, int** lamps, int lampsSize, int* lampsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int ret;
    MyStatus s = { 0 };
    MyRlt r = { 0 };
    ret = sInit(&s, lamps, lampsSize, lampsColSize);
    ret |= rInit(&r);
    if (ret != MY_OK) {
        sFree(&s);
        rFree(&r);
        *returnSize = 0;
        return NULL;
    }
    proc(&s, &r, queries, queriesSize, queriesColSize);
    sFree(&s);
    *returnSize = r.cnt;
    return r.rlt;
}
```