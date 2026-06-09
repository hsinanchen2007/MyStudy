### 解题思路
把二叉搜索树转换为累加树，和1038 从二叉搜索树到更大和树是一个题目，只是1038是在辅助函数的参数中添加了一个引用（因此当在递归到一个子树下面时，x的改变也影响上面）

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
    int x=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        return DFS(root);
    }
    TreeNode * DFS(TreeNode *root ){//按框架来就是根右左的中序遍历， 然后想象应该在右左递归之间该做什么。
        if(root==NULL) return root;
        DFS(root->right);
        x+=root->val;
        root->val=x;
        DFS(root->left);
        return root;
    }
};

```cpp
//1038题目代码
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {  //右边的比左边的都大
        if(root==nullptr) return root;
        int key=0;
        DFS(root,key);
        return root;
    }
    void DFS(TreeNode *root,int &key){  //注意这里的使用。。
        if(root==nullptr) return ;
        DFS(root->right,key);
        key=key+root->val;
        root->val=key;
        DFS(root->left,key);
    }
};