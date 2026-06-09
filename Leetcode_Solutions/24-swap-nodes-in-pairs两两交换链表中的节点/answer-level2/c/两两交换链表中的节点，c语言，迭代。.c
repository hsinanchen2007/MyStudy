### 解题思路
链表前两个节点单独处理一下，并且为循环做一下预处理，然后循环，h->q->p 变成h->p->q。
### 代码

```c
struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next){
        return head;
    }
    struct ListNode *q=head,*p=head->next,*result,*h;
    q->next = p->next;            //前两个节点单独处理
    p->next = q;
    result = p;
    h = q;                       //并且为循环做一下预处理 
    q = q->next;
    if(q){
        p = q->next;
    }else{
        p = NULL;
    }
    while(p){                  
        h->next = p;            //h->q->p 变成h->p->q
        q->next = p->next;
        p->next = q;
        h = q;                 
        q = q->next;
        if(q){
            p = q->next;
        }else{
            break;
        }
    }
    return result;
}
```