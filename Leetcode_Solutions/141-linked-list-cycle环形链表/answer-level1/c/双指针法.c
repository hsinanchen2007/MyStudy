### 解题思路
利用两个指针从链表头开始往下遍历，第一个指针每次只移动一个节点，第二个指针每次移动两个节点，如果链表中存在环，第二个和第一个指针总有一个时刻会相遇。如果链表中不存在环，那么就会出现指针为空的情况，说明链表结束了，并没有环的情况，这个也就是循环退出的条件。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    struct ListNode *p = head, *q = head -> next;

    while (p && q && q -> next) {
        if (p == q) {
            return true;
        } 
        p = p -> next;
        q = q -> next -> next;
    }
    return false;
}
```