### 解题思路一 双指针迭代法
    /*
     * 方法1 双指针迭代法
     *
     * 1->2->3->4->5->null
     * 1<-2<3   4->5->null
     *
     * 因为要反转链表，
     * 遍历节点visitnode只知道next节点，
     * 所以需要在visitnode前设置一个前节点prenode，
     * 每遍历一个节点，就将visitnode的next指向prenode，
     * 因为每次链表会断裂，需要将visitnode节点提前保存为nextnode，
     * 在将visitnode设为prenode，nextnode设为visitnode
     * 重复上述每一次遍历的操作，直到visitnode为空节点，
     * 在此前，最后一个节点已经赋给prenode，
     * 所以返回prenode为反转链表的头节点
     * */
### 代码

```cpp
ListNode *reverseList(ListNode *head) {
    // 空链表
    if (head == nullptr) {
        return head;
    }

    // 遍历链表指针
    ListNode *visitnode = head;
    // 指向遍历指针前一节点的指针
    ListNode *prenode = nullptr;

    while (visitnode != nullptr) {
        // 每遍历一个节点，将该节点的next节点保存
        ListNode *nextnode = visitnode->next;

        // 每遍历一个节点后，对节点进行反转
        // 将该节点的next指针指向prenode节点
        // 此时遍历节点与nextnode之间断裂
        visitnode->next = prenode;

        // prenode节点指向遍历节点
        prenode = visitnode;

        // 将保存好的nextnode节点交给遍历节点继续遍历
        visitnode = nextnode;
    }

    // 最后prenode=visitnode，
    // 即prenode为反转链表的头节点
    // 而最后visitnode为空节点
    return prenode;
}
```

### 解题思路二 递归法
    /*
     * 方法2 递归法
     *
     * 1->2->3->4->5->null
     * 1->2->3->4<-5
     *
     * 递归法的难点有两个：
     * 1. 终止条件： 因为要反转链表，
     *    如果只是当前节点为null，则需要多一个节点，
     *    使当前节点为该节点的next的下一个节点，
     *    如果设为当前节点为null或下一节点为null，
     *    就能将当前节点设为next节点的next节点，
     *    达到反转的目的
     * 2. 头节点的返回：因为要返回头节点，
     *    所以递归函数返回的结果不能随递归变化，
     *    在递归函数内部，每次改变的是当前节点的指向
     *    (这里容易想到返回的结果也变化，那最终返回不了头节点)
     *
     * WARNing : 指针反转后，要设置当前节点的next节点为null，
     *           不然会发生循环，例如2个节点时
     * */
### 代码

```cpp
ListNode *reverseList2(ListNode *head) {
    // 递归终止条件是当前为空，或下一节点为空
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // node为原链表的最后一个节点，
    // 也即反转链表的头节点
    ListNode *node = reverseList2(head->next);

    // node为最后一个节点，
    // head此时为倒数第二个节点，
    // 反转即是将head节点设为head->next的next节点
    head->next->next = head;

    // 防止链表循环，例如2个节点时，
    // 需要将head->next设为空
    head->next = nullptr;

    // 每层递归都返回node节点
    return node;
}
```