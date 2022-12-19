![image.png](https://pic.leetcode-cn.com/19848b5a783adfa367bed1580b886f0c7ac26a0e4a21130751819005d89af54c-image.png)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){

    if(!head||!(head->next)||!(head->next->next))  return head;

    struct ListNode*odd=head,*oddp=head;
    struct ListNode*even,*evenphead;
    even=evenphead=head->next;
    while(oddp&&oddp->next&&oddp->next->next)
    {
        oddp=odd->next->next;
        odd->next=oddp;
        odd=oddp;
        if(oddp)
        {
            even->next=oddp->next;
            even=oddp->next;
        }
    }
    oddp->next=evenphead;

    return head;
}
```
