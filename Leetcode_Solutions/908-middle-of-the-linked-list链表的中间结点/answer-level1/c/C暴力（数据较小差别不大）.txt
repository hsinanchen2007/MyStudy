### 解题思路
先遍历一遍得到链表长度，然后得到长度的一半，然后再遍历到中间，返回中间节点即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    if(!head) return head;
    int len = 0;
    struct ListNode* p = head;
    while(p){
        len++;
        p = p->next;
    }
    len /= 2;
    while(len){
        head = head->next;
        len--;
    }
    return head;
}
```