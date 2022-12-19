### 解题思路
设置快慢指针fast_p,p,快指针一次前进两步，慢指针一次前进一步，若链表中有环，则快慢指针最终会相遇，且快指针比慢指针多前进k步，为环的长度。设目标节点离头指针距离为a，则慢指针p要前进到目标节点需经过k-（k-a）=a步，其中k为环的长度，k-a为p在环中相对于目标节点前进的步数。所以最后使头指针与慢指针p同步前进，两者将会相遇在目标节点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast_p = head,*p = head;

    while(fast_p != NULL && fast_p->next != NULL)
    {
        fast_p = fast_p->next->next;
        p = p->next;
        if(fast_p == p)break;
    }

    if(fast_p == NULL || fast_p->next == NULL)return NULL;
    while(head != p)
    {
        head = head->next;
        p = p->next;
    }
    return head;
}
```