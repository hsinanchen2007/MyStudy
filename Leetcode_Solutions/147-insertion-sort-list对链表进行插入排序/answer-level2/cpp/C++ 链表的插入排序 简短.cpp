```
    ListNode* insertionSortList(ListNode* head) {
        auto h = new ListNode(-1),pre = h,q=head;//q为防止断链的备份节点
        for(auto p = head; p; p=q){//把head的每个节点p插入到h链中
            for(pre = h; pre->next&&(p->val > pre->next->val);pre = pre->next){}//找插入点
            q = p->next,p->next = pre->next, pre->next = p;//插入
        }
        return h->next;
    }
```
