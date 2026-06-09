先明白二叉树前序遍历的概念：前序遍历首先访问**根节点**，然后遍历**左子树**，最后遍历**右子树**。
以下各个方法细讲
## 方法一： 递归法
```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL){
            ans.push_back(root -> val);
            preorderTraversal(root -> left);
            preorderTraversal(root -> right);
        }
        return ans;
    }
};
```
- 因为先访问根节点，所以直接将`root`的`val`放入答案（ans）容器内。
- 然后遍历左子树，现在以`root`的左子树为`root`进入递归。

## 方法二： 迭代法（使用stack
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* temp = root;
        while(temp != NULL || !stk.empty()){
            while(temp != NULL) {
                ans.push_back(temp -> val);
                stk.push(temp);
                temp = temp -> left;

            }
            temp = stk.top();
            stk.pop();
            temp = temp -> right;
        }
        return ans;
    }
};
```
- 想法跟上一种方法差不多，差别在于使用`stack`来储存`root`。
- 当左子树遍历完后，取出`root`接着遍历右子树。