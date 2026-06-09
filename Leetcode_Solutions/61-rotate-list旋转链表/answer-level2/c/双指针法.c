### 解题思路
由题意可知当k小于链表长度时，后移k位就是倒数k个节点移动到链表的前面
因此先将k对len取模，找到倒数第k+1个节点和尾节点，
将倒数第k+1个节点的next设为NULL，并将尾结点指向头结点
注意：操作时注意边界条件（k为0，链表为空）

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    prehead->next = head;
    struct ListNode* pre = prehead;
    struct ListNode* cur = prehead;
    struct ListNode* ptail;

    int len = 0;
    while(head != NULL)
    {
        len++;
        ptail = head;
        head = head->next;
    }

    if(len == 0)
        return prehead->next;
    k = k % len;
    if(k == 0)
        return prehead->next;
    while(k+1)
    {
        k--;
        cur = cur->next;
    }
    while(cur)
    {
        cur = cur->next;
        pre = pre->next;
    }
    cur = pre->next;
    pre->next = NULL;
    ptail->next = prehead->next;

    return cur;
}
```