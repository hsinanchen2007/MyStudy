```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *cur = head;
    struct ListNode *pre;
    struct ListNode *phead = (struct ListNode *)malloc(sizeof(struct ListNode));
    phead->next = NULL;
    struct ListNode *ph = phead;
    
    while( cur && cur->next )
    {
        pre = cur;
        ph->next = pre->next;   // 先指向两个一组的第二个节点  
        ph = ph->next;          // 移动ph指针
        cur = cur->next->next;  // 移动cur指针进行下一轮的交换
        ph->next = pre;         // 再指向两个一组的第一个节点
        ph = ph->next;          // 移动ph指针
    }
    ph->next = cur;             // 最后指向cur cur为NULL 或者是奇数的情况下剩下的一个元素
    return phead->next;
}

```
