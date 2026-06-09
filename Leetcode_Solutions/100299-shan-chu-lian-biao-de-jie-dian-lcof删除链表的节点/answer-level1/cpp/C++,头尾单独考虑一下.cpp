
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val) return head->next;
        ListNode * bak = head;
        while(head->next!=NULL){
            if(head->next->val==val&&head->next->next!=NULL){
                head->next=head->next->next;
                break;
            }else if(head->next->val==val&&head->next->next==NULL){
                head->next=NULL;
                break;
            }
            head = head->next;
        }
        return bak;
    }
};
```