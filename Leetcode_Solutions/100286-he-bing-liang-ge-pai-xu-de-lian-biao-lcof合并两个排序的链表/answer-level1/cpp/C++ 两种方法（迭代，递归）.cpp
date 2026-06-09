### 解题思路

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
     //方法1 递归
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1==NULL)return l2;
         if(l2==NULL)return l1;
         ListNode* newL;
         if(l1->val<l2->val){
             newL=l1;
             newL->next=mergeTwoLists(l1->next,l2);
         }
         else{
             newL=l2;
             newL->next=mergeTwoLists(l1,l2->next);
         }
         return newL;
     }
        //方法2 迭代
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1; 
        ListNode* res=new ListNode(0);
        ListNode* p=res;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        p->next=l1?l1:l2;
        return res->next;
    }
};
```