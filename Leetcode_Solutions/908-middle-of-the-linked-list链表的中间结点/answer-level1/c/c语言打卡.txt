### 解题思路
设置一个尾和中间结点，尾每次往下一个，中间结点隔一次往下一个

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
    struct ListNode *midNode = head, *tail = head;
    int len = 1;
    while(tail != NULL && tail->next != NULL){
        tail = tail->next;
        len ++;
        if(len % 2 == 0)
            midNode = midNode->next;
    }
    return midNode;
}
```