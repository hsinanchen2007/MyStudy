
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* h1 = head, *h2 = head->next;
        ListNode*h2_tmp = h2;
        while(h1->next!=NULL&&h2->next!=NULL){
            h1->next = h1->next->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        h1->next = h2_tmp;
        return head;
    }
};
```