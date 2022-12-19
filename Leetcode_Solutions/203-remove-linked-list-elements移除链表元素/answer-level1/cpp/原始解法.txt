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
        ListNode* pre=NULL;
        ListNode* p=head;
        while(p!=NULL){
            if(p->val==val){
                if(pre==NULL){
                    head=p->next;
                }
                else{
                    pre->next=p->next;
                }
            }
            else{
                pre=p; 
            }
            p=p->next;
        }
        return head;
    }
};
```