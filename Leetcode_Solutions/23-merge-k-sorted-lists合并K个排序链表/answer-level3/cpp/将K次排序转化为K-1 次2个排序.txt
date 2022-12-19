### 解题思路
将K次排序转化为K-1 次2个排序

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
    ListNode* meger2List(ListNode *l1,ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l_size = lists.size();
        ListNode *p;
        if(l_size == 0)
        {
            return NULL;
        }
        else if(l_size == 1)
        {
            return lists[0];
        }
        else
        {
            p = lists[0];
            for(int i = 1;i < l_size;i++)
            {
               p =  meger2List(p,lists[i]);
            }
        }
        return p;
    }
};
```