### 解题思路
![图片.png](https://pic.leetcode-cn.com/b8d00553add4b5f3471b81205cbbe4257c549f3d1a63337740e47a68fe85b200-%E5%9B%BE%E7%89%87.png)
这三种方法都容易理解。
头插法还是考验一些微操的，声明一个头结点是秀起来关键。
递归法也考验微操。
真实的战斗中，不是看你有多秀，而是能在短时间内打出一套爆发，把题做出来即可。
让我选的话，我选头插法，因为它是数据结构考研必须掌握的，精准而优雅，更重要的是我熟悉它。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    int size=0;struct ListNode* p=head;
    while(p!=NULL){
        size++;
        p=p->next;
    }
    struct ListNode*stack[size];
    int top=-1;p=head;
    while(p!=NULL){
        stack[++top]=p;
        p=p->next;
    }
    struct ListNode* head2=stack[top];
    p=head2;
    while(top!=-1){
        p->next=stack[top--];
        p=p->next;
    }
    p->next=NULL;
    return head2;
}
```
头插法：
```c
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *output=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*p=head;struct ListNode*q;struct ListNode*temp;
    output->next=NULL;
    while(p!=NULL){
        temp=output->next;
        q=p->next;
        output->next=p;
        p->next=temp;
        p=q;
    }
    return output->next;
}
```
递归法
```c
struct ListNode*output2;
void reverse(struct ListNode*head,struct ListNode*pre){
    struct ListNode*newhead=head->next;
    head->next=pre;
    if(newhead==NULL){
        output2=head;
    }else{
        reverse(newhead,head);
    }
}
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL)return head;
    reverse(head,NULL);
    return output2;
}
```