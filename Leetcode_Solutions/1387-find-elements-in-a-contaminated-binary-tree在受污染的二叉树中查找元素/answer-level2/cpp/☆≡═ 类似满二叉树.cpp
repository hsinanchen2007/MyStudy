1. 给本题里未受污染的二叉树节点值加一，它的值就类似于满二叉树节点间的关系。

         0                  1
        1 2     会变为      2 3
       3 4                4 5
2. 每个节点的值为 x, 左孩子值为 2x，右孩子值为 2x + 1。
3. 深度优先遍历二叉树，填入对应的值。
4. 并把值存入哈希表中，查询时直接返回。
```c++
class FindElements {
public:
    FindElements(TreeNode* root) {
        if (root) dfs(root, 1);
    }
    
    bool find(const int target) {
        return s.count(target);
    }
    
private:
    unordered_set<int> s;
    void dfs(TreeNode* root, const int val) {
        root->val = val - 1;
        s.insert(root->val);
        if (root->left) dfs(root->left, 2 * val);
        if (root->right) dfs(root->right, 2 * val + 1);
    }
};
```
