### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//反转链表
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL,*curr=head,*q;
    while (curr != NULL) {
        q= curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    return prev;
}

//(1)反转[1,len]   (2)反转[1，d]    (3)反转[d+1,len]
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* p,*q,*r;
    int len=0,d,i;
    p=head;
    while(p!=NULL){        //统计长度
        len++;
        p=p->next;
    }
    if(len==0){            //空链表
        return NULL;
    }
    i=d=k%len;               //实际移位次数               
    if(d==0){
        return head;
    }else{
        p=reverseList(head);     //反转[1,len]
        r=p;
        while(d!=1){             //找到1、d、d+1   r=1  p=d  q=d+1
            p=p->next;
            d--;
        }
        q=p->next;
        p->next=NULL;
        p=reverseList(r);        //反转[1，d]
        head=p;
        q=reverseList(q);        //反转[d+1,len]
        while(i!=1){             //找到1、d、d+1   r=1  p=d  q=d+1
            p=p->next;
            i--;
        }
        p->next=q;               //链接[d,d+1]
    }
    return head;
}
```