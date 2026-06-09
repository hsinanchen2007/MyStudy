
# **双指针法**

首先，判断特殊的情况，如果链表中没有元素或只有一个元素，则返回头结点。
对一般情况，考虑用两个指针，指针pre用来寻找插入的位置，使用curr指针遍历单链表。若没有重复，则curr和pre一起前移。否则使用新指针p来查找相同元素的个数。最后将pre连接到p上，如果最后p为空（即到末尾元素都要删除），则pre->next=null。
```
struct ListNode* deleteDuplicates(struct ListNode* head){
    //1.首先解决特殊情况
    if(head==NULL||head->next==NULL)
        return head;
    
    //2.构建虚拟头结点
    struct ListNode *s=(struct ListNode*)malloc(sizeof(struct ListNode));
    s->next=head;
    head=s;

    //3.构建几个指针，pre指针，curr指针，用curr指针遍历
    struct ListNode *pre=head;
    struct ListNode *curr=head->next;
    while(curr->next!=NULL&&curr!=NULL)
    {
        if(curr->next->val!=curr->val)
        {
               pre=curr;
               curr=curr->next;
        }
        else
        {
            struct ListNode *p=curr->next;
            while(p!=NULL&&p->val==curr->val)
            {
                p=p->next;
            }
            pre->next=p;
            if(p==NULL)
            {
                pre->next=NULL;
                return head->next;
            }
            curr=p;
        }
    }
   
    return head->next;

}
```
