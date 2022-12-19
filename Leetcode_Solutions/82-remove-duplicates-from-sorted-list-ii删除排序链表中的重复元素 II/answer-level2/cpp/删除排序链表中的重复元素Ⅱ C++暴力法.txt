### 解题思路
遍历问题，比较简单

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
        if(head==NULL)
            return NULL;
        ListNode * start=new ListNode(0);
        start->next=head;
        ListNode * low=start;
        ListNode * high=start->next;
        while(high->next!=NULL)
        {
            if(high->val==high->next->val)
            {
                while(high->next!=NULL && high->val==high->next->val)
                    high=high->next;
                high=high->next;
                low->next=high;
                if(high==NULL)
                    break;
            }
            else{
                low=low->next;
                high=high->next;
            }
        }
        return start->next;
    }
};
```