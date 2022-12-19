### 解题思路
快慢指针一个一步一个两步！

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    //用快慢指针的方法
    //一个一次走一步
    //一个一次走两步
    struct ListNode* p=head;//慢指针
    struct ListNode* px=head;//快指针
    while(px->next)
    {
        p=p->next;
        px=px->next->next;
        if(px==NULL||px->next==NULL)
        {
            return p;
        }
        
    }
    return p;
}
```