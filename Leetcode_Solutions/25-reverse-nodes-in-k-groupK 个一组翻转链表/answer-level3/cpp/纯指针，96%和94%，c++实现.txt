不让用额外空间，但是看评论好像用数组也能过？感觉写的很乱，很丑。将就着看吧
```
ListNode* reverseKGroup(ListNode* head, int k) 
{
        //特殊情况
        if(head == NULL || k == 1)
            return head;
        //记录有没有满k个节点
        int index = 1;
        //prev记录上一组的尾节点;temp是保存p->next的临时节点;tail记录每一组的尾部节点
        ListNode* prev = NULL,*p = head,*cur = NULL,*temp = NULL,*tail = NULL;
        
        while(p != NULL)
        {
            if(index != k)
            {
                temp = p->next;
                //一组中的首个节点
                if(cur == NULL)
                {
                    cur = p;
                    tail = p;
                    //这里要把一组中的第一个节点指定为NULL,不然会出现互相指向导致死循环的问题
                    p->next = NULL;
                }
                else
                {
                    p->next = cur;
                    cur = p;
                }
                p = temp;
                index++;
            }
            //一组中最后的一个节点
            else
            {
                temp = p->next;
                //如果是第一组，需要修改head的指向
                if(tail == head)
                {
                    head = p;
                    tail->next = p->next;
                    p->next = cur;
                }
                else
                {
                    tail->next = p->next;
                    p->next = cur;
                    prev->next = p;
                }
                cur = NULL;
                index = 1;
                prev = tail;
                p = temp;
            }
        }
        //如果节点个数不是k的倍数，需要还原尾部节点顺序
        if(cur != NULL)
        {
            ListNode* r = cur,*s = r->next;
            while(s != NULL)
            {
                temp = s->next;
                s->next = r;
                r = s;
                s = temp;
            }
            cur->next = NULL;
        }
        
        return head;
}
```
