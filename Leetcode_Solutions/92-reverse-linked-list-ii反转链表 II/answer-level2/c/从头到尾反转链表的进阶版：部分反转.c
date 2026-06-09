### 解题思路
首先要记录下链表中第m-1和第n+1个节点（首先假设存在，因为m可能为1，n可能是尾节点，这两种情况下，理应指向这两个节点的指针为NULL）。接着按照链表反转的常规操作一个个节点反转即可，最后要看一下m是不是第一个节点，如果不是，把第m-1个节点的next指针指向第n个节点，返回head即可；如果是，说明第n个节点就是反转之后的头节点，直接返回该指针即可。
![速度.JPG](https://pic.leetcode-cn.com/e4134a3c0e580a05bbfc52a575dc9b4fe05cae82821d631519d2783606af003b-%E9%80%9F%E5%BA%A6.JPG)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    int len = 0;//记录链表的长度
    struct ListNode *node = head;
    struct ListNode *pre = NULL;//指向第m-1个节点
    struct ListNode *pos = NULL;//指向第n+1个节点
    while(node != NULL)
    {
        len++;
        if(len == m - 1)
            pre = node;
        if(len == n + 1)
            pos = node;
        node = node->next;
    }
    //反转链表：node指向要反转部分的第一个节点
    node = pre==NULL?head:pre->next;
    struct ListNode *cur = node->next;//cur指向当前要处理的节点
    node->next = pos;
    struct ListNode *nextNode = NULL;
    while(cur != pos)
    {
        nextNode = cur->next;//保存当前节点的下一个节点
        cur->next = node;
        node = cur;
        cur = nextNode;
    }
    if(pre != NULL)
    {
        pre->next = node;
        return head;
    }
    return node;
}
```