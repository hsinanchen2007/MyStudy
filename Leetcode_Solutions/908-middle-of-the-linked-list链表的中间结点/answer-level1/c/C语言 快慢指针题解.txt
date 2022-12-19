### 解题思路
定义两个指针p,q。其中p每次循环后移两次，q每次循环后移一次。这样当p遍历完链表后，q指针刚好指向链表中央。
当结点个数为奇数，直接输出q指针指向结点的地址。
当结点个数为偶数，按题意输出q指针指向的结点的下一个结点的地址。

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
    struct ListNode* p;
    struct ListNode* q;
    p = q = head;
    while(1)
    {
        if(p->next == NULL)
        {
            break;
        }
        else if(p->next->next == NULL)
        {
            q = q -> next;
            break;
        }
        else
        {
            p = p->next ->next;
            q = q->next;
        }
    }
    return q;
}
```