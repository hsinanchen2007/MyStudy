假设将整个链表分为三段，先遍历链表到m，然后保存第一段的尾结点，并判断状态。然后处理中间要翻转的一段链表，中间链表的第一个元素为第二段的尾结点，然后翻转过程中，已翻转链表的头结点为curnode,未翻转的部分的首结点为nextnode，设置一个临时结点tmpnode维护nextnode，防止其被覆盖，然后处理完第二段链表，并判断第三段链表起始部分的状态。
```
ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy=new ListNode(-1000);
        dummy->next=head;
        ListNode *tmpNode=dummy,*onetail;
        int num=0;
        while(num<m)
        {
            onetail=tmpNode;
            tmpNode=tmpNode->next;
            num++;
        }
        if(tmpNode->next==NULL)
        {
            return dummy->next;
        }
        onetail->next=NULL;
        ListNode *curNode=tmpNode,*nextNode,*twotail=tmpNode;
        while(num<=n)
        {
            if(num==m)
            {
                nextNode=curNode->next;
                curNode->next=NULL;
                num++;
                continue;
            }
            tmpNode=nextNode->next;
            nextNode->next=curNode;
            curNode=nextNode;
            nextNode=tmpNode;
            num++;
        }
        if(nextNode!=NULL)
            twotail->next=nextNode;
        onetail->next=curNode;
        return dummy->next;
    }
```
