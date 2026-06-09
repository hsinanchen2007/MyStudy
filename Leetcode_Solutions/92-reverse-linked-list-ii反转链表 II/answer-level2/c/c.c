分成了两个链表，然后相连。代码比较多。。
### 代码

```c
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode*pre,* p,*q,* lastp;
    struct ListNode* inversehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* dummyhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    inversehead->next=NULL;
    dummyhead->next=head;
    pre=dummyhead;
    p=head;
    int i=1;//计数，当i的值在范围内时，进行头插法插成链表，获得前一个结点和后一个结点
    while(p&&i<=n){
        if(i<m){
            if(i==m-1){
                pre=p;
            }
            p=p->next;
            ++i;
        }
        if(i>=m&&i<=n){
            if(i==m){
                lastp=p;
            }
            q=p;
            p=p->next;
            i++;
            q->next=inversehead->next;
            inversehead->next=q;//头插法
        }
    }
    pre->next=inversehead->next;
    lastp->next=p;
    return dummyhead->next;
}
```