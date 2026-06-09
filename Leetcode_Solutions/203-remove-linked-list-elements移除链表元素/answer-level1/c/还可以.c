### 解题思路
删除节点，设置头节点，判断非法输入

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* pr = NULL;
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(head == NULL) {
        return head;
    }
    p->next = head;
    head = p;
    pr = head;
    p = head->next; 

    while(p->next != NULL)
    {
        if(p->val == val)
        {
            pr->next  = p->next;
            free(p);
            p = pr->next;
        } else {
            p = p->next;
            pr = pr->next;
        }
    }
    if(p->val == val)
    {
        pr->next = NULL;
        free(p);
    }
    return head->next;
}
```