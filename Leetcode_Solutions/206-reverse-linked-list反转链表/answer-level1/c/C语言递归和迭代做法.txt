### 解题思路
c语言的递归和迭代做法

### 代码
递归做法，假设后面的都已经翻转，仅仅把当前位置指向前一个结点进行迭代，但要注意首结点的下一个必须为NULL
```c

struct ListNode* reverseList(struct ListNode* head){

    if(head==NULL||head->next==NULL)   
            return head;
    struct ListNode* tr=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return tr;

}
```

迭代做法：
```
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *tr1=NULL,*tr2=head;
    while(head！=NULL)
    {
        head=head->next;
        tr2->next=tr1;
        tr1=tr2;
        tr2=head;
    }
 return tr1;


}
```
tr1为第一个前一个位置，tr2为当前位置，head为后一个位置进行迭代
