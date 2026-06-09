### 解题思路一 双指针迭代法
    /*
     * 方法1 双指针迭代法
     * 设置头节点head(不动)和插入节点node(移动)，
     * 当两链表均不为空时，比较两链表头节点的值，
     * 值较小的节点插入到node节点的next节点，
     * 更新改变的链表的头节点，node节点移动，
     * 当迭代结束后，某一链表可能还有值未访问，
     * 将剩下有序的节点插入node的next节点即可，
     * 因为初始化node=head,所以返回head的next节点
     * */
### 代码

```cpp
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // 判断l1与l2是否为空的情况
    // 包含了l1、l2同时为空的可能
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    }

    // 对合并链表的头节点初始化
    // 下面两种方式都可
    auto *head = (ListNode*)malloc(sizeof(ListNode));
//    ListNode *head = new ListNode(1);

    // 设置插入节点
    ListNode *node = head;

    // 当两链表均未访问到空节点时进行值比较
    while (l1 != nullptr && l2!= nullptr){
        if(l1->val < l2->val){
            // l1头节点的值较小时，
            // 将该节点插入node节点的next节点
            // WARNing: 不要插入node节点，
            // 不然后面node=node->next会访问空指针
            node->next = l1;

            // l1指向链表的next节点
            l1 = l1->next;
        } else{
            node->next = l2;
            l2 = l2->next;
        }
        // node节点指向next节点
        // 更新next节点的值
        node = node->next;
    }

    // l1 或者 l2 为空时，
    // 将另一链表剩余部分全部插到合并链表后即可
    node->next = (l1 == nullptr ? l2 : l1);

    // 因为最开始是插入到node节点的next节点
    // 所以返回的是head节点的next节点
    return head->next;
}
```

### 解题思路二 递归法
    /*
     * 方法2 递归法
     * 设置合并链表头节点head,比较两链表头节点的值，
     * 值较小的节点插入head节点，递归函数返回head节点的next节点的值
     * 返回合并链表的head节点
     * */
### 代码

```cpp
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    // 判断l1与l2是否为空的情况
    // 包含了l1、l2同时为空的可能
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    }

    ListNode *head = nullptr;

    // 对l1和l2当前头节点的值进行比较
    if(l1->val < l2->val){
        // l1头节点的值较小，则将该节点插入合并链表中
        head = l1;
        // 递归函数返回合并链表的下一个节点
        head->next = mergeTwoLists(l1->next, l2);
    }else{
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }

    return head;
}
```