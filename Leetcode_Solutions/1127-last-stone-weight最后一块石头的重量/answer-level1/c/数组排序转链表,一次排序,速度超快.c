### 解题思路
新手链表不大熟悉,所以多练练链表
大致是 
1 先从大到小排序 qsort
2 将数组变成链表
3 第一个和第二个比较 链表指向第三个,将比较结果按顺序插入链表,循环往复,直到链表剩下一个或者一个都没有
![截图.PNG](https://pic.leetcode-cn.com/ac34f344a8f3a9285cb0357fb77c6dca8bee1412fea872766d0a38e523be78aa-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```c
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}
int lastStoneWeight(int* stones, int stonesSize){
    qsort(stones, stonesSize, sizeof(int), cmpfunc);
    struct stnode {
        int val;
        struct stnode* next;
    };
    struct stnode* st;
    st = (struct stnode*)malloc(sizeof(struct stnode));
    struct stnode* p = st;
    p->next = NULL;
    int i = 0;
    while(i < stonesSize) {
        struct stnode* tmp;
        tmp = (struct stnode*)malloc(sizeof(struct stnode));
        tmp->val = stones[i];
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
        i++;
    }
    st = st->next;
    while(st != NULL && st->next != NULL) {
        //比较
        int v1 = st->val;
        int v2 = st->next->val;
        int v = v1 > v2 ? v1 - v2 : v2 -v1;
        st = st->next->next;
        //插入
        if (v == 0) {
            continue;
        }
        if (!st){
            struct stnode* tmp;
            tmp = (struct stnode*)malloc(sizeof(struct stnode));
            tmp->val = v;
            tmp->next = NULL;
            st = tmp;
            break;
        }
        struct stnode* curr = st;
        if(curr->val <= v) {
            struct stnode* tmp;
            tmp = (struct stnode*)malloc(sizeof(struct stnode));
            tmp->val = v;
            tmp->next = st;
            st = tmp;
            continue;
        }
        struct stnode* prev = NULL;
        while (curr != NULL) {
            if (curr->val > v) {
                prev = curr;
                curr = curr->next;
            } else {
                struct stnode* tmp;
                tmp = (struct stnode*)malloc(sizeof(struct stnode));
                tmp->val = v;
                tmp->next = NULL;
                struct stnode* tmp2 = prev->next;
                prev->next = tmp;
                tmp->next = tmp2;
                break;
            }
        }
        if(curr == NULL) {
            struct stnode* tmp;
            tmp = (struct stnode*)malloc(sizeof(struct stnode));
            tmp->val = v;
            tmp->next = NULL;
            prev->next = tmp;
        }
    }
    if (st != NULL) {
        return st->val;
    } else {
        return 0;
    }
}
```