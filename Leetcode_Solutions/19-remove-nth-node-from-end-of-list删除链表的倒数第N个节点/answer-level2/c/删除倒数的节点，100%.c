### 解题思路
此处撰写解题思路
要考虑只有一个节点和两个节点的情况，其他的一前一后两个指针相距n,还有一个指向前一个指针的签一个节点，然后向后移动即可，
当最后一个为0时，只需要pre->next=p->next,即可。
（注意：头节点指的是第一个有值的头节点，有的书说的头节点，只是为了统一操作设置的无值节点。这里的头节点等价于头指针）

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p,*q,*pre;
    int len=0;
    pre=head;
    p=head;
    q=head;
    while(n--){
        q=q->next;
        if(!q&&n==1){
            return NULL;
        }

    }
    if(q==NULL){
        head=p->next;
    }
    
    while(q){
        pre=p;
        p=p->next;
        q=q->next;
    }
    pre->next=p->next;
    return head;
}
```