### 解题思路
我们先来看看什么叫`逆转`
`逆转`也就是把每个元素倒序重新排列，根据这一点我们来分析一下这道题

这里给了三种方法：
### 方法一
    我们也就是把前后变成后前，也就是说两两需要改变前后关系，这里就涉及到了原来的那后的后驱如何找到。这里直接用了三个指针，分别指向前驱，当前节点，后继，举个例子：
```
1-->2-->3       ------->      1<--2<--3
pre head r                             
```
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//存后驱法
struct ListNode* reverseList(struct ListNode* head){
    if(!head||!head->next)return head;

    struct ListNode *pre=head,*r;
    head=head->next;
    r=head->next;
    pre->next=NULL;
    while(head)
    {
        r=head->next;
        head->next=pre;
        pre=head;
        head=r;
    }
    return pre;
}
```
### 方法二
    看到了`逆转`，我就想到了`逆序`，正好链表常用的一种方法就是`递归`，`递归`也就是逆序的一种方法，我们只需从后面的依次往前逆转即可。
    注意别忘了给原来的头节点，将其后驱置空。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//递归法1
void Reverse(struct ListNode *head,struct ListNode **new_head)
{
    if(!head->next)
    {
        *new_head=head;
        return;
    }
    Reverse(head->next,new_head);

    //逆转相邻的两个节点
    struct ListNode *r=head->next;
    r->next=head;
}
struct ListNode* reverseList(struct ListNode* head){
    if(!head||!head->next)return head;
    struct ListNode *new_head=head;
    Reverse(head,&new_head);
    head->next=NULL;
    return new_head;
}
```
```c
//递归法2
struct ListNode* reverseList(struct ListNode* head){
    if(!head||!head->next)
    return head;

    struct ListNode *p=reverseList(head->next);
    head->next->next=head;//翻转前后两个
    head->next=NULL;

    return p;//返回新的头结点
}
```

### 方法三
    头插法，我觉得很简单了，直接上代码
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//头插法
struct ListNode* reverseList(struct ListNode* head){
    if(!head||!head->next)return head;
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=NULL;

    struct ListNode *r;
    while(head)//头插法
    {
        r=head->next;
        head->next=new_head->next;
        new_head->next=head;
        head=r;
    }
    return new_head->next;
}


```
