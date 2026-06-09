### 解题思路
日常参考 [@jyd](/u/jyd/) 大佬的思路。
- 这个题个人理解的难点在于：每次都要用`cur->next = l1(或者l2)`，如果直接`cur = l1`会使得cur指向别的地方，而没有连接到合并链表上，要通过`cur->next`来访问到合并链表的下一个节点。
- 另，附加空节点的特殊情况考虑，加强鲁棒性，这是剑指offer出这道题的本意之一~

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 !=NULL && l2 !=NULL)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 == NULL)
        {
            cur->next = l2;
        }
        else
        {
            cur->next = l1;
        }
        return head->next;
    }
};
```