## 解法

该问题很经典，同时解法也很简单。要点是要抓住前序遍历序列和中序遍历序列的特点。前序遍历序列中的第一个元素是二叉树的根节点的值；中序遍历序列中，根节点左侧的值是左子树的中序遍历序列，右侧的值是右子树的中序遍历序列。

那么解法就很简单了：

* **找出根节点元素在中序遍历序列中的位置**：首先取出前序遍历序列中的第一个元素，在中序遍历序列中进行遍历对比，找到该元素在中序遍历序列中的下标；
* **构建左右子树的中序遍历序列**：该下标左侧的元素都是左子树的中序遍历序列，右侧的元素都是右子树的中序遍历序列；
* **构建左右子树的前序遍历序列**：计算左侧元素的数目$m$，则在前序遍历序列中，从首元素的下一个元素开始的$m$个元素构成左子树的前序遍历序列，$m$个元素之后的元素构成右子树的前序遍历序列；
* **递归**：依据生成的左右子树的前序序列和中序序列，递归调用上述过程；
* **递归终止条件**：当序列中剩余一个元素时，将该元素作为单独的节点返回即可。

要注意的一点是：在递归构建左右子树之前，要保证左右子树的序列中存在元素。

代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return buildTreeCore(preorder, inorder);
    }
    
    TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 1 && inorder.size() == 1)
            return new TreeNode(preorder[0]);
        TreeNode* root = new TreeNode(preorder[0]);  // 前序遍历序列的第一个元素为二叉树的根节点的值
        // 找到根节点在中序遍历序列中的位置
        int index;
        for (index = 0; index < inorder.size(); index++){
            if (inorder[index] == preorder[0])
                break;
        }
        // 左子树的前序和中序遍历序列
        if (index != 0){
            vector<int> left_tree_preorder(preorder.begin() + 1, preorder.begin() + 1 + index);
            vector<int> left_tree_inorder(inorder.begin(), inorder.begin() + index);
            root->left = buildTreeCore(left_tree_preorder, left_tree_inorder);
        }
        // 右子树的前序和中序遍历序列
        if (index != preorder.size() - 1){
            vector<int> right_tree_preorder(preorder.begin() + 1 + index, preorder.end());
            vector<int> right_tree_inorder(inorder.begin() + index + 1, inorder.end());
            root->right = buildTreeCore(right_tree_preorder, right_tree_inorder);
        }
        
        return root;
    }
};
```

为了使得代码流程较为清晰，编码过程中构造了很多`vector`的临时对象，这些操作是比较耗时和耗费空间资源的。可以转换为传入下标来进行改进。

时间复杂度：$O(n)$；

空间复杂度：$O(n)$，存储整棵树。