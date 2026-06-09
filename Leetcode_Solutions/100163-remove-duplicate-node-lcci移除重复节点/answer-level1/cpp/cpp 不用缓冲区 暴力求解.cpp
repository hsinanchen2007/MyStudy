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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* output=new ListNode(-1);
        ListNode* outputrec=output;
        while (head!=NULL){
            bool flag=true;
            ListNode* temp=outputrec;
            while (temp->next!=NULL){
                if (temp->next->val==head->val){
                    flag=false;
                    break;
                }
                temp=temp->next;
            }
            if (flag) {
                output->next=new ListNode(head->val);
                output=output->next;
            }
            head=head->next;
        }
        return outputrec->next;
    }
};
```