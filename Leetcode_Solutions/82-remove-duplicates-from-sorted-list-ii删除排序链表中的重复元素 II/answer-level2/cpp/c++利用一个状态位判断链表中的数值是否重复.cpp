```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res=new ListNode(0);
        ListNode  *p1=head,*pot=res;//p1指向输入链表头结点， pot指向输出链表
        bool dup=false;//状态位 如果p1前面的值和p1的值重复 dup=true
        if(!p1)
        return head;
        while(p1&&p1->next)
        {
            //p1的值和p1下个值重复 dup=true
            if(p1->val==p1->next->val)
            {
                p1=p1->next;
                dup=true;
            }
            else if(dup==1)//p1前面的值和p1的值重复
            {
                p1=p1->next;
                dup=false;
            }
                else//p1前面的值和p1的值不同
                {
                    pot->next=p1;
                    p1=p1->next;                  
                    pot=pot->next;
                    dup=false;
                }
        }
        //判断链表最后一个值是否和前一个值重复
        if(dup==false)
        pot->next=p1;
        else
        pot->next=NULL;
        return res->next;
    }
};
```
