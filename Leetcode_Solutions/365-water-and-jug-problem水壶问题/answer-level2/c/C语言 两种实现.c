### 方法一： 优化的方法二，不再存储中间结果
见check函数注释
![image.png](https://pic.leetcode-cn.com/f72009d27213f75e9438d47d51388cdeb590e4e98b070c5eff61b8218425696f-image.png)
### 代码

```c
/* 计算y能通过x产生多少个数 */
bool check(int x, int y, int z)
{
    int left = 0;
    if (y == z) {
		return true;
	}
	if ((x + y) == z) {
		return true;
	}
    if (y == 0) {
        return false;
    }
    while (1) {
        if (x > left) { /* left小于x，把y桶剩下的倒到x桶，然后用y桶把x桶倒满，y桶剩余产生的数*/
            left = y - (x - left) % y;
        } else { /* left大于等于x，那么直接将left倒到x，此时y桶剩余的数 */
            left = (left - x) % y;
        }
		if (left == z || left + x == z) {
			return true;
		}
        /* 一旦为0或y则进入了循环推倒，说明所有的数已经找到，可以退出 */
        if (left == 0 || left == y) {
            break;
        }
    }
    return false;
}

bool canMeasureWater(int x, int y, int z){
    if (z > (x + y) || z < 0) {
        return false;
    }
    if (z == 0) {
        return true;
    }
    return check(x, y, z) || check(y, x, z);
}
```
### 方法二 写得有点儿水，硬是用了hash存储下了所有的值
见sCal注释，算是提供一个解法吧
![image.png](https://pic.leetcode-cn.com/e86f0a21a6f600191c9636efde80e9eb13dfc35bdb42bea000ce45ae26cfa7e9-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)
#define MY_BASE_SIZE 100000
typedef struct {
    int num;
    UT_hash_handle hh;
} MyItem;
typedef struct {
    const char *name;
    MyItem *items;
    int size;
    int cnt;
    MyItem *hh_items;
} MyStatus;
void sTrace(MyStatus *s)
{
    MyItem *cur, *tmp;
    printf("[%s]:[%d]:", s->name, HASH_CNT(hh, s->hh_items));
    HASH_ITER(hh, s->hh_items, cur, tmp) {
        printf("%d, ", cur->num);
    }
    printf("\n");
}
void sFree(MyStatus *s)
{
    if (s->hh_items != NULL) {
        HASH_CLEAR(hh, s->hh_items);
        s->hh_items = NULL;
    }
    if (s->items != NULL) {
        free(s->items);
        s->items = NULL;
    }
    return;
}
int sInit(MyStatus *s, const char *name)
{
    s->name = name;
    s->size = MY_BASE_SIZE;
    s->items = (MyItem*)calloc(s->size, sizeof(MyItem));
    if (s->items == NULL) {
        printf("sInit s->items == NULL\n");
        return MY_FAIL;
    }
    s->hh_items = NULL;
    s->cnt = 0;
    return MY_OK;
}
int sExist(MyStatus *s, int num)
{
    MyItem *item = NULL;
    HASH_FIND_INT(s->hh_items, &num, item);
    if (item != NULL) {
        return MY_OK;
    }
    return MY_FAIL;
}
int sAdd(MyStatus *s, int num)
{
    if (s->cnt == s->size) {
        printf("%s buffer is not enough\n", s->name);
        return MY_FAIL;
    }
    //printf("sAdd(%s, %d)\n", s->name,num);
    s->items[s->cnt].num = num;
    HASH_ADD_INT(s->hh_items, num, (&s->items[s->cnt]));
    s->cnt++;
    return MY_OK;
}
/* 计算y能通过x产生多少个数 */
int sCal(MyStatus *s, int x, int y)
{
    int left = 0;
    sAdd(s, y);
    if (y == 0) {
        return;
    }
    sAdd(s, left);
    while (1) {
        if (x > left) { /* left小于x，把y桶剩下的倒到x桶，然后用y桶把x桶倒满，y桶剩余产生的数*/
            left = y - (x - left) % y;
        } else { /* left大于等于x，那么直接将left倒到x，此时y桶剩余的数 */
            left = (left - x) % y;
        }
        /* 一旦存在则进入了循环推倒，说明所有的数已经找到，可以退出 */
        if (sExist(s, left) == MY_OK ) {
            break;
        }
        sAdd(s, left);
    }
    return MY_OK;
}
bool check(MyStatus *s, int other, int z)
{
    int num = z;
    MyItem *item = NULL;
    //sTrace(s);
    //printf("other = %d, z = %d\n", other, z);
    HASH_FIND_INT(s->hh_items, &num, item);
    if (item != NULL) {
        return true;
    }
    if (z < other) {
        return false;
    }
    num = z - other;
    HASH_FIND_INT(s->hh_items, &num, item);
    if (item != NULL) {
        return true;
    }
    return false;
}
bool canMeasureWater(int x, int y, int z){
    bool rlt;
    int ret;
    MyStatus xs = { 0 };
    MyStatus ys = { 0 };
    if (z > (x + y) || z < 0) {
        return false;
    }
    ret = sInit(&xs, "x_status");
    ret |= sInit(&ys, "y_status");
    if (ret != MY_OK) {
        return false;
    }
    sCal(&xs, y, x);
    //sTrace(&xs);
    sCal(&ys, x, y);
    //sTrace(&ys);
    rlt = check(&xs, y, z) || check(&ys, x, z);
    sFree(&xs);
    sFree(&ys);
    return rlt;
}
```