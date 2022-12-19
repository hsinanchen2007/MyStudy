### 解题思路
处理起来稍微有点麻烦，但是自己细细的捋一下还是轻松的。

###方法一
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *H=(struct ListNode*)malloc(sizeof(struct ListNode));//自建头节点
    H->next=NULL;
    struct ListNode *r=H;
    struct ListNode *p=head,*q=head->next;
    while(p||q)
    {
        if(q&&p->val==q->val)
        {
            while(q&&p->val==q->val)
            q=q->next;
            if(!q)
                break;
            p=q;
            q=q->next;
        }
        if(!q||p->val!=q->val)
        {
            r->next=p;
            r=r->next;
            p=p->next;
            if(q)
            q=q->next;
        }   
    }
    r->next=NULL;
    return H->next;
}
```
###方法二
对于数组哈希的总结:
```
1.一维哈希

2.二维哈希
```
功能：
```
1.一维为了去重

2.二维为了保存相同元素
```

```c
//哈希表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MaxSize 20000
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head||!head->next)return head;

    int hash[MaxSize]={0};
    struct ListNode *p=head;
    while(p)
        {
            hash[p->val+10000]++;
            p=p->next;
        }

    p=head;
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=NULL;

    struct ListNode *r,*pre=new_head;
    while(p)
    {
        //printf("%d ",p->val);
        if(hash[p->val+10000]==1)
        {
            r=p->next;
            p->next=pre->next;
            pre->next=p;
            pre=pre->next;
            p=r;
        }
        else
        p=p->next;
    }
    return new_head->next;
}

```
