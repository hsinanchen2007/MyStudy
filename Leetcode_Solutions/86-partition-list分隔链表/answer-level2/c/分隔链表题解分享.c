### 解题思路

1.这个题目的关键在于创建2个空节点，这样后面拼接的时候，省去了很多麻烦。
2.另外，关于2个链表头指针和“运动中的指针”要格外关注。
3.函数返回的时候，要返回head_small->next,原因是这个节点为空节点，它的下个节点才是真正有意义的节点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* head_small = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head_big = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    struct ListNode* p_small = head_small;
    struct ListNode* p_big = head_big;
    struct ListNode* p = head;
    while(p){
        if(p->val < x)
        {
            p_small->next = p;
            p_small = p_small->next;
        }
        else
        {
            p_big->next = p;
            p_big = p_big->next;
        }
        p = p->next;
    }
    p_big->next = NULL;
    p_small->next = head_big->next;
    return head_small->next;
}
```