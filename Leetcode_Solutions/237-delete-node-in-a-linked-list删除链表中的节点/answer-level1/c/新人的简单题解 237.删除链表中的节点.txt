### 解题思路
u1s1,以前删除链表中的结点都是用两个指针，一个指向当前节点，另一个指向前驱，万没想到还有这套路。

node就是指向当前节点的指针，只需要把下一节点的值复制到node，然后删除node->next就可以了，这样node就成为了要删除节点的前驱，目的达成。

为了省点时间，没写free，当然现实中肯定要写的。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
    node->val=node->next->val;
    //struct ListNode* temp=node->next;
    node->next=node->next->next;
    //free(temp);
}
```