### 解题思路
遍历链表计数，找到一半处，返回。

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
    struct ListNode* l = head;
    if(head == NULL){
        return NULL;
    }
    int count = 0;
    while(l != NULL){
        l = l->next;
        count++;
    }
    if(count == 1){
        return head;
    }
    l = head;
    count = count/2;
    while(count != 0){
        l = l->next;
        count--;
    }
    return l;
}
```