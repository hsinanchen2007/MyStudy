# 1. 理解
根据前序遍历和中序重建二叉树，关键是找到中序节点，左树部分和有书部分，然后递归的重建二叉树。
# 2. 思路
1. 使用map保存序列在中序遍历中的位置
2. 第一个元素一定是中间节点，创建作为子树的根节点，如果先序序列长度为0，则该子树重建完毕
3. 通过在中序遍历中的位置，找到左子树节点范围，递归重构左子树，
4. 先序遍历序列剩下的部分为右子树，递归重构右子树
# 3. 代码
```c++ []
class Solution {
public:
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        for(int i=0; i<inorder.size(); i++){
            index[inorder[i]] = i;
        }
        TreeNode* tree = nullptr;
        
        return build_tree(tree, 0, inorder.size());
    }

    TreeNode* build_tree(TreeNode* &root, int l, int h){
        if(l >= h) return nullptr;
        root = new TreeNode(preorder[l]);
        if(l+1 == h) return root;
        int i;
        for(i=l+1; i<h&&index[preorder[i]] < index[preorder[l]]; i++);
        root->left = build_tree(root->left, l+1, i);
        root->right = build_tree(root->right, i, h);
        return root;
    }
};
```
# 4. 总结
这道题想了很久，主要时间花在理清递归思路上，另外这道题虽然AC了，但是效率不高，我感觉在确定下一个左子树范围的地方有待优化，也就是下面这个循环：
```c++ []
for(i=l+1; i<h&&index[preorder[i]] < index[preorder[l]]; i++);
```
