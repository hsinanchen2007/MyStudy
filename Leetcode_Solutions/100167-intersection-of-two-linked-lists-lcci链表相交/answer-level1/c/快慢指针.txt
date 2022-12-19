### 解题思路
此处撰写解题思路
头尾连接，转化为判断环形链表问题，再用快慢指针判断
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL||headB==NULL)
    return NULL;
    struct ListNode *head=headA, *fast, *slow;
    struct ListNode * pre=(struct ListNode *)malloc(sizeof(struct ListNode ));
    pre->next=head;
    fast=pre, slow=pre;
    while(headA->next!=NULL) headA=headA->next;
    headA->next=headB;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) break;
    }
    if(fast==NULL||fast->next==NULL) {
        headA->next=NULL;
        return NULL;
    }
    else{
        fast=pre;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        headA->next=NULL;
        free(pre);
        return slow;
    }
    
}
```