### 解题思路
简单题，删除满足题目要求的节点即可

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *first=new ListNode(0);
        first->next=head;
        ListNode *current=new ListNode(0);
        current=first;
        while(current->next!=NULL)
        {
            if(current->next->val==val)
            {

                ListNode *tmp=current->next;
                current->next=current->next->next;
                delete tmp;
            }
            else
                current=current->next;
        }
        return first->next;
    }
};
```