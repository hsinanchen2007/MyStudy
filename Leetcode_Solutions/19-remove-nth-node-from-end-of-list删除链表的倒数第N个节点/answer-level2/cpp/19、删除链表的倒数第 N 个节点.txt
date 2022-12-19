### 解题思路
快慢指针，相当于 a + b = b + a;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<n;++i){
            fast = fast->next;
        }
        ListNode* pre = NULL;
        while(fast){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head) return slow->next;// 第一个的情况
        if(pre){
            pre->next = pre->next->next;
        }
        return head;
    }
};
```