
把链表1和链表2相加的和结果储存在链表1的各结点中，最后返回链表1。
链表1空间不够时，调用链表2的空间attach给链表1。以下详细解释。


```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//定义进位标志、节点和、链表1的头、当前结点空间、链表2的头
    int plus = 0,nodeSum = 0;
    struct ListNode *head1=(l1 ? l1 : (l2 ? l2 : NULL));
    struct ListNode *cur;
    struct ListNode *head2=l2;

//当l1 l2 进位标志plus 至少存在一者时，运算继续。
    while( l1 || l2 || plus) { 

//分配运算空间。这一段涵盖三种情况：先从头调用链表1空间；
//如果l2较长，那么从链表2当前节点开始调用节点空间；
//如果链表1与2等长，最后一位是进位，那么调用l2的头结点空间，并把链表2从头结点处切断。
        cur->next =( l1 ? l1 : ( l2 ? l2 : head2 )); 
        cur=cur->next;
        if(!l1 && !l2){
            cur->next=NULL;
        }

//加法，易理解
        nodeSum = ( l1 ? l1->val : 0 ) + (l2 ? l2->val : 0) + plus;  
        cur->val = nodeSum % 10;    
        plus =  nodeSum / 10; 

//l1 l2指针后移
        l1 ? l1 = (l1->next ? l1->next : NULL) : NULL;
        l2 ? l2 = (l2->next ? l2->next : NULL) : NULL;
    }
    return head1;
}
```