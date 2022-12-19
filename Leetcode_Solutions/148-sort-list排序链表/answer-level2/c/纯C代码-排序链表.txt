### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_NUM 50000

int cmp(const void *a, const void *b) {
    struct ListNode *ap = *(struct ListNode **)a;
    struct ListNode *bp = *(struct ListNode **)b;

    return ap->val - bp->val;
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *data[MAX_NUM];
    struct ListNode *node = head;
    int num = 0;
    int i;

    if (head == NULL) {
        return NULL;
    }
    while(node != NULL) {
        data[num++] = node;
        node = node->next;
    }
    //printf("00----data[0]->val=%d,data[1]->val=%d,data[2]->val=%d,data[3]->val=%d\r\n",data[0]->val,data[1]->val,data[2]->val,data[3]->val);
    qsort(data, num, sizeof(struct ListNode *), cmp);
    //printf("01----data[0]->val=%d,data[1]->val=%d,data[2]->val=%d,data[3]->val=%d\r\n",data[0]->val,data[1]->val,data[2]->val,data[3]->val);
    head = data[0];
    node = data[0];
    for (i = 1; i < num; i++) {
        node->next = data[i];
        node = node->next;
    }
    node->next = NULL;

    return head;
}
```