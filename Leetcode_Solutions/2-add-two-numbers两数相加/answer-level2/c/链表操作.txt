/**
* 1.设两个链表数长度分别为len1,len2,则两数和的新链表长len3<=max{len1,len2}+1
* 2.各结点数字相加，若结果小于10，则直接生成新结点，若结果大于9，则取余后生成新结点
* 3.同时与其相邻的结点和需要加1
* 4.需要设置一个标志变量，表明是否需要加1进位
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3=(struct ListNode *)malloc(sizeof(struct ListNode));
    l3->next=NULL;//初始化l3链表
    struct ListNode *p,*s,*q;
    int t,flag=0;//flag标识是否需要进位，值为1表示需要进位
    //生成第一个结点
    t=l1->val+l2->val;
    if(t<10){
        l3->val=t;
    }else{
        l3->val=t%10;
        flag=1;
    }
    
    p=l3;
    l1=l1->next;
    l2=l2->next;     
    while(l1&&l2){//生成后续结点
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        t=l1->val+l2->val;
        if(flag) t++;
        if(t<10){
            s->val=t;
            flag=0;
        }else{
            s->val=t%10;
            flag=1;
        }
        p->next=s;
        p=s;
        l1=l1->next;
        l2=l2->next;     
    }
    
    q=NULL;//q指向未加完的链表
    if(l1) q=l1;
    if(l2) q=l2;
    while(q){//把未加完的链表继续增加到新链表
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        t=q->val;
        if(flag) t++;
        if(t<10){
            s->val=t;
            flag=0;
        } else{    
            s->val=t%10;
            flag=1;
        }
        p->next=s;
        p=s;
        q=q->next;
    }
    
    if(flag){//判断最高位是否需要进1
            s=(struct ListNode *)malloc(sizeof(struct ListNode));
            s->val=1;
            p->next=s;
            p=s;
    }
    p->next=NULL;
    return l3;
}

