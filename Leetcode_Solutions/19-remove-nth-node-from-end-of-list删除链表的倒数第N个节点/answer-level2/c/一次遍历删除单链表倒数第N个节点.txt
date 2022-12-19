### 解题思路

 双指针，l1,l2都指向链表头，l1先走n步，然后l1与l2一起向后遍历，此时两个指针之间的距离就是n，当l1->next为null时，l2指向的是要删除的节点的前一个节点，直接l2->next=l2->next->next，即可。

 注意判断边界，比如删除链表的头结点，可以直接判断l2，如果为空就表示删除头结点。

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
    struct ListNode *front = head;
    struct ListNode *last = head;
    while (n>0){
        front = front->next;
        n--;
    }
    if (front == NULL){
        return last->next;
    }
    while (front->next != NULL){
        front = front->next;
        last = last->next;
    }
    last->next = last->next->next;
    return head;
}
```