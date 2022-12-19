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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode*p=head;
        int count=0;
        ListNode*pre=NULL;
        ListNode*next=NULL;
        ListNode*tail=NULL;
        ListNode*temp=NULL;
        while(count<=n)
        {
            count++;
            if(count<m)
            {    
                temp=p;
                p=p->next;
            }
            if(count==m)
            {    
                pre=p;
                tail=p;
                p=p->next;
            }
            if(count>m&&count<=n)
            {
                next=p->next;
                p->next=pre;
                pre=p;
                p=next;
            }
            if(count==n)
            {
                tail->next=p;
                if(temp!=NULL)
                    temp->next=pre;
            }      
        }
        if(m==1)
            return pre;
        return head;
    }
};
```