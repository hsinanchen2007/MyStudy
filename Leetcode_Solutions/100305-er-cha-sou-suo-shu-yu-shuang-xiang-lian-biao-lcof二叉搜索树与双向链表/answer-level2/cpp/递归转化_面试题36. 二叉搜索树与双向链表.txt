### 解题思路
    /*
     * 转换后的链表是有序的双向循环链表，而二叉树有左右两指针与双向链表的前后驱相对应。
     * 又由二叉搜索树左节点<根节点<右节点的特性，可以使用中序遍历二叉树的每个节点。
     * 因为中序遍历算法的特点是按照从小到大的顺序遍历二叉树的每个节点。
     * 当遍历到根节点时，将二叉搜索树分为3个部分：根节点，左子树，右子树。
     * 根绝有序循环链表的定义，根节点将链接在左子树中值最大的节点后，同时在右子树值最小的节点前。
     * 按照中序遍历的顺序，当遍历转换到根节点时，它的左子树已经转换为一个有序的双向链表了，
     * 并且处在链表中最后一个节点是当前值最大的节点。当将根节点链接在该节点后，根节点成为最大节点。
     * 接着遍历转换右子树的节点，最后将根节点作为右子树中值最小的节点的前驱。
     * */
### 代码

```cpp
BiTreeNode *treeToDoublyList(BiTreeNode *root) {
    if (root == nullptr) {
        return root;
    }

    // 已排序链表的最后一个节点
    BiTreeNode *lastNodeInList = nullptr;

    // 对二叉搜索树进行有序双向链表的转化
    convertNode(root, &lastNodeInList);

    // 将有序双向链表的的最后一个节点赋值为链表的头节点
    BiTreeNode *headOfList = lastNodeInList;

    // 对有序双向链表向前遍历到链表的头部
    while (headOfList != nullptr && headOfList->left != nullptr) {
        headOfList = headOfList->left;
    }

    // 此时有序双向链表还不是循环的，
    // 所以需要将该链表的头节点的前驱指向链表尾节点，
    // 将链表的尾节点的后继指向链表的头节点构成循环双向链表
    lastNodeInList->right = headOfList;
    headOfList->left = lastNodeInList;

    return headOfList;
}

void convertNode(BiTreeNode *node, BiTreeNode **lastNodeInList) {
    if (node == nullptr) {
        return;
    }

    // 遍历的当前节点
    BiTreeNode *curNode = node;

    // 如果当前节点不为左叶节点，就递归遍历到最左叶节点
    if (curNode->left != nullptr) {
        convertNode(curNode->left, lastNodeInList);
    }

    // 将当前节点添加到有序双向链表中

    // 当前节点的左指针指向已排序的双向链表的最后一个节点,
    // 即当前节点的前驱是已排序的双向链表的最后一个节点
    curNode->left = *lastNodeInList;

    // 已排序的双向链表的最后一个节点的右指针指向当前节点，
    // 即已排序的双向链表的最后一个节点的后继是当前节点
    if (*lastNodeInList != nullptr) {
        (*lastNodeInList)->right = curNode;
    }

    // 更新有序双向链表的最后一个节点为当前节点
    *lastNodeInList = curNode;

    // 继续对当前节点的右子树进行递归遍历
    if (curNode->right != nullptr) {
        convertNode(curNode->right, lastNodeInList);
    }
}

```