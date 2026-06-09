### 解题思路
先判断是否有环，通过快慢指针，一个走两步，一个走一步，如果相遇即有环，如果能遍历到链表结尾，则没环。

从head到环入口长度为 x, 从环入口到相遇位置长度为 y, 环长 z。

相遇 slow 总共走了 s，那么fast 就是走了 2s。

相遇时 fast 可能多绕了环 n圈，再加上 从head到相遇时的距离 ，

即为： nz + s = 2s，那么 s = n * z；

slow 走的距离 s = x + y (head到入口的距离x + 从入口到相遇距离 y)

x + y = nz

x = n * z - y， n 为绕环的圈数，如果n = 1 ， 则 x = z - y， z - y 是环的长度减去环内已走过的距离，剩下的即是未走过的距离，这个距离和head 到 环入口的距离相等。

那么如果此时从头和相遇位置同时开始遍历，每次走一步，相遇位置即是环入口



### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    // 判空
    if (head == NULL || head->next == NULL) return NULL;
    // 快慢指针，一个走两步一个走一步
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    // 判断是否有环
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            break;
        }
    }
    // 无环判断
    if (fast==NULL || fast->next == NULL) return NULL;
    // 有环，将快指针指向首节点，此时从slow到环入口距离等于从头到入口距离
    while (head != slow){
        head = head->next;
        slow = slow->next;
    }
    return head;
}
```