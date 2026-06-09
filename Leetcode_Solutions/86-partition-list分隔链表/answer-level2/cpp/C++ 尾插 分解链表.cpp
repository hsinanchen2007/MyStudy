```
ListNode* partition(ListNode* head, int x) {
    auto h1 = new ListNode(-1),h2 = new ListNode(-1),r1 = h1,r2 = h2,p = head,q= head;
    //将原链分解为h1和h2 (带头结点) 然后用尾插法插入即可,注意要断链插 q保存断链后的新起点
    while(p) {//遍历原始链表
        q = p->next,p->next= NULL;//把节点摘粗来-断链
        if(p->val < x) r1->next = p,r1 = r1->next;//尾插
        else r2->next = p,r2 = r2->next; 
        p = q;//继续遍历
    }
    r1->next = h2->next;//连接小和大
    return h1->next;
}
```
