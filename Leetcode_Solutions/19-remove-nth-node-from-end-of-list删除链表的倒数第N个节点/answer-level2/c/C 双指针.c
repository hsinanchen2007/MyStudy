### 解题思路
双指针整体思路，首先让前后指针间隔n，之后同时后退双指针，之后删除考前指针的next
比较烦人的是[]和[1]
在将单个指针向后推的时候判断是否为空，若出现空则直接返回head->next

执行用时 :4 ms, 在所有 C 提交中击败了81.55%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了81.31%的用户

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
    struct ListNode* a;//后指针
    struct ListNode* b;//前指针
    a=head;//a指向头指针
    b=head;
    for(int i=0;i<n;i++)
    {
        if(b->next)
            b=b->next;//若b->next不为空则将指针向后推
        else
            return head->next;
    }
    while(b->next)
    {
        a=a->next;
        b=b->next;
    }
    a->next=a->next->next;
    return head;
}
```