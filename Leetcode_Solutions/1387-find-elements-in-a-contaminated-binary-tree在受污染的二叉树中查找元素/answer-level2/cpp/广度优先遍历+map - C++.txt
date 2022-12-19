![4b460ab93072b595be330800cbbe90c.png](https://pic.leetcode-cn.com/8a14cb1e307fbb79ec4e62dd339d9b188dd6b109dd44795f1aa9d01826e31dee-4b460ab93072b595be330800cbbe90c.png)

广度优先遍历可以直接在构造函数里完成每个节点的赋值，然后将节点的值存进map里，后续的查找就可以达到O(1)，而不需要重新遍历树。
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    map<int,int> mp;
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            mp[t->val]++;
            if(t->left)
            {
                t->left->val = t->val*2+1;
                q.push(t->left);
            }
            if(t->right)
            {
                t->right->val = t->val*2+2;
                q.push(t->right);
            }
        }
    }
    
    bool find(int target) {
        if(mp[target]) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```
