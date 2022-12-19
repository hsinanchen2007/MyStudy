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


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode * p = head;
    struct ListNode * pNew;
    int len = 0;
    int index = 0;
    if(p == NULL){
        return head;
    }
    else if(p->next == NULL){
        return head;
    }
    else{
        while(p->next){
                p = p->next;
                len ++;
        }
        len ++;
        p->next = head;
        index = len - k % len - 1;    
        p = head;
        while(index > 0){
            p = p->next;
            index --;
        }
        pNew = p->next;
        p->next = NULL;
        return pNew;
    }
    
}
```