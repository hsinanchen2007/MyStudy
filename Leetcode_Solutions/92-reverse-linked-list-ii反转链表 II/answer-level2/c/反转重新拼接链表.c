### 解题思路
反转链表[m, n]， 然后重新拼接链表 

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* dummpHead = (struct ListNode*) calloc(1, sizeof(struct ListNode));
    dummpHead -> next = head;
    struct ListNode* pre = dummpHead;
    struct ListNode* cur = head;
    struct ListNode* next, *start, *end; // start 指向链表 m - 1  位置的元素， end 指向链表 n 位置的元素
    int i = 1; // cur 指向位置的索引
    while(cur != NULL && i <= n){
        next = cur -> next;
        if(i == m){ // start 指向链表 m - 1 位置的元素
            start = pre;
        }
        if(i == n){ // end 指向链表 n 位置的元素
            end = cur;
        }
        if(i > m && i <= n){ // 反转链表[m, n] 位置的元素， 所以最开始是将 m + 1 指向 m， 而最后是将 n 指向 n - 1
            cur -> next = pre;
        }
        pre = cur;
        cur = next;
        i++;
    }
    start -> next -> next =  next; // 链表[m, n] start -> next -> next 即 list[m] -> next 此时他是 [m, n] 反转后的尾元素， 指向 list[n] 的后一个元素 next（这里不能使用 list[n]-> next 因为 list[n] 已经被反转）
    start -> next = end; // 链表[m, n] list[m-1] —> 指向 list[n] 
    struct ListNode* ret = dummpHead -> next;
    free(dummpHead);
    return ret;
}
```