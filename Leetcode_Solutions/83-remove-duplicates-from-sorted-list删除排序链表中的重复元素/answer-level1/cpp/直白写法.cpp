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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur_head = head;     //指向头结点
        if(cur_head==NULL)
        {
            return NULL;
        }
        while(cur_head!=NULL&&cur_head->next!=NULL)
        {
            if(cur_head->val==cur_head->next->val)
            {
                cur_head->next=cur_head->next->next;
            }
            else
            {
                cur_head=cur_head->next;
            }
        }
        return head;
    }
};
```