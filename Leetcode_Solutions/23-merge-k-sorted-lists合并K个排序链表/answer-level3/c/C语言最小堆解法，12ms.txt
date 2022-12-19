### 解题思路
利用最小堆的数据结构，把每个链表的头放进堆里。
只需要堆的两个操作，buildHeap和increaseKey，而这两个操作又只需要一个共同的pocolateDown(下滤)操作。
为了编写方便，增加了一个NULLNODE节点，并在堆的头部安了一个哑节点。

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
static inline void pocolateDown(Node **heap, int i, int heapSize)
{
    int child;
    Node *temp;
    for (child = i * 2; child <= heapSize; i = child, child *= 2)
    {
        if (child + 1 <= heapSize && heap[child + 1]->val < heap[child]->val)
            child++;
        if (heap[child]->val < heap[i]->val)
        {
            temp = heap[i];
            heap[i] = heap[child];
            heap[child] = temp;
        }
        else
            break;
    }
}
Node *mergeKLists(Node **lists, int listsSize)
{

    Node *heap[listsSize + 1];
    int heapSize = 0;
    for (int i = 0; i < listsSize; i++)
        if (lists[i])
            heap[++heapSize] = lists[i];
    if (heapSize == 0)
        return NULL;
    Node NULLNODE = {.val = INT_MAX, .next = NULL};
    heap[0] = &NULLNODE;
    // buildHeap
    for (int i = heapSize / 2; i > 0; i--)
        pocolateDown(heap, i, heapSize);
    Node head;
    Node *node = &head;
    while (heap[1]->val < INT_MAX)
    {
        node->next = heap[1];
        node = node->next;
        heap[1] = heap[1]->next;
        if (heap[1] == NULL)
            heap[1] = &NULLNODE;
        pocolateDown(heap, 1, heapSize); // increaseKey
    }
    return head.next;
}
```