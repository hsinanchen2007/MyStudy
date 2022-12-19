双指针解法还是比较直观的，思路就是通过倒数第几个节点确定前后指针的间隔，从而达到定位的效果。
代码不是很好看但是思路比较清晰。
如果在头部加入哑节点应该还可以使代码更加简洁。

typedef struct ListNode List;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    List *ptr1=head;
    List *ptr2=head;
    if(n==1)
    {
        if(ptr1->next==NULL)
            return NULL;
        else
        {
            for(;ptr1->next->next;ptr1=ptr1->next)
            {}
            ptr1->next=NULL;
            return head;
        }
    }
    for(int i=0;i<n;i++)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
        {
            return head->next;
        }
    }
    while(ptr1->next)
    {
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    ptr2->next=ptr2->next->next;
    return head;

}
