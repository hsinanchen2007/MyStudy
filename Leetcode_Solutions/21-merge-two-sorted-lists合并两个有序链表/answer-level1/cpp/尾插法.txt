### 解题思路
挺简单的，看到题解区都是很高端的用法，我用的是最普通的尾插法，时空效率还可以，时间93%，空间74%。思路看注释吧。

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
        ListNode *res = new ListNode(1);        // 初始化一个头结点
        ListNode *p = res;                      // 头结点的指针
        while (l1!=NULL && l2!=NULL) {
            if (l1->val < l2->val) {            // 尾插法，每次插入一个更小的值
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (l1 != NULL) p->next = l1;           // 以下代码二选一执行，接着插入没有插完的
        if (l2 != NULL) p->next = l2;

        return res->next;                       // 结果要求不带头结点
    }
};
```