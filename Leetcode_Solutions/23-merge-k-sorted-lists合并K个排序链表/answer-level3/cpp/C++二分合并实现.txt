### 解题思路
    本题其实在之前2个链表合并的基础上较为容易，只需要考虑下奇数情况的边界问题，最终用时在24-32ms波动，内存消耗11M左右，算是双90%了。

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
        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }
        if (size == 1) {
            return lists[0];
        }
        
        while (size > 1)
        {               
            for (int i = 0; i < size / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + size / 2]);
            }
            if (size % 2)
            {
                lists[size / 2] = lists[size - 1];
                size = size / 2 + 1;               
            }
            else
            {
                size = size / 2;
            }
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *preHead, *ptr;
        preHead = new ListNode(-1);
        ptr = preHead;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {         
                ptr->next = l1;    
                l1 = l1->next;                                 
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        ptr->next = (l1 == NULL? l2 : l1);
        return preHead->next;
    }
};

```