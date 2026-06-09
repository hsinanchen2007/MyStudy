### 解题思路
这道题和K个一组翻转列表解法一致，只不过k为2，详情请参见我的博客[清晰易懂的“K个一组翻转链表”](https://blog.csdn.net/qq_42103091/article/details/105113700)解法但需要注意一些细节即链表为NULL或链表结点为1个的情况。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *pre,*p,*curhead,*rear;
    int i;
    if(!head || (head->next == NULL))
    {
        return head;
    }
    curhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre = p = head;
    while(p)
    {
        for (i = 1; i < 2; i++)
        {
			 if (!p)
				 break;
			 p = p->next;
        }
        if(p)
        {
            rear = p->next;
            curhead->next = NULL;
            if(pre == head)
                head = curhead;
            while(pre!= rear)
            {
                p = pre;
                pre = pre->next;
                p->next = curhead->next;
                curhead->next = p;
            }
            while(curhead->next)
            {
                curhead = curhead->next;
            }
            curhead->next = rear;
            p = pre;
        }
    }
    return head->next;
}
```