
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
        int len = 0;
        ListNode *temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        if(head->next == NULL || len == n){
            return head = head->next;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        int count = 0;
        while(count != n){
            cout << fast->val;
            count++;
            fast = fast->next;  
        }
        // cout << count << endl;
        // cout << fast->val;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
```