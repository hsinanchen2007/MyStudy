### 解题思路
    /*
     * 快慢指针
     *
     * 定义两个指针fastPtr和slowPtr同时指向头节点,其中fastPtr每次走两步,slowPtr每次走一步。
     * 当fastPtr->next时，表示fastPtr走到链表尾，此时slowPtr指向链表中间节点，直接返回；
     * 或当fastPtr->next->next为空时，表示fastPtr走到链表尾前一个节点，
     * 此时slowPtr指向链表中间节点的第一个节点，所以返回slowPtr->next节点。
     * */
### 代码

```cpp
ListNode *middleNode(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *fastPtr = head;
    ListNode *slowPtr = head;

    // 遍历链表，直到fastPtr走到链表尾或链表尾前一节点
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    // 当fastPtr走到链表尾前一节点，
    // 则slowPtr走到中间第一个节点，
    // 返回slowPtr->next节点
    if (fastPtr->next) {
        return slowPtr->next;
    } else {
        // 当fastPtr走到链表尾，
        // slowPtr走到链表中间，直接返回
        return slowPtr;
    }
}
```