![Snipaste_2020-03-16_06-54-41.png](https://pic.leetcode-cn.com/4125b495587d87d15ad8e60d53c2f9aa6a9ada547cd23e62c2aedc6e22a6dec8-Snipaste_2020-03-16_06-54-41.png)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *slow = &dummyHead;
        ListNode *fast = &dummyHead;
        for(int i = 0;i<n;++i)
        {
            fast = fast->next;
        }
        while(fast->next!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead.next;

    }
};
```
