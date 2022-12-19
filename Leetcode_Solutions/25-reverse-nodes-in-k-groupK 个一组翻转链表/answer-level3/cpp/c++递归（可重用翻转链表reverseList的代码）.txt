
执行用时 :8 ms, 在所有 C 提交中击败了92.12%的用户
内存消耗 :6.6 MB, 在所有 C 提交中击败了100.00%的用户
### 解题思路
1、循环找到第k-1和第k个节点，将node(k-1)->next = NULL
2、翻转[0,k-1]，翻转后的tail1 = head
3、递归从k开始的剩余节点，得到head2
4、tail1->next = head2
5、return head1

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;
    while (cur) {
        next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL) return NULL;
    // [0, k-1] => [head, tail]
    struct ListNode* cur = head;
    for (int i = 0; i < k-1; ++i) {
        cur = cur->next;
        if (cur == NULL) return head;
    }
    struct ListNode* tail = cur;
    struct ListNode* nodek = cur->next;
    tail->next = NULL;
    struct ListNode* head1 = reverseList(head);
    struct ListNode* tail1 = head;
    struct ListNode* head2 = reverseKGroup(nodek, k);
    tail1->next = head2;
    return head1;
}
```