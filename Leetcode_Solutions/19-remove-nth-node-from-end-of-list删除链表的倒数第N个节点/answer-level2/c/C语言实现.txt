### 解题思路
设两个指针p, q均初始化指向head，p遍历链表，同时设置一个count变量计数，初始化为1，当count>n时q开始移动，最后当count == n 时说明要删除的是第一个节点，head = head->next, 否则q = q->next->next; 

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
    struct ListNode *p = head, *q = head;
    int count = 1;
    // if(!p->next){
    //     head = head->next;
    //     return head;
    // }
    while(p->next){
        p = p->next;
        if(count++ > n){
            q = q->next;
        }
    }
    if(count == n){
        return head = head->next;
    }
    else{
        q->next = q->next->next;
        return head;
    }
    

}
```