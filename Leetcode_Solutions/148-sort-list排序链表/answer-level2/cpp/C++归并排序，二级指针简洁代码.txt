执行用时 : 28 ms, 在所有 C++ 提交中击败了99.39%的用户
内存消耗 : 11.9 MB, 在所有 C++ 提交中击败了63.15%的用户

先通过快慢指针找到中间节点，再将前后两部分切割开，对前后两部分分别进行归并排序后再合并起来。
另，通过Sentinel简化代码。

```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *slow=head, *fast=head, *last_slow=NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            last_slow = slow;
            slow = slow->next;
        }
        last_slow->next = NULL; //cut the 2 part

        //sort
        ListNode *firstPart = sortList(head);
        ListNode *secondPart = sortList(slow);
        //merge
        ListNode res(0);
        ListNode *tail = &res;
        while(firstPart || secondPart) {
            ListNode **ppNext = firstPart&&secondPart ? (firstPart->val<secondPart->val ? &firstPart : &secondPart) : (firstPart ? &firstPart : &secondPart);
            tail->next = *ppNext;
            tail = tail->next;
            *ppNext = (*ppNext)->next;
        }
        return res.next;
    }
};
```
