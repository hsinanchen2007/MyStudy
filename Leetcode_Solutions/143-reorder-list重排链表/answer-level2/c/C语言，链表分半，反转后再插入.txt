基本思路是：把链表分为两部分，然后再把后半部分反转，然后再把反转后的后半部分，依次插入到前半部分当中去
```
struct ListNode *converse(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while(curr)
    {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(struct ListNode* head){
    if(head == NULL || head->next == NULL)      //至少要有三个节点
        return head;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *pre = NULL;

    while(fast && fast->next)                   //寻找中间节点
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    pre->next = NULL;
    slow = converse(slow);                      //断开前半部分后后半部分的连接
    fast = head;

    while(slow && fast)
    {
        struct ListNode *fast_next = fast->next;        //分别记录两条链表的后继节点位置
        struct ListNode *slow_next = slow->next;

        if(fast_next == NULL)           //如果前半部分走到NULL了，则直接连接后半部分剩下的节点
        {                               //此情况主要是应对链表节点个数为偶数的情况
            fast->next = slow;
            break;
        }    
        else
        {
            slow->next = fast_next;     //否则，以此将后半部分的节点插入到前半部分中
            fast->next = slow;
        }
        slow = slow_next;
        fast = fast_next;
    }
}
```
