### 解题思路一 递归法
    /*
     * 方法1 递归法
     *
     * 对称二叉树如下：
     *     1
     *    / \
     *   2   2
     *  / \ / \
     * 3  4 4  3
     *
     * 由观察可以发现，根节点的左节点2与根节点的右节点2要相等，
     * 同时根节点左子树的左节点3与根节点右子树的右节点3相等，
     * 同时根节点左子树的右节点4与根节点右子树的左节点4相等。
     *
     * 所以只需要递归判断此上三个条件即可。
     * */
### 代码

```cpp
bool isSymmetric(BiTreeNode *root) {
    // 传入根节点的左右子节点
    // 因为对称子树的根节点的左右子节点肯定相等，
    // 所以直接传入根节点的左右子节点更省时间
    return isMirror(root->left, root->right);
}

bool isMirror(BiTreeNode *root1, BiTreeNode *root2) {
    // 左右子树都为空时为对称子树
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    // 左右子树只有其一为空不为对称子树
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    // 当左节点的值等于右节点的值，
    // 同时递归比较左子树的left节点和右子树的right节点，
    // 同时递归比较左子树的right节点和右子树的left节点
    return root1->val == root2->val && isMirror(root1->left, root2->right)
           && isMirror(root2->right, root1->left);
}
```

### 解题思路二 迭代法
    /*
     * 方法2 迭代法
     *
     * 利用队列先进先出的特性模拟方法1的递归操作，
     * 将根节点的左右子节点push到队列中，
     * 然后pop出来比较它们的值是否相等，
     * 再按照左子树的左节点，右子树的右节点，
     * 左子树的右节点，右子树的左节点顺序push到队列中。
     * */
### 代码

```cpp
bool isSymmetric(BiTreeNode *root) {
    // 构造队列
    std::queue<BiTreeNode *> q;

    if (root == nullptr) {
        return true;
    }

    // 将根节点的左右子节点push到队列中
    // 因为对称子树的根节点的左右子节点肯定相等，
    // 所以直接push根节点的左右子节点更省时间
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        // 从队列中依次取出左右子节点
        BiTreeNode *node1 = q.front();
        q.pop();
        BiTreeNode *node2 = q.front();
        q.pop();

        if (node1 == nullptr && node2 == nullptr) {
            continue;
        }

        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        // 比较左节点的值右节点的值
        if (node1->val != node2->val) {
            return false;
        }

        // 按照左子树的左节点，右子树的右节点，
        // 左子树的右节点，右子树的左节点顺序push到队列中
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }

    return true;
}
```