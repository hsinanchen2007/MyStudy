### 解题思路
此题受21题合并两个有序链表的启发，通过对链表数组的遍历，两两归并即可

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        for(int i=1;i<lists.size();i++)
        {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;

        if (l2 == nullptr)
            return l1;
        if(l1->val<=l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```