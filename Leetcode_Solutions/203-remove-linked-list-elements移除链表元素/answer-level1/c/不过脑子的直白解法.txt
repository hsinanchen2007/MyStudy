本题较为简单，菜鸡我用的方法比较直接，算是最直接的方法，思路就是遍历一遍链表，如果是要删除的节点的话就删除，因此就需要预设两个节点，一个节点是现在正在遍历的节点另一个是上一个节点（用此用x该节点的next指针指向被删除节点的下一个节点，即完成删除动作），还有两种特殊情况要考虑，一是头节点即为需要被删除的节点，第二是tail也是需要被删除的节点。代码如下，写的比较繁琐，，，
执行用时 :12 ms, 在所有 C 提交中击败了99.05%的用户
内存消耗 :9.3 MB, 在所有 C 提交中击败了91.91%的用户```
代码块
```
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode * newpoint, *p, *lastpoint;
    if(head==NULL)return head;
    while(head->val==val){
        if(head->next!=NULL)head=head->next;
        else return NULL;
    }
    p=head;
    if(head->next!=NULL){
        lastpoint=p;
        p=p->next;
    }
    while(p->next!=NULL){
        if(p->val==val){
            p=p->next;
            lastpoint->next=p;
        }
        else{
            p=p->next;
            lastpoint=lastpoint->next;
        }
    }
    if(p->val==val){
        lastpoint->next=NULL;
    }
    return head;
}

代码块
```

