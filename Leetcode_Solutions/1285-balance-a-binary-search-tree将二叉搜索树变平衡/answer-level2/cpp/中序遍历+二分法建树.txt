### 解题思路
双百击败用户，感觉还可以。
因为题目给的是一个二叉排序树，顾中序遍历的结果是有序的，所以只需要中序遍历+二分法建树即可。
（经测试，如果遍历的时候只保存值，建树的时候重新建立节点，会超时）

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
    vector<TreeNode*> IO;
    TreeNode* balanceBST(TreeNode* root) {
        //中序输出这棵树，然后采用2分法建树
        if (root==NULL) return root;
        if (root->left == NULL && root->right == NULL) return root;
        InOrder(root);//中序遍历，注意保存的是节点
        TreeNode* Root=Create(0, IO.size()-1);//2分法建树
        return Root;
    }
    void InOrder(TreeNode* root){
        if (root==NULL) return;
        InOrder(root->left);
        IO.push_back(root);
        InOrder(root->right);
        return;
    }

    TreeNode* Create(int left, int right){
        if (left>right) return NULL;
        IO[(left+right)/2]->left=Create(left, (left+right)/2-1);
        IO[(left+right)/2]->right=Create((left+right)/2+1, right);
        return IO[(left+right)/2];
    }
};
```