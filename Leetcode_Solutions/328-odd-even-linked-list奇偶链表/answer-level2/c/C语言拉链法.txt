解题思路
感觉算是比较简单的解法，解题过程形如解开衣服拉上的拉链
在链表>=2个结点时，拉链的两侧各需要一个头节点指针。
head=奇数head
last=偶数head

如：1->2->3->null

last=2 偶数链表头节点是2
temp=3, 暂存 last->next
连接偶数链表的下一个，即2->null 偶数链表的当前位置前进（b=b->next）
temp把两个偶数结点之间的奇数结点保存下来（2->null之间的3），直接加到奇数链表的后面（head->next=temp）
此时奇数链表：1->3
奇数链表当前位置前进。

以上，进行循环。

循环退出条件：
1、null出现在偶数位：如1->2->3->NULL，偶数链表的当前节点为NULL时停止：
NULL进入偶数链表最后一个位置
偶数链表当前位置前进
当前位置=NULL
停止
2、null出现在奇数位：如1->2->NULL
temp=NULL时停止
 tips：如1->2->NULL 或 1->2->3->4->NULL
 2->next =NULL =temp
 4->next=NULL =temp
 所以最后不要在末尾手动添加NULL


最后：连接两个表：
奇数链表当前位置->next=偶数链表头节点
返回奇数链表头节点

    

```
struct ListNode* oddEvenList(struct ListNode* head){
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
        return head;
    struct ListNode* last=head->next;//偶数
    struct ListNode* a=head;
    struct ListNode* b=last;//偶数
    struct ListNode* temp;
    
    temp=b->next;
    while (temp!=NULL){
        b->next=b->next->next;
        b=b->next;
        a->next=temp;
        a=a->next;
        if (b==NULL)
            break;
        temp=b->next;
    }
    a->next=last;
    return head;
}

```
