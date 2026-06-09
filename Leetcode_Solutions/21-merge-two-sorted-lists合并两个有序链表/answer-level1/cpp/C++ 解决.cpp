

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *temp = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                res ->next = l1;
                res = l1;
                l1 = l1->next;
            }else if(l2->val < l1->val){
                res ->next = l2;
                res = l2;
                l2 = l2->next;
            }
        }
        if(l1 == NULL){
            res->next = l2;
        }else{
            res->next = l1;
        }
        return temp->next;
    }
};
```