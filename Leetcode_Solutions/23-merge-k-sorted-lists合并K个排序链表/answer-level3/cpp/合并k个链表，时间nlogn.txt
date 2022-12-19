### 解题思路
二分思想，每次让数组长度二分，直到数组长度为1

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
    ListNode* mergeTwo(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        if (l1 -> val > l2 -> val)
            return mergeTwo(l2, l1);
        l1 -> next = mergeTwo(l1 -> next, l2);
        return l1;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int count = lists.size();
        if (count == 0)
            return NULL;
        if (count == 1)
            return lists[0];
        --count;
        while (count > 0)
        {
            for (int i = 0; i < count; ++i, --count)
                lists[i] = mergeTwo(lists[i], lists[count]);
        }
        return lists[0];
    }
};
```