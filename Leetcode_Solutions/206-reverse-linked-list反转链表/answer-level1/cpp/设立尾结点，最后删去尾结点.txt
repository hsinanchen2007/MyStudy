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
        if(head==NULL)return NULL;
        ListNode* dummy=head->next;
        ListNode* x=head;
        ListNode* tail=new ListNode(-1);
        int len=0;
        while(x->next!=NULL)
        {
            len++;
            x=x->next;
        }
        x->next=tail;
        tail->next=NULL;
        for(int i=0;i<len;i++)
        {
            head->next=x->next;
            x->next=head;
            head=dummy;
            dummy=dummy->next;
        }
        ListNode* m=x;
        for(int i=0;i<len;i++)
        {
            m=m->next;
        }
        m->next=NULL;
        delete tail;
        return x;
    }
};
```