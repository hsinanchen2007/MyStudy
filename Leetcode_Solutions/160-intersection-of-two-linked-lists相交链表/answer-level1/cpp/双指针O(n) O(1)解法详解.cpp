1。用两个指针分别同时走完两个链表，从头开始，A走完继续走B，B走完继续走A
2。如两链表相交，则必然会同时走到相交处（相交之后走的节点是一样的，而走的总的节点数又是一样的，会同时走完）
3。如不相交，则必然同时走到链表结尾（因为两个指针走的节点数一样，都是两个链表节点和）
4。注意指针在切换链表的时候，不要走快了，要保持两个指针一起走。

        if(NULL == headA || NULL == headB)
        {
            return NULL;
        }
        ListNode* La,*Lb;
        La = headA;
        Lb = headB;
        while(La!=NULL && Lb!=NULL) // 如是不相交，必然会同时走到头，因为两个都是走相同的结点
        {
            if(La == Lb)   //相交的地方
            {
                return La;
            }
            if(NULL == La->next) //A走到最后了,切换到B头
            {
                La = headB;       // 切换的时候就走了一步了，Lb要跟上，注意这里不能用La->next = headB;
                Lb = Lb->next;
                continue;
            }
            if(NULL == Lb->next) //B走到头了，切换到A头。
            {
                Lb = headA;
                La = La->next;
                continue;
            }
            La = La->next;
            Lb = Lb->next;
        }
        return NULL;