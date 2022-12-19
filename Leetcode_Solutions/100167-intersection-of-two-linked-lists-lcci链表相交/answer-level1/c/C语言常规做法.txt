不难发现，如果两链表相交，则两链表尾部到相交节点距离相同。具体算法如下。两个方法的原理相同。
- 方法一
```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p_1=headA,*p_2=headB;
    while(p_1!=0&&p_2!=0){
        p_1=p_1->next;
        p_2=p_2->next;
    }
    //以下if语句用于保证headA指向较长的链表头部。
    if(p_1==0){
        p_1=headA;
        headA=headB;
        headB=p_1;
        p_1=p_2;
    }
    while(p_1!=0){
        headA=headA->next;
        p_1=p_1->next;
    }
    while(headA!=0){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return 0;
}
```
- 方法二
为了简明易读，某些步骤通过另写函数实现。
```c
short length(struct ListNode *obj){
    short length=0;
    while(obj!=0){
        length++;
        obj=obj->next;
    }
    return length;
}
void swap(struct ListNode **A,struct ListNode **B,short* len_A,short *len_B){
    struct ListNode* tmp=*A;
    short tmp_len=*len_A;
    *A=*B;
    *B=tmp;
    *len_A=*len_B;
    *len_B=tmp_len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    short len_A=length(headA),len_B=length(headB),tmp_len;
    struct ListNode *tmp;
    if(len_A<len_B) swap(&headA,&headB,&len_A,&len_B);
    while(len_A>len_B){
        headA=headA->next;
        len_A--;
    }
    while(headA!=0){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return 0;
}
```