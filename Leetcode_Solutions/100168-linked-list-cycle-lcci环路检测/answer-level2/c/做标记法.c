1、从头开始遍历链表，把每个节点的值改成一个基本不会出现的数，
2、遍历到这个数的时候，说明到达了环的开头节点，返回这个节点
3、到底了，说明没环


struct ListNode *detectCycle(struct ListNode *head) {
    struct  ListNode *p = head;
    while(p)
    {
        if(p->val==99999999)
        break;
        p->val = 99999999;
        p = p->next;
    }
    if(p)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}