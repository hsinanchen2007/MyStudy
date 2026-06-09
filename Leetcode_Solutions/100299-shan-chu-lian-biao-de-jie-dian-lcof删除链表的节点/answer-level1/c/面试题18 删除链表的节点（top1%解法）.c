![image.png](https://pic.leetcode-cn.com/29a0bc8956a6922c6acb2b2c36446b2ba1a7b445e11de9afcf14f80b4fe14c7f-image.png)

### 解题思路
1.while循环遍历结点
2.在值为val的结点前停下
3.q = p->next q指向值为val的结点
4.p->next = q->next
5.over！

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* p = head;
    struct ListNode* q;

    if(head->val==val){
        head = head->next;
        return head;
    }
    while(p->next->val!=val){
        p = p->next;
    }

    q = p->next;

    p->next = q->next;
    return head;
}
```