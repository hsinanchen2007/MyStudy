```
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *r=l3;    //没有头结点，自己搞一个头结点，方便return
    while(l1!=NULL&&l2!=NULL){      //l1指针和l2指针不都未空进行循环
        if(l1->val>l2->val){
            r->next=l2;
            l2=l2->next;
            r=r->next;
        }                         //将小的结点插入l3，其中r指向l3的尾部
        else{
            r->next=l1;
            l1=l1->next;
            r=r->next;
        }
    }
    if(l1) r->next=l1;            //l1或l2最多一个为空，直接插在r后面
    else r->next=l2;             //若l1和l2都未空，也插入r，因为r->next需要一个NULL
    return l3->next;             //将头结点后一个返回，也懒得free头结点了
}
```
