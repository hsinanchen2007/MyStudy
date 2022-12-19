### 解题思路
1. head 节点的val是1，head->next的val是2。链表没有头结点。
2. 定义两个指针，从头开始，一个一次一跳，一个一次两跳，两跳的到结尾的时候，一跳的正好在中间

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
    struct ListNode* x1=head,*x2=head;
    while(x2!=0&&x2->next!=0)
    {
        x1=x1->next;
        x2=x2->next->next;
    }
    return x1;
}
```