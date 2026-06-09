### 解题思路
我觉得这里链表的问题不需要删除那个节点，只需要把要删除的节点的前一个节点的next指向下一个下一个，这样所要删除的节点没有所指向，就会删除了；

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
        ListNode *current=new ListNode(0);
        ListNode *first =new ListNode (0);
        first->next=head;
        current=first;
        while(current->next!=NULL)
        {
            if(current->next->val==val)
            {
                current->next=current->next->next;
            }
            else
            {
                current=current->next;
            }
        }
         return first->next;
    }
};
```