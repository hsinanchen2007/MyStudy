### 当然，一开始我们先回顾以下中序遍历的概念：中序遍历是先遍历左子树，然后访问根节点，然后遍历右子树。（如果还不清楚，可以看这个 [链接](https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/2/traverse-a-tree/7/) 是力扣关于中序遍历的动态总结）
### 方法一： 递归法
```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL) {
            inorderTraversal(root -> left);
            ans.push_back(root -> val);
            inorderTraversal(root -> right);
        }
        return ans;
    }
};
```
- 递归法，先左子树，后root，最后；右子树。
### 方法二： 迭代法
```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* temp = root;
        while(temp || !stk.empty()){
            while(temp){
                stk.push(temp);
                temp = temp -> left;
            }
            temp = stk.top();
            stk.pop();
            ans.push_back(temp -> val);
            temp = temp -> right;
        }
        return ans;
    }
};
```
- 个人认为难点在于找到哪里到哪里为一个循环
- 首先，我们知道从root开始。然后遍历左子树，直到NULL。然后指向最后一个root的右子树。从这里进入循环，以新的点为root。