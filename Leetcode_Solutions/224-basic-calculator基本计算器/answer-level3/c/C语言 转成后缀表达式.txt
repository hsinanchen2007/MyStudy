### 解题思路

先转成后缀表达式，再计算就方便多了

![image.png](https://pic.leetcode-cn.com/9a33062cf81bc7c817972b250d4c345679983dd8272118da8c154de98b045e3e-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_NUM 0
#define MY_OPER 1
typedef struct {
    int val;
    int type;
} MyItem;
typedef struct {
    const char *name;
    MyItem *sta;
    int size;
    int cnt;
} MyStack;
void trace(MyStack *s)
{
    int i;
    printf("%s\n", s->name);
    for (i = 0; i < s->cnt; i++) {
        if (s->sta[i].type == MY_NUM) {
            printf("[%d]", s->sta[i].val);
        } else {
            printf("[%c]", (char)s->sta[i].val);
        }
    }
    printf("\n");
}
void sFree(MyStack *s)
{
    if (s->sta != NULL) {
        free(s->sta);
        s->sta = NULL;
    }
    return;
}
int sInit(MyStack *s, const char *name, int size)
{
    s->name = name;
    s->size = size;
    s->sta = (MyItem*)calloc(s->size, sizeof(MyItem));
    if (s->sta == NULL) {
        return MY_FAIL;
    }
    s->cnt = 0;
    return MY_OK;
}
void sPush(MyStack *s, MyItem item)
{
    if (s->cnt == s->size) {
        printf("sPush buffer is not enough\n");
        return;
    }
    s->sta[s->cnt] = item;
    s->cnt++;
    return;
}
bool sIsEmpty(MyStack *s)
{
    return s->cnt == 0;
}
void sPop(MyStack *s, MyItem *item)
{
    if (sIsEmpty(s)) {
        return;
    }
    *item = s->sta[s->cnt - 1];
    s->cnt--;
    return;
}
void sPeek(MyStack *s, MyItem *item)
{
    if (sIsEmpty(s)) {
        return;
    }
    *item = s->sta[s->cnt - 1];
    return;
}
bool myIsNum(char ch)
{
    return ch >='0' && ch <= '9';
}
bool myIsOper(char ch)
{
    return ch == '+' || ch == '-' || ch == '(' || ch == ')';
}
void procNum(MyStack *s_trans, char *s, int len, int *pi)
{
    int i = *pi;
    int num;
    MyItem item_num;
    if (sscanf(&s[i], "%d", &num) != 1) {
        printf("proc sscanf error:[%s]\n", &s[i]);
        return;
    }
    while(myIsNum(s[i+1])) {
        i++;
    }
    item_num.type = MY_NUM;
    item_num.val = num;
    sPush(s_trans, item_num);
    *pi = i;
    return;
}
void procOper(MyStack *s_trans, MyStack *s_oper, char *s, int len, int *pi)
{
    int i = *pi;
    MyItem item;
    MyItem peek_item;
    MyItem pop_item;
    if (s[i] == '(') {
        item.type = MY_OPER;
        item.val = s[i];
        sPush(s_oper, item);
    } else if (s[i] == '+' || s[i] == '-') {
        item.type = MY_OPER;
        item.val = s[i];
        while(!sIsEmpty(s_oper)) {
            sPeek(s_oper, &peek_item);
            if (peek_item.val == '(') {
                break;
            }
            sPop(s_oper, &pop_item);
            sPush(s_trans, pop_item);
        }
        sPush(s_oper, item);
    } else if (s[i] == ')') {
        while(!sIsEmpty(s_oper)) {
            sPop(s_oper, &pop_item);
            if (pop_item.val == '(') {
                break;
            }
            sPush(s_trans, pop_item);
        }
    } else {
        printf("procOper err [%c]\n", s[i]);
    }
    return;
}
void proc(MyStack *s_trans, MyStack *s_oper, char *s, int len)
{
    int i;
    int ret;
    int num;
    MyItem item;
    for (i = 0; i < len; i++) {
        if(s[i] == ' ') {
            continue;
        }
        if (myIsNum(s[i])) {
            procNum(s_trans, s, len, &i);
            continue;
        }
        if (myIsOper(s[i])) {
            procOper(s_trans, s_oper, s, len, &i);
            continue;
        }
        printf("proc something err [%c]\n", s[i]);
    }
    while(!sIsEmpty(s_oper)) {
        sPop(s_oper, &item);
        sPush(s_trans, item);
    }
    return;
}
int cal(MyStack *s_trans, MyStack *s_num)
{
    int i;
    MyItem n1, n2;
    MyItem item;
    for (i = 0; i < s_trans->cnt; i++){
        item = s_trans->sta[i];
        if (item.type == MY_NUM) {
            sPush(s_num, item);
            continue;
        }
        sPop(s_num, &n2);
        sPop(s_num, &n1);
        n1.val = item.val == '+' ? n1.val + n2.val : n1.val - n2.val;
        sPush(s_num, n1);
    }
    return s_num->sta[0].val;
}
int calculate(char * s){
    int ret;
    int len;
    MyStack s_num = { 0 };
    MyStack s_oper = { 0 };
    MyStack s_trans = { 0 };
    if (s == NULL) {
        return 0;
    }
    len = strlen(s);
    if (len == 0) {
        return 0;
    }
    ret = sInit(&s_num, "num", len);
    ret |= sInit(&s_oper, "oper", len);
    ret |= sInit(&s_trans, "trans", len);
    if (ret != MY_OK) {
        sFree(&s_num);
        sFree(&s_trans);
        sFree(&s_oper);
        return 0;
    }
    proc(&s_trans, &s_oper, s, len);
    //trace(&s_trans);
    ret = cal(&s_trans, &s_num);
    sFree(&s_trans);
    sFree(&s_oper);
    sFree(&s_num);
    return ret;
}
```