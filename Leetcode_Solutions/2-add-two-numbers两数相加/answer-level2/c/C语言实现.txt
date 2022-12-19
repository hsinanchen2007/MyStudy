```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));//使用头结点，用以最后返回结果（没有free，懒得写了）
    head->next=NULL;
    struct ListNode* p=head;//工作指针
    int cur=0;              //进位标志
    while(l1!=NULL||l2!=NULL){
        //生成一个结点
        struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        //val1保存l1中的值，val2保存l2中的值，cal用来保存计算后存储在该结点的数字
        int val1,val2,cal;
        //注意判断l1是否为空
        if(l1==NULL) val1=0;
        else {
            val1=l1->val;
            l1=l1->next; //不为空的时候再next，不然报错
        }
        if(l2==NULL) val2=0;
        else {
            val2=l2->val;
            l2=l2->next;
        }
        //保存计算后存储在该结点的数字
        cal=(val1+val2+cur)%10;
        //求出进位是多少
        cur=(val1+val2+cur)/10;
        temp->val=cal;
        //temp保存为工作指针的下一结点
        p->next=temp;
        //工作指针下移（尾插法）
        p=p->next;
    }
    //如果最后还有进位，需要保存
    if(cur==1){
        struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        temp->val=1;
        p->next=temp;
        p=p->next;
    }
    return head->next;
}
```
