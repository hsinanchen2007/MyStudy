首先遍历链表找到最后一个节点，在遍历的过程中顺便求出这个链表中有多少个节点  找到最后一个节点后将它的next指向头节点构成一个循环链表，我们求出链表的长度为len 观察发现 如果len>k 那么整个链表向右移动k个位置 如果len<=k
链表向右移动k%len个位置 我们知道链表向右移动多少个位置后 初始时让指针p指向head tail指向p的前一个位置 q指向p+move（move是链表向右移动多少个位置)然后这三个指针一起向有移动 当q指向head时 p指向的位置就是新的head 这时让tail->next=NULL 返回p即可
```
struct ListNode* rotateRight(struct ListNode* head, int k){
   if(head==NULL)
      return head;
   struct ListNode* p;
   struct ListNode* q;
   struct ListNode* tail;
   p=head;
   int length=1;
   int move=0;
   while(p->next!=NULL)//找到最后一个节点
   {
       length+=1;
       p=p->next;
   }
   p->next=head;//将链表连接成环
   tail=p;
   if(k>=length)
      move=k%length;
    else
      move=k;
   p=head;
   q=head;
   while(move>0)
   {
       q=q->next;
       move-=1;
   }
   while(q!=head)
   {
       q=q->next;
       p=p->next;
       tail=tail->next;
   }
   tail->next=NULL;
   return p;
}
```
