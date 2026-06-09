设len为两个链表的长度差，那么我们将链表比喻为两条交叉的路，分别有两辆车在路上行驶，如果想要使得两车在交叉路口相遇，那么行驶在路更长的那辆车就必须先行驶一段路（这段路长为两条路的长度差），然后第另一辆车在出发，这样两车便会在交叉路口相遇。具体代码·如下
：
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  struct ListNode *p ,*q;
  int lenA=0,lenB=0,len ;

  for(p =headA;p!=NULL;p=p->next)
    lenA++;
  for(q =headB;q!=NULL;q=q->next)
    lenB++;

  if (lenA-lenB>0) {
    len=lenA-lenB;
    p=headA,q=headB;
  }else{
    len=lenB-lenA;
    p=headB,q=headA;
  }

  for(int i=0;i<len;i++){
    p=p->next;
  }

  while (p!=NULL&&q!=NULL) {
    if(p==q) return p;
    p=p->next;
    q=q->next;
    
  }
  return NULL;
}

  