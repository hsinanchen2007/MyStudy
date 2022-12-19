### 解题思路一 拆分法
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
    if (head == nullptr) {
        return head;
    }

    copyNodes(head);
    connectRandomNode(head);

    return splitCopyNodeList(head);
}

void copyNodes(Node *head) {
    Node *node = head;

    while (node != nullptr) {
        Node *copyNode = new Node(0);
        // 复制节点
        copyNode->val = node->val;
        copyNode->next = node->next;
        copyNode->random = nullptr;

        // 将复制节点挂在原节点后
        node->next = copyNode;
        node = copyNode->next;
    }
}

void connectRandomNode(Node *head) {
    Node *node = head;

    while (node != nullptr) {
        Node *copyNode = node->next;
        // 复制random指针
        if (node->random != nullptr) {
            copyNode->random = node->random->next;
        }

        node = copyNode->next;
    }
}

Node *splitCopyNodeList(Node *head) {
    Node *node = head;
    Node *copyHead = nullptr;
    Node *copyNode = nullptr;

    // 因为是返回拆分后的链表
    // 所以先要将原链表第一个节点拆除
    if (node != nullptr) {
        copyHead = node->next;
        copyNode = copyHead;
        node->next = copyNode->next;
        node = node->next;
    }

    // 拆出复制的链表
    while (node != nullptr) {
        copyNode->next = node->next;
        copyNode = copyNode->next;
        node->next = copyNode->next;
        node = node->next;
    }

    return copyHead;
}
```

### 解题思路二 哈希表法

    /*
     * 哈希表法
     *
     * 使用map<Node*,Node*>建立哈希表，
     * 将原节点与复制节点对应起来，
     *
     * 1. 建立 map 。map<Node *, Node *> visited；
     * 2. NULL 指针加入 map ，当指针为 NULL 时能对应visited[NULL] = NULL；
     * 3. 使用标准链表遍历方式： while (pNode != NULL) pNode = pNode->next；
     * 4. new 新的 Node ，并保存在 map 中；
     * 5. 指针回到 head ，再遍历一遍链表，用来复制 Node 中的数据；
     * 6. 需要复制的有：val, random, next；
     * 7. 返回新数据的 head 指针，没错，就是 visited[head] 。
     * */
### 代码
```cpp
Node *copyRandomList2(Node *head) {
    if (head == nullptr) {
        return head;
    }

    std::map<Node *, Node *> visited;
    visited[nullptr] = nullptr;

    Node *prev = nullptr;
    Node *node = head;

    // 建立原链表的哈希表，
    // 使用map存储原节点与复制节点的对应关系
    while (node != nullptr) {
        Node *newNode = new Node(head->val);
        visited[node] = newNode;
        node = node->next;
    }

    // 重置node节点
    node = head;

    // 复制链表的每个节点
    while (node != nullptr) {
        // 从复制链表的第一个节点开始
        // newNode作为临时节点
        Node *newNode = visited[node];

        // 复制节点的value和random指针
        newNode->val = node->val;
        newNode->random = visited[node->random];
        newNode->next = nullptr;

        // 连接复制链表的每个节点
        // 复制next指针
        if (prev != nullptr) {
            visited[prev]->next = newNode;
        }

        prev = node;
        node = node->next;
    }

    return visited[head];
}
```


### 解题思路三 回溯法

    /*
     * 回溯法
     *
     * 回溯算法的第一想法是将链表想象成一张图或树，如图1。
     * 链表中每个节点都有 2 个指针（图中的边）。
     * 因为随机指针给图结构添加了随机性，
     * 所以我们可能会访问相同的节点多次，这样就形成了环。
     *
     * 图1 复杂链表的复制回溯法1.png
     * 图2 复杂链表的复制回溯法2.png
     *
     * 1. 从头指针开始遍历整个图，如图2；
     * 2. 当遍历到某个节点时，如果已经有了当前节点的拷贝，则无需重复拷贝；
     * 3. 如果没有拷贝当前节点，则创造新节点，并放入map访问字典中；
     * 4. 进行回溯调用：顺着next指针和顺着random指针
     * */
### 代码
```cpp
Node *copyRandomList3(Node *head) {
    std::map<Node *, Node *> visited;

    if (head == nullptr) {
        return head;
    }

    // 回溯结束条件
    if (visited.count(head)) {
        return visited[head];
    }

    // 复制节点且复制值
    Node *node = new Node(head->val);

    // 做选择
    visited[head] = node;

    // 进入下一层决策
    // 复制next和random指针
    node->next = copyRandomList3(head->next);
    node->random = copyRandomList3(head->random);


    return node;
}
```