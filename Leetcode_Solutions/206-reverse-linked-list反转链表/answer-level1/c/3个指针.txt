### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{    
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    
    struct ListNode *p = head -> next, *q = head -> next -> next, *t;  //q从第3个结点开始，t为q的下一个结点，防止断链
    
    p -> next = head;
    head -> next = NULL;//将链表的前两个结点反转，为后面在头部逐个添加结点做准备
    while (q){
        t = q -> next;//t指向q的下一个结点
        q -> next = p;//q连上p
        p = q;//p指向其前一个结点（向前移动一位）
        q = t;//q向后移动
    }
    
    return p;
}
```