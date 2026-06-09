### 解题思路
快慢指针，让两指针一开始指向head，q先走k步，后p,q同时走，当q==NULL时，p即为所求。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int cnt=0;
    struct ListNode *p=head,*q=head;
    while(q)
    {
        if(cnt>=k)
        {
            p=p->next;
        }
        q=q->next;
        cnt++;
    }
    return p;
}
    
```