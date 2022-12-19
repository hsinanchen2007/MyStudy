```
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        auto h1 = head,h2 = head->next,r1 = h1,r2 = h2;//分成奇偶链
        while(1){
            if(r2->next) r1->next = r2->next,r1 = r1->next;//找奇数的下一个
            else break;
            if(r1->next) r2->next = r1->next,r2 = r2->next;//偶数的下一个
            else break;
        }
        r2->next = NULL,r1->next = h2;//偶数项接在奇数项后,连接,注意偶数的最后要断开，不然死循环
        return h1;
    }
```
