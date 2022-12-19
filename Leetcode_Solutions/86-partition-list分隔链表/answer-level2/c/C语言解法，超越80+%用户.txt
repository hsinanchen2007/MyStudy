超越了80%多的用户，思路简单，但是定义5个指针，看起来不太厉害的样子
malloc两个结点dummy1，dummy2
dummy1：存放val小于x的结点
dummy2：存放val大于等于x的结点
定义三个结点p,q1,q2
p:扫描原链表
q1:dummy1的工作指针
q2:dummy2的工作指针
扫描完原链表后，再连接dummy1和dummy2即可
```
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *dummy1,*dummy2,*p=head,*q1,*q2;
    dummy1=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy2=(struct ListNode*)malloc(sizeof(struct ListNode));
    q1=dummy1,q2=dummy2;
    while(head!=NULL){
        if(head->val<x){
            q1->next=head;
            q1=q1->next;
        }else{
            q2->next=head;
            q2=q2->next;
        }
        head=head->next;
    }
    q2->next=NULL;//q2就是新的链表的最后一个结点，一定要设置next为NULL，不然会超时
    q1->next=dummy2->next;
    free(dummy2);
    return dummy1->next;
}
```
