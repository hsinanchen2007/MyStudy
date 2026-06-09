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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode  *p1=head,*p2=head->next,*p3;
        ListNode ad(0);
        p3=&ad;
        while(p1!=NULL&&p2!=NULL)
        {p3->val=p1->val;
         p1->val=p2->val;
         p2->val=p3->val;
         if(p1->next==NULL||p2->next==NULL)
             return head;
         p1=p1->next->next;
         p2=p2->next->next;
         }return head;
    }
};
```