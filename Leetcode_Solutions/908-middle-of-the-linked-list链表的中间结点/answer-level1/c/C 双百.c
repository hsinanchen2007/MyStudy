### 解题思路
![批注 2020-03-23 102445.png](https://pic.leetcode-cn.com/6bf74c738c5ee1f06786e526086a30c280f68ee1126ee397f484efbe034842ce-%E6%89%B9%E6%B3%A8%202020-03-23%20102445.png)

首先遍历一遍单链表，记录链表的长度，然后count/2+1求出中间节点的位置。最后再将指向头节点的ret移动到中间节点便可。


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
    struct ListNode* ret = head;
    int count = 1;
    while(head!=NULL&&head->next!=NULL){
        head = head->next;
        count++;
    }
    count = count/2+1;
    while(count-- > 1)    ret = ret->next;
    return ret;
}
```