执行用时 :672 ms, 在所有 C 提交中击败了6.15%的用户
内存消耗 :10.2 MB, 在所有 C 提交中击败了100.00%的用户
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head)
{
    if( !head )
        return;
    
    struct ListNode *cur = head;
    struct ListNode *pre = head;
    int count = 0, i = 0 , k, temp;
    
    while( cur )
    {
        cur = cur->next;
        count++;
    }
    temp = count;
    if( count % 2 == 0 )
        k = count / 2 - 1;      // 若链表长度为偶数 则只要进行count / 2 - 1次节点交换
    else
        k = count / 2;          // 若为奇数 则进行count / 2 次节点交换
    while( pre->next && k-- )
    {
        cur = pre;
        i = count;
        while( i-1 )
        {
            cur = cur->next;    // 将cur指向末尾元素的前一个元素
            i--;
        }
        cur->next = pre->next;
        pre->next = cur;
        pre = pre->next->next;
        count -= 2;
    }
    if( temp % 2 == 0 )
        pre->next->next = NULL;
    else
        pre->next = NULL;
}
```
