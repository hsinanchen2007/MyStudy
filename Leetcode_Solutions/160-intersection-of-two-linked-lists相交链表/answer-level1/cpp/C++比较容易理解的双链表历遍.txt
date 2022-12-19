首先计算出两个链表的长度差，让长链表指针先走长度差次，则长短链表的指针一定在交点相逢
```
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * p = headA,*q = headB;
        //计算高度差
        int len_a = 0,len_b = 0;
        while(p != NULL){
            p = p->next; 
            len_a ++;
        }
        while(q!=NULL){
            q = q->next;
            len_b ++;
        }
        //计算完毕后让长链表指针优先移动
        p = headA;
        q = headB;
        while(len_a > len_b){
            p = p->next;
            len_a --;
        }

        while(len_a < len_b){
            q = q->next;
            len_b --;
        }
        // 两个指针一起移动，若相交一定同时到达交点
        while(p!=NULL && q!=NULL)
        {
            if(p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
```
