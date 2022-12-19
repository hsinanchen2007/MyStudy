### 解题思路
此处撰写解题思路
1、如果出现重复数值，则直接next指向next->next节点；
2、得考虑空节点情况；

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *tmp = head;
    
    while((tmp != NULL) && (tmp->next != NULL))
    {
        if(tmp->val == tmp->next->val)
        {
            tmp->next = tmp->next->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }

    return head;
}
```