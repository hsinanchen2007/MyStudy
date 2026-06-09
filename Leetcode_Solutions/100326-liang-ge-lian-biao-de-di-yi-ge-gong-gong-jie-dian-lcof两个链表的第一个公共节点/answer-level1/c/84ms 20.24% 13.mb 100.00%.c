### 解题思路
要不是408见过我还真不会做。。。不过这速度太慢了8

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lena=0,lenb=0;
    ListNode *p=headA,*q=headB;
    while(p!=NULL||q!=NULL){
        if(p!=NULL){
            lena++;
            p=p->next;
        }
        if(q!=NULL){
            lenb++;
            q=q->next;
        }
    }    
    int minus=(lena>lenb)?(lena-lenb):(lenb-lena);
    p=(lena>lenb)?headA:headB;q=headA-p+headB;
    while(minus>0){
        p=p->next;
        minus--;
    }
    while(p!=NULL){
        if(p==q){
            return p;
        }
        p=p->next;
        q=q->next;
    }
    return NULL;
}
```