
![image.png](https://pic.leetcode-cn.com/d7880cd8376f7caa4d121e787014737ece8c0d92f8678fc6c2010c231f977d9a-image.png)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int i;
    if(head == NULL)return NULL;
    struct ListNode* p, *last, *tmp;
    p = head;
    last = head;
    for(i = 0; i < n; i ++){
        last = last->next;
    }
    if(last == NULL){
        tmp = head->next;
        free(head);
        return tmp;
    }
    while(last->next != NULL){
        last= last->next;
        p = p->next;
    }
    tmp=p->next;
    p->next = p->next->next;
    free(tmp);
    return head;
}
```

