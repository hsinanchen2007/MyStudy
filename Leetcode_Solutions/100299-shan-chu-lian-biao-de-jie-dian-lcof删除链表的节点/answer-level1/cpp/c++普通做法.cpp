### 解题思路
普通思路

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
        ListNode* p=head;
        ListNode* q=head;
        while(p)//先确定head的头，即移到不是val的节点上，若第一个就不是val则不动
        {
            if(p->val==val)
            {
                head=head->next;
                p=p->next;
                continue;
            }
            else break;
        }
        while(p)//q始终处于上一个不是val的位置，移p
        {
            if(p->val==val)
            {
                p=p->next;
                q->next=p;
                continue;
            }
            q=p;
            p=p->next;
        }
        return head;
    }
};
```