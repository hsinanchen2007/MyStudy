### 代码

```cpp
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        int length = 0;
        for (ListNode *i = head; i !=NULL; length++, i = i->next);  // 获取链表长度
        
        ListNode *prev = dummy, *tail = head, *next = NULL;
        
        for(; length >= k; length -= k ) {
            for(int i = 1; i < k; i++) {
                next = tail->next->next;
                tail->next->next = prev->next; // 将tail的后面一个节点插入到dummy节点后,需要3步
                prev->next = tail->next;
                tail->next = next;   
            }
            prev = tail;
            tail = tail->next;
        }
        return dummy->next;
    }
};
```