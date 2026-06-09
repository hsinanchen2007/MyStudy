### 解题思路
对于这道逆置链表的题目, 相信利用头插法进行逆置大家都能比较好的掌握, 下面介绍一下递归法的思路.  
对于递归而言, 最重要的是将问题分解为更简单的子问题.  
- 让我们先来考虑最简单的情况: 仅有单个节点或空链表, 那么我们直接返回头节点既可, 这便是递归出口
- 有了递归出口, 我们再来考虑子问题, 如何将有k个节点的链表逆置呢?   
  首先我们先将后k-1个节点逆置, 随后, 我们将头节点连接到逆置后的链表尾部, 这样, 链表逆置就完成了

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){
    if (!head || !head->next) { return head; }
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}
```