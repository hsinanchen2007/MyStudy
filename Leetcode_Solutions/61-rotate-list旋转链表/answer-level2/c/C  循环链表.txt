### 解题思路
先遍历一遍把链表的尾和头连接起来做成一个循环链表并记录链表长度，之后再将尾向右移动len - k % len个位置后的地方即为要返回链表的头部，前面那个节点让它指向NULL

![image.png](https://pic.leetcode-cn.com/ea09ea6e1d092f423f380c5225088c91f8eab7c30c43e5e3e54681d30d910509-image.png)
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head == 0 || head->next == 0)
    {
        return head;
    }

    struct ListNode* tmp = head;
    struct ListNode* tmp2 = head;
    int len = 1;
    while(tmp->next != 0)
    {
        tmp = tmp->next;
        len++;
    }
    tmp->next = head;
    k = len - k % len;
    while(k > 1 )
    {
        tmp2 = tmp2->next;
        k--;
    }
    head = tmp2->next;
    tmp2->next = NULL;
    return head;
}


```