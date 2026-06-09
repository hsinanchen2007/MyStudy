
递归+后续遍历：
```
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        //后续遍历
        dfs(root, res);
        return res[k-1];
    }
    void dfs(TreeNode* root, vector<int> &res){
        if(!root) return;
        dfs(root->right, res);
        res.push_back(root->val);
        dfs(root->left, res);
    }
};
```
迭代法：
```
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode *> myStack;
        int cnt = 0;
        TreeNode *Node = root;
        while(!myStack.empty()||Node){
            while(Node){
                myStack.push(Node);
                Node = Node->right;
            }
            Node = myStack.top();
            myStack.pop();
            cnt++;
            if(cnt==k) return Node->val;
            Node = Node->left;
        }
        return NULL;
    }
};
```
