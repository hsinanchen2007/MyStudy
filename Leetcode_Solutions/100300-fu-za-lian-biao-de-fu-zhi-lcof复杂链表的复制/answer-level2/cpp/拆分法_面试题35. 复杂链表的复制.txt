### 解题思路 复杂问题拆分处理

    /*
     * 分解法
     *
     * A->A'->B->B'->C->C'->D->D'->E->E'
     * |_____R|_______|R    |      |R
     *        |_____________|______|
     *        |_____________|
     *
     * 1. 根据原链表的value和next对原链表进行复制，
     *    复制的节点在原节点之后，此步未处理random指针
     * 2. 遍历链表，复制每个节点的random指针
     * 3. 将复制后的链表拆分为原链表和复制链表。
     * */

### 代码

```cpp
Node *copyRandomList(Node *head) {
    if(head == nullptr){
        return head;
    }

    copyNodes(head);
    connectRandomNode(head);

    return splitCopyNodeList(head);
}
    /*
     * 复制原链表的节点，
     * 复制节点接在原节点之后
     * */
void copyNodes(Node *head) {
    Node* node = head;

    while (node != nullptr){
        Node* copyNode = new Node(0);
        // 复制节点
        copyNode->val = node->val;
        copyNode->next = node->next;
        copyNode->random = nullptr;

        // 将复制节点挂在原节点后
        node->next = copyNode;
        node = copyNode->next;
    }
}
    /*
     * 遍历链表，复制random指针
     * */
void connectRandomNode(Node *head) {
    Node* node = head;

    while (node != nullptr){
        Node* copyNode = node->next;
        // 复制random指针
        if(node->random != nullptr){
            copyNode->random = node->random->next;
        }

        node = copyNode->next;
    }
}
    /*
     * 拆分复制链表
     * */
Node *splitCopyNodeList(Node *head) {
    Node* node = head;
    Node* copyHead = nullptr;
    Node* copyNode = nullptr;

    // 因为是返回拆分后的链表
    // 所以先要将原链表第一个节点拆除
    if(node != nullptr){
        copyHead = node->next;
        copyNode = copyHead;
        node->next = copyNode->next;
        node = node->next;
    }

    // 拆出复制的链表
    while (node != nullptr){
        copyNode->next = node->next;
        copyNode = copyNode->next;
        node->next = copyNode->next;
        node = node->next;
    }

    return copyHead;
}
```