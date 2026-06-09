```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre=dummyHead, *cur=head;
        while(cur && cur->next){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = cur->next;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};
```
执行用时 ：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 ：8.5 MB, 在所有 C++ 提交中击败了89.60%的用户