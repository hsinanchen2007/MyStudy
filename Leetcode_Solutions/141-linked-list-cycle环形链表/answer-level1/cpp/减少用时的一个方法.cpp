### 解题思路
此处撰写解题思路
将q=head->next换为q=head

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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return false;
        ListNode *q,*s;
        q=head;
        s=head;
        do
        {
            if(q->next==NULL||q->next->next==NULL)return false;
                q=q->next->next;
            s=s->next;
        }while(s!=q);
        return true;
        
    }
};
```