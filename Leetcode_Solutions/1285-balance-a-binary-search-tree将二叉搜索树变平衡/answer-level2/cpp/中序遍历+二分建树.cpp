注意题目规定是“二叉搜索树”，这就限定了对于任何子树：左边的值 < 根的值 < 右边的值！为了保证这个顺序，我们需要使用中序遍历的次序来收集所有树上的值。然后利用二分的方法，递归构建树：取中间的那个值为根，左边一半用来用来递归构建左子树，右边一半用来用来递归构建右子树。复杂度是 $O(n)$。

当然如果不想中序遍历，就先按照任意顺序收集完所有值后，做一次排序，再来进行二分法建树。这样的复杂度是 $O(n \log n)$。

然而，在本题数据下，两种方法只有几毫秒的差别！

```c++
class Solution {
    void collect(TreeNode* root, vector<int>& v) {
        if (root->left) collect(root->left, v);
        v.push_back(root->val);
        if (root->right) collect(root->right, v);
    }
    
    TreeNode* build(const vector<int>& v, int lo, int hi) {        
        if (lo < hi) {
            int mid = (lo + hi) / 2;
            auto tree = new TreeNode(v[mid]);
            tree->left = build(v, lo, mid - 1);
            tree->right = build(v, mid + 1, hi);
            return tree;
        }
        
        if (lo > hi) {
            return NULL;
        }
        
        return new TreeNode(v[lo]);
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        collect(root, v);
        return build(v, 0, v.size() - 1);
    }
};
```