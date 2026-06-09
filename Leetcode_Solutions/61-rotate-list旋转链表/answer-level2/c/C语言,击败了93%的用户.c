先遍历求长度,再进行取模运算,然后将链表变成环,找到旋转后的尾结点进行拆环

```
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head)//链表为空时直接返回
        return head;
    int count=1,length=1;
    struct ListNode* s=head;//头指针
    struct ListNode* temp=head;
    while(temp->next){
            temp=temp->next;
            length++;
        }//遍历得到链表长度和尾指针
    if(k>=length)
         k=k%length;//实际需要旋转的次数
    if(k==0)
         return head;//次数为链表长度的倍数时不需要旋转,直接返回
    else{
         temp->next=head; //合成环
         while(count<length-k){
         s=s->next;//移动头指针
         count++;
         }
         struct ListNode* p=s->next;
         s->next=NULL;//拆环
         return p;
    }
}
```
