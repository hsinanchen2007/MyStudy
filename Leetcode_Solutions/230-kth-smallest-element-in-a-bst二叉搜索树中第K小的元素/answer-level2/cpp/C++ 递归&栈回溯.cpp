### 解题思路
二叉搜索树的中序遍历就是元素的升序排列，所以这个问题可以转换为中序遍历，获取第K个节点的数据值。

为了优化代码的性能，可以记录当前访问节点的数目，当等于K的时候，提前将该节点的数据值返回即可。

### 代码

### 辅助栈迭代代码
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> s;
        // 中序遍历
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                // 返回第k个最小的元素
                if(++count == k){
                    return root->val;
                }
                root = root->right;
            }
        }
        return 0;
    }
};
```

### 递归代码
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorderTraversal(root);
        return ret;
    }

private:
    void inorderTraversal(TreeNode* & root){
        if(root && !isFind){
            inorderTraversal(root->left);
            if(++count == k){
                // 记录第k个最小的元素，并将isFind置为true
                ret = root->val;
                isFind = true;
                return;
            }
            inorderTraversal(root->right);
        }
    }
private:
    int count = 0;
    int k = 0;
    int ret = -1;
    bool isFind = false;
};









```