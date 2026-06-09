建议大家每种方法都自己画图试一次，可以方便理解很多
### 头插法
使用头结点

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *p,*q;
    ListNode *t= new ListNode(1);       //t作头结点        
    p=head;
    t->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;

        q->next=t->next;
        t->next=q;
    }
    head=q;
    return head;
    }
};
```

### 逆置

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *cur=NULL;
    ListNode *pre=head;

    while(pre)
    {
        ListNode *t=pre->next;
        pre->next=cur;

        cur=pre;
        pre=t;
    }
   return cur;
    }
};
```
### 递归

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL)    return head;    //递归终止条件

    ListNode* s= reverseList(head->next);     //s的值始终为一开始的表尾，最后被用来当做新的表头使用
    head->next->next=head;                    //使下一个节点指向自己
    head->next= NULL;                         //使自己指向NULL

    return s;
    }
    
};
```