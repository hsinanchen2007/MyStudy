### 解题思路
使用中序遍历，在根结点处，先更新curtime，再与maxtime进行比较。
注意pre指针在声明处需要使用引用。如果不加引用，pre在递归深层修改的值不会回传到递归的上一层的，会影响结果。

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* pre = nullptr;
        int curTime = 1, maxTime = 0;
        inOrder(root, pre, curTime, maxTime, res);
        return res;
    }
private:
    void inOrder(TreeNode* root, TreeNode*& pre, int& curTime, int& maxTime, vector<int>& res){
        if(!root) return;
        inOrder(root->left, pre, curTime, maxTime, res);


        if(pre)
            curTime = (root->val == pre->val)? curTime+1:1;
        if(curTime==maxTime)
            res.push_back(root->val);
        else if(curTime > maxTime){
            res.clear();
            res.push_back(root->val);
            maxTime  = curTime;
        }
        pre = root;
        inOrder(root->right, pre, curTime, maxTime, res);
    }
};
```