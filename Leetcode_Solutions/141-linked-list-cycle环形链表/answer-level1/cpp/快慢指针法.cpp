
    ListNode*    fast = fast->next->next;   // 快指针
    ListNode*    slow = slow->next;     // 慢指针

**一、 假设链表中不存在环**
    快指针一定会走到NULL，直接return 0 即可

**二、 假设链表中存在环**
    快指针 和 慢指针 一定会进入环，无论快慢指针何时进入环，中间相隔任意个节点，总会在某一次移动后相遇， fast == slow 时候返回 1

C++ 代码如下 仅供参考

```
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL) {
        if (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            return 0;
        }
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}
```

![image.png](https://pic.leetcode-cn.com/2835e8a9092158e526e0888212070c31a21139cb49eb8ef083e05f00f218e41b-image.png)

