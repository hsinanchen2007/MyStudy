### 解题思路
此处撰写解题思路
想象一下拉拉链的过程，把一个链表头插入到另一个链表合适的位置，然后两个链表交换

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode* l2)
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode *list1 = l1->val > l2->val ? l2 : l1;
    ListNode *list2 = l1->val > l2->val ? l1 : l2;
    ListNode *temp = NULL;
    ListNode *end = NULL;

    while (1) {
        while (list1 != NULL && list1->val <= list2->val) {
            end = list1;
            list1 = list1->next;
        }
        end->next = list2;
        if (list1 == NULL) {
            break;
        }
        temp = list1;
        list1 = list2;
        list2 = temp;
    }

    return l1->val > l2->val ? l2 : l1;
}
```