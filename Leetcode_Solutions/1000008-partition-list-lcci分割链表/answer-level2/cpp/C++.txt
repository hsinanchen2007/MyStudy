### 解题思路
分成小于x和不小于x两部分

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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode*ans=head,*tail=head,*mark=head->next;
       while(mark){
           ListNode*p=mark;
            mark=mark->next;
            if(p->val<x){
                p->next=ans;
                ans=p;
            }
            else{
                tail->next=p;
                tail=p;
            }
        }
        tail->next=NULL;
        return ans;
    }
};
```