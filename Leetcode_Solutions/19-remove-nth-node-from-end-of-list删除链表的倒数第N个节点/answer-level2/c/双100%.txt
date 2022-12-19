/*参考《大话数据结构》单链表某个元素的删除*/
1.计算链表的总长度
2.根据链表长度和n，将p移位到将删除的前一个节点
3.q=p->next;p->next = q->next;free(q);
4.注意特殊情况：
（1）if (!head || !head->next) return NULL; //参数非法或head只有一个节点
（2）if(l==n) return head->next;//如果删除的第一个节点，直接返回head->next;
/**************************代码如下**************************/
//计算链表长度
unsigned int ListLength(struct ListNode* ptr)
{
    unsigned int l=0;
    while(ptr!=NULL)
    {
        l++;
        ptr=ptr->next;
    }
    return l;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

if (!head || !head->next) return NULL; //参数非法或head只有一个节点
int l=0;
int j=1;
struct ListNode* p;
struct ListNode* q;

l=ListLength(head);//计算链表长度
p=head;//赋值
if(l==n) return head->next;//如果删除的第一个节点，直接返回head->next;
while(p && j<(l-n)){ //将p移位到删除的前一个节点
    p=p->next;
    ++j;
}
q=p->next;
p->next = q->next;
free(q);          //释放
return head; 
}