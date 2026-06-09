![微信截图_20200403215253.png](https://pic.leetcode-cn.com/5f1ac6c11d45a51efd21ecdf9acec01abfa1785feb9337669b2b35c0da81ada1-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200403215253.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
typedef struct Pair
{
    Node *head;
    Node *tail;
} Pair;

Pair quickSort(Node *node)
{
    if (!node || !node->next)
        return (Pair){node, node};

    Node leftHead, rightHead;
    Node *left = &leftHead, *right = &rightHead;
    Node *mid = node, *midHead = node;
    node = node->next;
    Node **ptr;
    while (node)
    {
        ptr = (node->val < mid->val) ? &left
                                     : (node->val > mid->val) ? &right : &mid;
        (*ptr)->next = node;
        (*ptr) = (*ptr)->next;
        node = node->next;
    }
    left->next = right->next = NULL;
    Pair leftPair = quickSort(leftHead.next);
    Pair rightPair = quickSort(rightHead.next);

    Pair pair;
    if (leftPair.tail)
    {
        leftPair.tail->next = midHead;
        mid->next = rightPair.head;
        pair.head = leftPair.head;
    }
    else
    {
        mid->next = rightPair.head;
        pair.head = midHead;
    }
    pair.tail = rightPair.tail ? rightPair.tail : mid;
    return pair;
}
struct ListNode *sortList(struct ListNode *head)
{
    return quickSort(head).head;
}
```