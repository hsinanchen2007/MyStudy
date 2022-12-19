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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res,*temp;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val){
            res=l1;
            l1=l1->next;
        }
        else{
            res=l2;
            l2=l2->next;
        }
        temp=res;
        while(1){
            if(l1==NULL){
                temp->next=l2;
                temp=l2;
                return res;
            }
            if(l2==NULL){
                temp->next=l1;
                temp=l1;
                return res;
            }
            if(l1->val<l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }
    }
};
```