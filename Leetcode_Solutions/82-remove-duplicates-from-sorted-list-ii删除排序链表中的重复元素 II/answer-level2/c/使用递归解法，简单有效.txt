除了二叉树以外，链表也可以看作是递归定义的数据结构。使用递归思想来解答本题比较简单，不需要多重循环嵌套。具体思路如下：
对于一个链表来说:
1. 如果头结点head->val是值和下一个节点head->next->val的值不同，那么保留头节点，然后再递归调用本函数去处理head->next;
2. 如果头结点的值和下一个节点值相同，那么直接删除所有和头节点的值相同的节点后，再递归调用本函数去处理首个非相同值节点。
3. 单独处理空指针和单个节点的情况。

```C
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    } 

    if (head->val != head->next->val) {  // 头结点和下一个节点不同，直接递归处理下一个节点开头的链表。
        head->next = deleteDuplicates(head->next);
        return head;
    }

    struct ListNode *node = head->next;
    int val = head->val;

    while (node != NULL) {  // 相同时，遍历找到首个非相同值节点，再递归处理之。
        if (node->val != val) {
            break;
        } 
        node = node->next;
    }

    return deleteDuplicates(node);
}
```