
递归解法：
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
    int res;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return res;
        if(root->val >= L && root->val <= R) res += root->val;
        rangeSumBST(root->left, L, R);
        rangeSumBST(root->right, L, R);
        return res;
    }
};
```

BFS 层序遍历
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0, curLen = 0;
        if(!root) return res;
        queue<TreeNode *> myQue;
        myQue.push(root);
        while(!myQue.empty()){
            curLen = myQue.size();
            while(curLen--){
                TreeNode *Node = myQue.front();
                myQue.pop();
                if(L <= Node->val && Node->val <= R) res += Node->val;
                if(Node->left != NULL) myQue.push(Node->left);
                if(Node->right != NULL) myQue.push(Node->right);
            }
        }
        return res;
    }
};
```

考虑二叉搜索树独特性质，左子树一定小于右子树
当L >= 当前节点值，此时没有必要再遍历左子树，也即遍历左子树前，限定 L < 当前节点值;
当R <= 当前节点值，此时没有必要再遍历右子树，也即遍历右子树前，限定 当前节点值 < R;

因此递归解法可更新为：
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
    int res;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return res;
        if(root->val >= L && root->val <= R) res += root->val;
        // 如下两行做了递归优化
        if(L < root->val) rangeSumBST(root->left, L, R);
        if(R > root->val) rangeSumBST(root->right, L, R);
        return res;
    }
};
```

BFS层次遍历解法可更新为：
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0, curLen = 0;
        if(!root) return res;
        queue<TreeNode *> myQue;
        myQue.push(root);
        while(!myQue.empty()){
            curLen = myQue.size();
            while(curLen--){
                TreeNode *Node = myQue.front();
                myQue.pop();
                if(L <= Node->val && Node->val <= R) res += Node->val;
                // 如下两行做了优化
                if(Node->left != NULL && L < Node->val) myQue.push(Node->left);
                if(Node->right != NULL && R > Node->val) myQue.push(Node->right);
            }
        }
        return res;
    }
};
```
