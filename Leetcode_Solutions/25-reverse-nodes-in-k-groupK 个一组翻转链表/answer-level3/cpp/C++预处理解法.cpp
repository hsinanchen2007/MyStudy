首先遍历一下链表，记录链表中数据的个数。然后如果个数小于k，直接输出原链表即可，否则，计算链表可以分多少组，从哪里开始断开。最后利用循环对每一组进行翻转，如果有剩余，直接加至末尾即可。
代码如下：
```
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        if(k==1)
            return head;
        ListNode *tmp=head;
        int num=1;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            if(tmp==NULL)
                break;
            num++;
        }
        if(num==1 ||num<k)
            return head;
        int gr=num/k,remain=num%k;
        ListNode *newhead, *tail,*curNode,*nextNode,*tmpNode ,*pretail;
        for(int i=0;i<gr;i++)
        {
            int j=0;
            while(j<k)
            {
                if(j==0)
                {
                    nextNode=head->next;
                    curNode=head;
                    curNode->next=NULL;
                    tail=curNode;
                    j++;
                    continue;
                }
                tmpNode=nextNode->next;
                nextNode->next=curNode;
                curNode=nextNode;
                nextNode=tmpNode;
                j++;
            }
            if(i==0)
            {
                newhead=curNode;
                pretail=tail;
            }
            else
            {
                pretail->next=curNode;
                pretail=tail;
            }
            head=tmpNode;
        }
        if(tmpNode==NULL)
            return newhead;
        else
        {
            pretail->next=tmpNode;
            return newhead;
        } 
    }
```
