### 解题思路
用两个队列分别存储父亲层与儿子层的队列，同时每一次将父亲层的值存入到vector<int>中，同时将这个值存入需要返回的容器中，从root层不断更迭，直到最底层（父亲队列为空）;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levellist;
        vector<int>* tmp;
        queue<TreeNode*>* parentqueue = new queue<TreeNode*>;
        queue<TreeNode*>* childqueue = new queue<TreeNode*>;
        queue<TreeNode*>* swap;
        parentqueue->push(root);
        TreeNode* tree;
        if(root==NULL) return levellist;
        while(!parentqueue->empty())
        {
            tmp = new vector<int>;
            while(!parentqueue->empty())
            {
                tree = parentqueue->front();
                parentqueue->pop();
                tmp->push_back(tree->val);
                if(tree->left) childqueue->push(tree->left);
                if(tree->right) childqueue->push(tree->right);
            }
            swap = parentqueue;
            parentqueue = childqueue;
            childqueue = swap;
            levellist.push_back(*tmp); 
        }
        return levellist;
    }
};
```