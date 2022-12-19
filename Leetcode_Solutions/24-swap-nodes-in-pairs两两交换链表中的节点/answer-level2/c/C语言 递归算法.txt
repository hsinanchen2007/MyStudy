答题前，首先考虑到了依次两两变换的操作时一样的，不考虑特殊情况的话：
 head.next=head（这是直接可以得到的）
head.next.next是要经过交换之后的一组数据才可以得到，而这一步是每次交换操作必不可少的
所以：
1、先给出递归结束的条件
2、设定双指针 分别指向头和头的下一个
3、在一次递归中，先不着急让head.next=head  为避免影响，应该先利用递归求出head.next.next，再执行head.next=head
struct ListNode* swapPairs(struct ListNode* head)
{
   
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    struct ListNode* pr=head;
    struct ListNode* ps=head->next;
    pr->next=swapPairs(ps->next);
    ps->next=pr;
    return ps;
}
