### 解题思路
常规题，递归和非递归两种方法。

### 代码
# **递归**
```c
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(!head || !head->next)
        return head;
    if(head->val == head->next->val){
        return deleteDuplicates(head->next);
    }
    else{
        head->next = deleteDuplicates(head->next);
    }
    return head;
}
```
# **非递归**
```
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(!head)
        return NULL;
    struct ListNode *pre = head, *p = head->next, *q;
    while(p){
        if(p->val == pre->val){
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
            q = NULL;
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    return head;
}
```
