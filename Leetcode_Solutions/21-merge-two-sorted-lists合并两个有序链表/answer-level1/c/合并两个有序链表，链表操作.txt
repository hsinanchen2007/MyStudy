### 解题思路
1.处理边界（当有空链表时）
2.找出首个元素最小的链表作为返回链表
3.记录两条链的当前操作元素和前一个元素，对比处理即可
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *cur1 = NULL;
    struct ListNode *preCur1 = NULL;
    struct ListNode *cur2 = NULL;
    struct ListNode *preCur2 = NULL;
    struct ListNode *first = NULL;
    struct ListNode *second = NULL;

    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } 
    
    if (l1->val < l2->val) {
        first = l1;
        cur1 = l1;
        second = l2;
        cur2 = l2;
    } else {
        first = l2;
        cur1 = l2;
        second = l1;
        cur2 = l1;
    }

    while (cur1 != NULL) {
        if (cur2 != NULL) {
            if (cur1->val > cur2->val) {
                preCur2 = cur2;
                cur2 = cur2->next;
                preCur2->next = cur1;
                preCur1->next = preCur2;
                preCur1 = preCur1->next;
            } else {
                preCur1 = cur1;
                cur1 = cur1->next;
            }
        } else {
            return first;
        }
    }

    preCur1->next = cur2;

    return first;
}
```