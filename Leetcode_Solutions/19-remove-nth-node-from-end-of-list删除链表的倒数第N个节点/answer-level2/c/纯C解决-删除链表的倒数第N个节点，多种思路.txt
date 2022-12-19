### 解题思路
这里给出两种思路，还有一种记录链表长度的常规方法我就不写了，应该大家都会的。

主要就是写一下递归思路和稍微利用了一下数学的思想解决的方案，时间都是双100%

### 方法一：
我们的目标是要求删除倒数的元素，那么我完全可以利用栈的思想，先进后出，从倒数开始计数，栈的另外一种模式就是递归，这也是链表解决问题的常规思路之一

然后考虑第二点，既然这里考虑到了删除，那么我的目标其实是待删除元素的前驱元素，找出了前驱，直接删除后继
为了统一化操作，添加一个头结点是必要的。

这里给出一个例子，从倒数开始减数：
```
1->2->3->4->5,

-2 -1 0  1  2
```
我们当N==0时删除后继即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//递归法
void findpre(struct ListNode *head,struct ListNode *pre,int *n)
{
    
    if(!head) return ;
    findpre(head->next,pre,n);
    if(*n==0)
     {
         pre=head;
         struct ListNode *q=pre->next;
         pre->next=q->next;
         free(q);
     }
    (*n)--;

}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(n==0)return head;
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=head;

    struct ListNode *pre=new_head;
    findpre(new_head,pre,&n);

    return new_head->next;
}
```
### 方法二：
这里再给出一种数学的解题思路，目标还是倒数第N个元素，然后我们的总长度是LEN

`倒数第N个`----->`正数LEN-N个`

那么常规思路就是我们先求出LEN，然后再算LEN-N，我这里不用这种思想，当然我相信大家都会这样写的。
这里采用双指针，先让第一个先走N个元素，然后再让另外一个元素从第一个结点开始，两个结点同时移动，当第一个先走了N个元素的结点走到了结尾，那么第二个元素不就和第一个元素之间相差了N个单位吗？

再结合上面的分析，我们需要找个前驱，并且自建一个头结点即可。我让q,p都是指向目标元素的前驱
这里同样给一个例子：
```
1->2->3->4->5，n=2   ---->   1->2->3->4->5   ---->   1->2->3->4->5 
                             p                             q     p


```


若有疑问~欢迎提问
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//数学法
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(n==0)return head;
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=head;
    struct ListNode *p=new_head,*q=new_head;
    while(n)
    {
        p=p->next;
        n--;
    }
    while(p&&p->next)
    {
        p=p->next;
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    free(p);
    return new_head->next;
}

```
