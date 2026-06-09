```
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
    //vector的find函数
    //输入(向量，和要找的值)，返回值对应的指针
    vector<int>::iterator find(vector<int> &v1, int num) {
        vector<int>::iterator it;
        for (it = v1.begin(); it != v1.end(); it++) {
            if (*it == num) {
                break;
            }
        }
        return it;
        //return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归方式
        //建立一棵树，新建一个根节点，并赋值，
        //建立左子树，返回左子树根节点指针
        //建立右子树，返回右子树根节点指针
        //递归入参，应当能够确定 1) 这棵树的前序遍历向量 2) 这棵树的中序遍历向量
        TreeNode* root;
        root = buildchildtree(preorder, inorder);
        return root;


        
    }
    TreeNode * buildchildtree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) {
            return NULL;
        }
        vector<int>::iterator root_position;
        root_position = find(inorder, preorder[0]);//返回中序遍历中根节点的指针，这个指针是左子树的结尾，加1是右子树的开始
        //建立根节点
        TreeNode *root = new TreeNode(preorder[0]);
        //建立左子树
        vector<int> left_preorder;
        vector<int> left_inorder;
        vector<int> right_preorder;
        vector<int> right_inorder;
        //先建立左子树的中序遍历序列
        for(vector<int>::iterator it = inorder.begin(); it != root_position; it++) {
            left_inorder.push_back(*it);
        }
        //根据左子树的中序遍历序列的size,建立前序遍历的内容
        //左子树的大小
        int left_size = left_inorder.size();
        for(vector<int>::iterator it = preorder.begin() + 1; it != preorder.begin() + 1 + left_size; it++) {
            left_preorder.push_back(*it);
        }
        root->left = buildchildtree(left_preorder, left_inorder);
        //建立右子树
        //建立左子树的同时是否能够同时建立右子树
        for(vector<int>::iterator it = root_position + 1; it != inorder.end(); it++) {
            right_inorder.push_back(*it);
        }
        for(vector<int>::iterator it = preorder.begin() + 1 + left_size; it != preorder.end(); it++) {
            right_preorder.push_back(*it);
        }
        root->right = buildchildtree(right_preorder, right_inorder);
        //返回根节点的指针
        return root;

    }
};
```
