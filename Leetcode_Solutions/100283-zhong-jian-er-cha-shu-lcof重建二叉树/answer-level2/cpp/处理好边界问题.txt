### 解题思路
根据**前序遍历数组的第一个值**找到在中序遍历中的坐标，那么中序遍历数组中这个坐标之前（左边）的节点都是左子树上的节点，右边的则是右子树上的节点，然后递归求解即可。

### 代码

```cpp
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> map;
        for (int i = 0; i < inorder.size(); ++i) {
            map.insert({inorder[i],i});
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, map);
        return root;
    }

    //建树过程
    //必须引用传参，否则超出内存限制
    TreeNode* buildTree(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int  inorderEnd, map<int, int>& map) {
        //递归出口，前序遍历中开始大于结束
        if (preorderStart > preorderEnd) return nullptr;

        int rootVal = preorder[preorderStart];
        TreeNode* root = new TreeNode(rootVal);
        //左右相等时，表明找到了每颗子树的根节点
        if (preorderStart == preorderEnd) {
            return root;
        }//否则
        //找到了根节点，在中序遍历数组中找到对应的坐标，然后分别计算出左子树和右子树的数量
        int rootIndex = map[rootVal];
        int leftNodes = rootIndex - inorderStart, rightNodes = inorderEnd - rootIndex;

        TreeNode* leftTree = buildTree(preorder, preorderStart+1, preorderStart+leftNodes, inorder, inorderStart, rootIndex-1, map);
        TreeNode* rightTree = buildTree(preorder, preorderEnd-rightNodes+1, preorderEnd, inorder,rootIndex+1, inorderEnd, map);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
};
```