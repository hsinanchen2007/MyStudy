C语言，比较笨的方法，直接hashmap建立random指针和指向节点的索引号的映射，然后直接copy一份新链表，然后同步扫描原链表中的random指针，看指向哪个index，从表头开始遍历到这个index还原即可。
不知道为什么这个笨方法居然双100%，难道是用C语言的人太少了？

执行结果：通过
显示详情 执行用时 :4 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :8.4 MB, 在所有 C 提交中击败了100.00%的用户

```
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */
typedef struct my_struct {
    void *random;  /* random指针值 */
    int idx;       /* random指向的节点索引 */
    UT_hash_handle hh;
} MapStruct;
MapStruct *map; /* hash map */
void hashAdd(void *randomIndex, int idx)
{
    MapStruct *h, *newNode;
    newNode = calloc(1, sizeof(MapStruct));
    newNode->random = randomIndex;
    newNode->idx = idx;
    HASH_FIND_PTR(map, &randomIndex, h);
    if (h == NULL) {
        HASH_ADD_PTR(map, random, newNode);
    } else {
        free(newNode);
    }
    return;
}
MapStruct *hashFind(void *randomIndex)
{
    MapStruct *h;
    HASH_FIND_PTR(map, &randomIndex, h);
    return h;
}
void CreateMap(struct Node* head)
{
    int idx;
    struct Node *s, *curr = head;
    map = NULL;
    while (curr != NULL) { /* O(N^2)建立random和指向节点的索引 */
        if (curr->random != NULL) {
            s = head;
            idx = 0;
            while (s != curr->random) {
                s = s->next;
                idx++;
            }
            hashAdd((void*)curr->random, idx);
        }
        curr = curr->next;
    }
    return;
}
struct Node* CopyList(struct Node* head)
{
    struct Node *newNode, *tail;
    struct Node *curr = head;
    struct Node *res = NULL;
    while (curr != NULL) {
        newNode = calloc(1, sizeof(struct Node));
        newNode->val = curr->val;
        if (res == NULL) {
            res = newNode;
            tail = newNode;
            curr = curr->next;
            continue;
        }
        tail->next = newNode;
        tail = tail->next;
        curr = curr->next;
    }
    return res;
}
struct Node* copyRandomList(struct Node* head)
{
    struct Node *newNode, *tail, *res, *tmp;
    MapStruct *h, *del, *deltmp;
    CreateMap(head);
    res = CopyList(head);
    struct Node *p = res; /* 拷贝的链表 */
    struct Node *q = head; /* 原链表 */
    while (p != NULL) {
        if (q->random == NULL) {
            p = p->next;
            q = q->next;
            continue;
        }
        h = hashFind((void*)q->random); /* 找到hash map中保存的索引值 */
        tmp = res;
        for (int i = 1; i <= h->idx; i++) {  /* 找到对应节点的地址 */
            tmp = tmp->next;
        }
        p->random = tmp;
        q = q->next;
        p = p->next;
    }
    HASH_ITER(hh, map, del, deltmp) {
      HASH_DEL(map, del);
      free(del);
    }
    return res;
}
```
