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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode* p=head;
        ListNode* q=head->next;
        p->next=NULL;
        while(q!=NULL){
            ListNode* t=q->next;
            q->next=p;
            p=q;
            q=t;
        }
        return p;
    }
};
```