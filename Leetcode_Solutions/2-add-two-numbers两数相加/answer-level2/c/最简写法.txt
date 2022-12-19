
看见这道题我们很容易想到大数相加问题
当两个数大于长整型时需使用数组从后往前逐位向加,存储进位,取余为该位值

核心代码:
    `l1=l1!=NULL?(c+=l1->val,l1->next):(c+=0,l1);
    l2=l2!=NULL?(c+=l2->val,l2->next):(c+=0,l2);`
c即进位,上一位的进位(c值)加上两个链表相同位的数值,(c的个位)为当前位的值,(c的十位)为当前位的进位
利用三目运算符,如果l1为空说明l1加完了,就给进位加0(不变),l1始终不变,不为空则加l1当前位值,l1移向下一位,l2同理,直到l1,l2为空,c为0
迭代申请了虚拟头结点方便开始操作,结束后避免空间泄露应该释放,循环过程中需要前后指针的转换,代码冗长,但易懂
**通过迭代的大数相加原理得到该题最简递归算法**
***博客：[两数相加I/II](https://blog.csdn.net/weixin_44529350/article/details/98753428)***
方法一：迭代
```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int c=0;
    struct ListNode *head,*cur,*next;
    head=(struct ListNode *)malloc(sizeof(struct ListNode));
    head->next=NULL;
    cur=head;
    while(l1!=NULL||l2!=NULL||c)
    {
        next=(struct ListNode *)malloc(sizeof(struct ListNode));
        next->next=NULL;
        cur->next=next;
        cur=next;
        l1=l1!=NULL?(c+=l1->val,l1->next):l1;
        l2=l2!=NULL?(c+=l2->val,l2->next):l2;
        cur->val=c%10;
        c=c/10;
    }
    struct ListNode *del=head;
    head=head->next;
    free(del);
    return head;
}
```

方法二：递归
```c
int c=0;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL&&c==0)return NULL;
    l1=l1!=NULL?(c+=l1->val,l1->next):l1;
    l2=l2!=NULL?(c+=l2->val,l2->next):l2;
    struct ListNode *cur=(struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val=c%10;
    c=c/10;
    cur->next=addTwoNumbers(l1,l2);
    return cur;
}

```
