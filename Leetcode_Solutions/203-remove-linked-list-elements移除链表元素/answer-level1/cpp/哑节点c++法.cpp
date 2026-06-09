### 解题思路
此处撰写解题思路

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        while(pre->next!=NULL){
            if(pre->next->val==val){
                ListNode* tem=pre->next;
                pre->next=pre->next->next;
                delete tem;
            }
            else pre=pre->next;
        }
        return dummy->next;

    }
};
```