### 解题思路
突然发现只要是用层序遍历就可以用队列来存储每一层的数据。
两种方法。

第一用队列，判断是否到达本层的最右节点。

第二递归，主要是添加一个level变量判断本层是否添加了数据。因为是从右边看，所以迭代的时候先迭代右子树。


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
    // 执行用时 :4 ms, 在所有 C++ 提交中击败了83.15% 的用户
    // 内存消耗 :12 MB, 在所有 C++ 提交中击败了5.31%的用户
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        queue<TreeNode*> q;
        // rightSideViewCore(root, res);
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 1;i<=n;++i){
                TreeNode* temp = q.front();
                q.pop();
                if(i==n){
                    res.push_back(temp->val);
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return res;
    }

    // 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗 :11.8 MB, 在所有 C++ 提交中击败了5.31%的用户
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        rightSideViewCore(root, res, 1);
        return res;
    }
    void rightSideViewCore(TreeNode* root, vector<int>& res, int level){
        if(!root->left&&!root->right){
            if(level>res.size()) res.push_back(root->val);
            return;
        }

        if(level>res.size()){//若当前这一层没有存数据，就存。
            res.push_back(root->val);
        }
        if(root->right) rightSideViewCore(root->right, res, level+1);//先从右边开始递归。
        if(root->left) rightSideViewCore(root->left, res, level+1);

    }

};
```