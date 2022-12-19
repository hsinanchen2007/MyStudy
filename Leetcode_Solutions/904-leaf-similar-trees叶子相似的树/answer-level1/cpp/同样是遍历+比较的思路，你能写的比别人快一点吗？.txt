看到题目后，很直观的思路是遍历每棵树的所有节点，遇到叶子节点后予以记录，后续可以比较两棵树的叶子节点序列，返回结果。

而到具体的实现上，还是能写出不同效率的代码。考虑这几点：
- 使用迭代而非递归做二叉树的遍历，能熟练写出吗？
- 两棵树的所有节点都需要遍历吗？
- 是否必须用STL(C++)的容器？

实际上，遍历完第一棵树后，叶子节点存储到数组中，则第二棵树可以在遍历的同时做比较(on-the-fly)，则一旦遇到不同值的叶子节点，或拥有更多叶子节点，即可结束函数。

题目中提到每棵树最多200个节点，因此每棵树最多有不超过100个叶子节点，此时可用数组提到vector存储叶子节点的值。

既然最多有200个叶子节点，那么树的高度，也就是DFS的栈的深度，最多不超过100个，因此可以用数组模拟栈，替代deque或stack这样的STL容器。


执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.8 MB
, 在所有 C 提交中击败了
100.00%
的用户

实现如下：
```cpp
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaf[100];
    memset(leaf, 0, sizeof(leaf));
    int leaf_idx = 0;

    struct TreeNode* q[100];
    q[0] = root1;
    int q_len = 1;
    struct TreeNode* cur = NULL;
    while (q_len > 0) {
        cur = q[--q_len];
        if (cur == NULL) continue;
        if (cur->left == NULL && cur->right == NULL) {
            leaf[leaf_idx] = cur->val;
            leaf_idx++;
        }
        q[q_len++] = cur->left;
        q[q_len++] = cur->right;
    }

    int leaf_cnt = leaf_idx;
    leaf_idx = 0;

    q[0] = root2;
    q_len = 1;
    while (q_len > 0) {
        cur = q[--q_len];
        if (cur == NULL) continue;
        if (cur->left == NULL && cur->right == NULL) {
            if (leaf_idx >= leaf_cnt || cur->val != leaf[leaf_idx]) {
                return false;
            }
            leaf_idx++;
        }
        q[q_len++] = cur->left;
        q[q_len++] = cur->right;
    }

    return true;
}
```