### 解题思路
把链表转换成数组，就好操作多了
![image.png](https://pic.leetcode-cn.com/69c657d14fbba4bc0d36ef089bd5cd9b263f8c17310b3c99a5b2225af1ae462e-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MY_OK 0
#define MY_FAIL (-1)

typedef struct {
    int lcnt;
    struct ListNode **larr;

    int k;
    int lsectCnt;
} MyStatus;
void sFree(MyStatus *s)
{
    if (s->larr != NULL) {
        free(s->larr);
        s->larr = NULL;
    }
    return;
}
int sInit(MyStatus *s, struct ListNode* head, int k)
{
    int i;
    struct ListNode *cur = head;
    s->lcnt = 0;
    while (cur != NULL) {
        s->lcnt++;
        cur = cur->next;
    }
    if (s->lcnt == 0) {
        return MY_OK;
    }
    s->larr = (struct ListNode**)calloc(s->lcnt + 1, sizeof(struct ListNode*));
    if (s->larr == NULL) {
        return MY_FAIL;
    }
    for (i = 0, cur = head; i < s->lcnt; i++, cur = cur->next) {
        s->larr[i] = cur;
    }
    s->lsectCnt = s->lcnt / k;
    s->k = k;
    return MY_OK;
}

void proc(MyStatus *s)
{
    int i;
    struct ListNode **l = NULL;
    struct ListNode **r = NULL;
    struct ListNode *tmp = NULL;
    for (i = 0; i < s->lsectCnt; i++) {
        l = &(s->larr[i * s->k]);
        r = &(s->larr[(i + 1)* s->k - 1]);
        while (l < r) {
            tmp = *l;
            *l = *r;
            *r = tmp;
            l++;
            r--;
        }
    }
    for (i = 0; i < s->lcnt; i++) {
        s->larr[i]->next = s->larr[i+1];
    }
    return;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int ret;
    struct ListNode *rlt = NULL;
    MyStatus s;
    if (head == NULL || k <= 0) {
        return head;
    }
    ret = sInit(&s, head, k);
    if (ret != MY_OK) {
        return NULL;
    }
    proc(&s);
    rlt = s.larr[0];
    sFree(&s);
    return rlt;
}
```