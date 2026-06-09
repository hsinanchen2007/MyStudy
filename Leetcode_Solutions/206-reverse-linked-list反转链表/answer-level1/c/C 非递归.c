### 解题思路
1.使用新的头节点保存返回结果。
2.具体参考代码
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*使用一个Head2存储结果，遍历链表使用头插法*/
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* ans = NULL;
    struct ListNode* p = head;
    while(p){
        if (ans == NULL){
            ans = p;
            p = p->next;
            ans->next = NULL;
        } else {
            struct ListNode* tmp = p->next;
            p->next = ans;
            ans = p;
            p = tmp;
        }
    }
    return ans;
}
```