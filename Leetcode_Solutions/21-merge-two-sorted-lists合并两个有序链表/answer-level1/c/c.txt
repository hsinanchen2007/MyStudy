### 解题思路
此处撰写解题思路
1、注意头尾节点初始化；
2、每申请一个新节点时，需内存申请，并且下个节点置为NULL；
3、尾节点新增模式；

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *end = NULL;
    struct ListNode *tmp = NULL;

    while((l1 != NULL) && (l2 != NULL))
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->next = NULL;

        if(l1->val <= l2->val)
        {
            tmp = l1;
            l1 = l1->next;
        }
        else
        {
            tmp = l2;
            l2 = l2->next;
        }

        if(head == NULL)
        {
            head = tmp;
            end = tmp;
        }
        else
        {
            end->next = tmp;
            end = end->next;
        }
    }

    while(l1 != NULL)
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        tmp = l1;
        l1 = l1->next;

        if(head == NULL)
        {
            head = tmp;
            end = tmp;
        }
        else
        {
            end->next = tmp;
            end = end->next;
        }
    }

    while(l2 != NULL)
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        tmp = l2;
        l2 = l2->next;

        if(head == NULL)
        {
            head = tmp;
            end = tmp;
        }
        else
        {
            end->next = tmp;
            end = end->next;
        }
    }

    return head;
}
```