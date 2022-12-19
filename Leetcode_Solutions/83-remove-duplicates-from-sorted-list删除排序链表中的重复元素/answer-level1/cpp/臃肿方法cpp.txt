记录自己的臃肿方法

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
/*
    用pre来记录。 脑子清晰点就没啥问题。
*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur != NULL){
            if(pre != NULL && cur->val == pre->val){
                ListNode * tmp = cur->next;
                delete cur;
                pre->next = tmp;
                cur = tmp;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
```
