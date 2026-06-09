### 解题思路

链表的删除操作其实很简单，就是`prev->next = curr->next`, 将前继节点的下一个节点设置为当前节点的下一个节点。

但是一个令人讨厌的问题在于，如何第一个节点的处理。毕竟我们都是第一个节点了，哪里来的前面节点？

没有节点，我们就创造节点，这就是哨兵节点，我们申请新的节点，将其作为头节点的前一个节点。然后第一个前继节点就是这个哨兵节点，当前节点就是head，后面处理就很方便了。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    //哨兵节点来了
    struct ListNode *sentinel = malloc(sizeof(struct ListNode));
    sentinel->next = head;
    //第一个节点的当前节点恶化前继节点
    struct ListNode *curr = head, *prev = sentinel;
    
    while (curr != NULL){
        if (curr->val == val){
            prev->next = curr->next;
        } else{
            prev = curr;
        }
        curr = curr->next;
    }
    return sentinel->next;

}
```

最后应该加上`free(sentinel)`, 把申请的内存归还回去。