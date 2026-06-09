### 解题思路

![image.png](https://pic.leetcode-cn.com/9c79d7af73c262286a8fe9f5edec5477fa42bca4a8c36a983d3a03d64776d853-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

typedef struct MyStr {
    int len;
    char *str;
} MyStr;
const MyStr g_arr[] = {
    {3, "abc"},
    {3, "def"},
    {3, "ghi"},
    {3, "jkl"},
    {3, "mno"},
    {4, "pqrs"},
    {3, "tuv"},
    {4, "wxyz"},
};
typedef struct MyStatus {
    char *cur;
    int cnt;
    int size;
} MyStatus;
void sFree(MyStatus *s)
{
    if (s->cur != NULL) {
        free(s->cur);
        s->cur = NULL;
    }
}
int sInit(MyStatus *s, int len)
{
    s->size = len;
    s->cur = (char*)calloc(1, len);
    if (s->cur == NULL) {
        return MY_FAIL;
    }
    return MY_OK;
}

typedef struct MyRlt {
    char **rlt;
    int cnt;
    int size;
} MyRlt;

void rCalSize(MyRlt *r, char * digits)
{
    int cnt = 1;
    while (*digits != '\0') {
        cnt *= g_arr[*digits - '2'].len;
        digits++;
    }
    r->size = cnt;
    return;
}

void rFree(MyRlt *r)
{
    int i;
    if (r->rlt != NULL) {
        for (i = 0; i < r->size; i++) {
            if (r->rlt[i] != NULL) {
                free(r->rlt[i]);
                r->rlt[i] = NULL;
            }
        }
        free(r->rlt);
        r->rlt = NULL;
    }
    return;
}
int rInit(MyRlt *r, char *digits)
{
    rCalSize(r, digits);
    r->rlt = (char**)calloc(r->size, sizeof(char*));
    if (r->rlt == NULL) {
        printf("rInit calloc fail\n");
        return MY_FAIL;
    }
    r->cnt = 0;
    return MY_OK;
}
int rAdd(MyRlt *r, MyStr *s)
{
    r->rlt[r->cnt] = (char*)calloc(s->len + 1, sizeof(char));
    if (r->rlt[r->cnt] == NULL) {
        printf("r->rlt[r->cnt] calloc fail\n");
        return MY_FAIL;
    }
    memcpy(r->rlt[r->cnt], s->str, s->len);
    r->cnt += 1;
    return MY_OK;
}
void proc(MyRlt *r, MyStatus *s, char *digits, int level)
{
    int i;
    int dinx;
    MyStr str;
    if (level == s->size) {
        str.len = s->size;
        str.str = s->cur;
        rAdd(r, &str);
        return;
    }
    dinx = digits[level] - '2';
    for (i = 0; i < g_arr[dinx].len; i++) {
        s->cur[level] = g_arr[dinx].str[i];
        proc(r, s, digits, level + 1);
    }
    return;
}
char ** letterCombinations(char * digits, int* returnSize){
    int ret, len, i;
    MyStatus s;
    MyRlt r;
    len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    ret = sInit(&s, len);
    ret |= rInit(&r, digits);
    if (ret != MY_OK) {
        sFree(&s);
        rFree(&r);
        return NULL;
    }
    proc(&r, &s, digits, 0);
    sFree(&s);
    *returnSize = r.cnt;
    return r.rlt;
}
```