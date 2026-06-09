- ### 解题思路
1. 先确定 “第一步”
两个链表都有序，要想合并后仍然有序，第一步应该是：比较两个链表的第一个节点，谁小谁是头结点。
2. 确定了第一步之后，问题就变成子链表（除去上文提到的头结点）与另一个链表的合并，发现与整个链表合并类似，仍然要先确认“第一步”，那么这是一个重复的子问题，可以通过递归来做。
3. 确定使用递归方法后，要确认三点：
 - 返回值：返回链表头指针
 - 递归调用式做什么：合并两个子链表，返回子链表的头指针
 - 终止条件 ：链表l1 或者 l2 其中一个到达链表尾部
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
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```