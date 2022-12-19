### 解题思路
先不管head，从head的下一个开始看，一个个删，最后return的时候再判断head，如果head该删除就返回`head->next`,否则直接返回`head`
有个坑就是 要删的不能delete或者free 不然会RE……

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
        if (head == NULL) return NULL;
        ListNode* it = head->next, *prev = head;
        while (it != NULL)
        {
            if (it->val == val)
            {
                prev->next = it->next;
                it = it->next;
            }
            else
            {
                it = it->next; prev = prev->next;
            }
        }
        return head->val == val ? head->next : head;
    }
};
```