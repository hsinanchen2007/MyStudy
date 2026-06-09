### 解题思路
先计算整体长度，在根据整体长度找出n的位置，最后循环一次找n的前驱节点即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(head == NULL)
        return head;
    struct ListNode* phead = head;
    struct ListNode* cur = head;
    int count = 1,len = 1;
    while(phead->next)    //计算链表长度
    {
        phead = phead->next;
        ++count;
    }
    phead = head;          //phead置头，方便后面的再次遍历
    if(n == count)     //删除头节点的情况
    {
        head = head->next;
        return head;
    }
    while(count > n)           //找到要删除的节点，当 count == n 即为所需删除的位置
    {
        cur = cur->next;
        --count;
    }
    while(phead->next != cur)
    {
        phead = phead->next;            //找到cur的前节点
    }
    phead->next = cur->next;    //因为此时就算 n == 1, phead 也会指向最后节点的后一位，即会自动置NULL，所以不用担心末尾置NULL
    return head;
}


```