### 解题思路
首先一定要把题读清楚，一开始很想当然的就觉得两个数的位数一定相同，然后一心想着示例就开始敲了，最后提交的时候发现系统给了两个位数不一样的数，所以位数不相同也要好好考虑。
其次就是要梳理好你用到的链表，之后给他们分配空间，然后初始化，一开始因为没有给next指针初始化，报错了：
Line xx Char xx:member access within misaligned address...
之后初始化NULL了就ok了。
[https://blog.csdn.net/qingkongyeyue/article/details/53994355](这边贴一条链接是说未初始化指针和空指针的区别)
以下的代码还有很多可以简化的地方，但是刚开始刷题还是先写的明明白白一点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){ 
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head -> val = 0;
    head -> next = NULL;
    struct ListNode* cur = head;
    int carry = 0;
    int x = 0,y = 0 ;
    while(l1!=NULL || l2!= NULL)    
    {
        if (l1 == NULL) 
            x = 0;    
        else x = l1->val;
        if (l2 == NULL)
            y = 0;
        else y = l2->val;
        struct ListNode* p = (struct ListNode*) malloc(sizeof(struct ListNode));
        p->next = NULL;
        p -> val = (x+y+carry) % 10;
        carry = (x+y+carry) / 10;
        cur -> next = p;
        cur = cur -> next;       
        if(l1 != NULL)      
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }
    if(carry == 1)
    {
        struct ListNode* ca = (struct ListNode*) malloc(sizeof(struct ListNode));
        ca -> val = 1;
        ca -> next = NULL;
        cur -> next = ca;
    }
    return head->next;
}
```