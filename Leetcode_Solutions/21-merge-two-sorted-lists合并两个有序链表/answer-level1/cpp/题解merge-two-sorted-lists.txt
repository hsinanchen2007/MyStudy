### 解题思路
解题思路就是用递归，参考前人题解，递归三要素：
1、终止条件：两个链表l1、l2，任一为空时结束；
2、返回值：在每次递归调用的时候，返回排序好的链表头；
3、每一级递归：如果l1->val小于l2->val，l1->next连接排序好的链表头；这句话其实意思就是l1.val与剩下元素递归merge出来的结果。
#### 复杂度分析
时间复杂度：O(n + m);
空间复杂度：O(n + m)。

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
        if (l1 == NULL) {
            return l2;
        }
        else if (l2 == NULL) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```