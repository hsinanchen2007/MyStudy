### 解题思路
三个节点

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
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q;
        if(head!=NULL){
            p=head;
            q=head->next;
        }else{
            return NULL;
        }

        while(q!=NULL){
            p->next=q->next;
            q->next=head;
            head=q;
            q=p->next;
        }
        p->next=NULL;
        return head;
    }
};
```