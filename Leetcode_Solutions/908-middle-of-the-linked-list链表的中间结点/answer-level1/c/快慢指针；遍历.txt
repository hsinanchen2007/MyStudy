### 解题思路
1.快指针一次进两步，慢指针一次进一步。最后答案为慢指针。
2.遍历计算总数，算出中间位置再遍历一次。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (slow && fast) {
        slow = slow->next;
        fast = (fast->next) ? fast->next->next : NULL;
    }
    return slow;
}
```

```c
struct ListNode* middleNode(struct ListNode* head){
    int cnt = 0;
    struct ListNode *cur = head;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    int mid = (cnt+1)/2 + (cnt%2==0 ? 1:0);

    cur = head;
    int cnt1=1;
    while (cnt1 < mid) {
        cur = cur->next;
        cnt1++;
    }

    return cur;
}
```
```