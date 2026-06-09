### 解题思路
关键在于找到分界节点即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode*newnode1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*tmp1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*tmp2=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode1=head;
    if(head==NULL)
        return head;
    int length=1;
    while(newnode1->next!=NULL)      //计算链表长度
    {
        newnode1=newnode1->next;
        length++;
    }
    k=length-k%length;     //计算要移动几次
    if(k==length)
        return head;
    tmp1=head;
    for(int i=0;i<k-1;i++)
    {
        tmp1=tmp1->next;      //找到分界节点
    }
    tmp2=tmp1->next;          //新链表的头结点
    tmp1->next=NULL;          //将尾部指向空节点
    newnode1->next=head;      //将原链表尾部指向指向原链表头
    return tmp2;

}
```