### 解题思路
暴力解法，注意边界条件

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // 一个链表为空则无相交
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    for (struct ListNode* nodeA = headA; nodeA != NULL; nodeA = nodeA->next) {
        for (struct ListNode* nodeB = headB; nodeB != NULL; nodeB = nodeB->next) {
            if (nodeA == nodeB) {
                if (nodeA == NULL && nodeB == NULL) {
                    // 如果两个链表均到结尾则无相交
                    return NULL;
                }

                // 链表地址相等则相交
                return nodeA;
            }
        }
    }

    return NULL;
}
```