### 解题思路
此处撰写解题思路
 要考虑初始的两个节点和后面的两个节点的操作是不同的，后面的节点在交换之前，要保留上次交换后最后的节点，保证有链接。
初始情况为：
        pre->next=p->next;
        p->next=pre;
        head=p;
        q=pre;
后续的情况为：
        pre->next=p->next;
        p->next=pre;
        q->next=p;
        q=pre;

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p,*pre,*q;
    pre=head;
    if(!pre){
        return head;
    }
    p=pre->next;
    if((!p)){
        return head;
    }
    int x=0;
    while(pre&&p){
        x++;
        
       
        if(x==1){
            
            pre->next=p->next;
            p->next=pre;
            head=p;
            q=pre;
        }
        else{
        
        pre->next=p->next;
        p->next=pre;
        q->next=p;
        q=pre;
        
        }
        pre=pre->next;
        if(pre){
             p=pre->next;
        }
       

    }
    return head;

}
```