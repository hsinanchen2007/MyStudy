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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p= new ListNode(0);
        p->next = head;
        ListNode* pre = p;
        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->val==val){
                pre->next=cur->next;
                cur->next=NULL;
                return p->next;
            }
            else{
                pre=pre->next;
                cur=cur->next; 
            }
        }
        return head;
        
        
    }
};
```