![image.png](https://pic.leetcode-cn.com/87d028d20f04f91439f5a82beb99d7d06b7ebff850e91688cddca27d51cf5b59-image.png)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    
    if(!head)  return NULL;

    struct ListNode*p,*temp,*pre,*L; 
    L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    pre=L;
    p=head;
    while(p)
    {
        if(p->val==val)
          {
              while(p&&p->val==val)//判断是否有连续相同的值存在
              {
                  p=p->next;
              }
              if(!p)//最后一个元素为空的话
              pre->next=NULL;
              else
              {
                pre->next=p;
                pre=pre->next;
                p=p->next;
              }         
          }
        else
        {
            pre=pre->next;
            p=p->next;
        }
    }

    return L->next;
}
```
```
struct ListNode* removeElements(struct ListNode* head, int val){
    
    if(!head)  return NULL;
    while(head&&head->val==val)
    {
        head=head->next;
    }
    if(!head)//特殊情况
    return head;
    //头结点不为val值
    struct ListNode*p,*pre;
    pre=head;//head的val值必然不为val
    p=head->next;
    while(p)
    {
        if(p->val==val)
        {
            while(p&&p->val==val)
                p=p->next;
            if(!p)
                pre->next=NULL;
            else 
            {
                pre->next=p;
                pre=pre->next;
                p=p->next;
            }
        } 
        else
        {
            pre=pre->next;
            p=p->next;
        }
    }
    return head;
}
```
