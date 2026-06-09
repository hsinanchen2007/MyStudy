### 解题思路

**递归**
递归的思路很简单，先遍历左子树，接着对根节点数据压入序列vector中，再遍历右子树

**迭代**
使用栈先进后出的特点进行回溯：
+ 对根节点的左孩子不断压栈，直到左孩子为空；
+ 然后弹出栈顶元素，将该节点的数据压入序列vector中；
+ 再将该节点的右孩子压入栈（为空则不必），则此时的右孩子可看作一开始的根节点


### 递归代码

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorderTraversal(root,vec);
        return vec;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& vec){
        if(root){
            inorderTraversal(root->left,vec);
            vec.push_back(root->val);
            inorderTraversal(root->right,vec);
        }
    }
};
```

### 辅助栈迭代代码
```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(!root){
            return vec;
        }
        stack<TreeNode*> s;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                vec.push_back(root->val);
                root = root->right;
            }
        }
        return vec;
    }
};



```