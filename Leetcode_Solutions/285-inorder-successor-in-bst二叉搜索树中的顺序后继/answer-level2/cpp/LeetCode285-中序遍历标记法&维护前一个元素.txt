## 标记法
### 解题思路
* 直接套中序遍历的模板，设置一个全局的flag = false。（表示是否开启查找下一个元素的开关）
* 若找到元素p，使得flag = true，即打开查找下一个元素的开关。
* 把找到的元素返回


### 递归代码

```cpp
class Solution {
public:
    bool flag = false;
    TreeNode *ret = nullptr;
    
    void dfs(TreeNode* root, TreeNode* p) {
        if (!root || ret) return;
        dfs(root->left, p);
        
        // 中序遍历过程
        if (flag) {
            ret = root;  // 找到了答案
            flag = false;  // 关闭开关
        }
        if (root == p) flag = true;  // 打开开关
        
        dfs(root->right, p);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return ret;
    }
};
```

### 迭代代码

```cpp
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *it = root;
        stack<TreeNode*> stk;
        bool flag = false;
        while (it || !stk.empty()) {
            while (it) {
                stk.push(it);
                it = it->left;
            }
            it = stk.top(); stk.pop();
            
            // 中序遍历过程
            if (flag) return it;   // 打开开关的下一个元素就是答案，直接返回
            else if (it == p) flag = true;  // 遇到p就打开开关
            
            it = it->right;
        }
        return nullptr;
    }
};
```

## 维护前一个元素
### 解题思路
* 在中序遍历的时候维护一个一个prev指针，指向的是当前元素的上一个元素
* 若上一个元素为p的时候，说明当前元素就是p的后继
* 直接返回当前元素即可

### 递归代码

```cpp
class Solution {
public:
    TreeNode *ret = nullptr;
    TreeNode *prev = nullptr;
    
    void dfs(TreeNode* root, TreeNode* p) {
        if (!root || ret) return;  
        dfs(root->left, p);
        
        // 中序遍历访问过程
        if (prev == p) ret = root;
        prev = root;
        
        dfs(root->right, p);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return ret;
    }
};
```

### 迭代代码

```cpp
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *prev = nullptr;
        TreeNode *it = root;
        stack<TreeNode*> stk;
        while (it || !stk.empty()) {
            while (it) {
                stk.push(it);
                it = it->left;
            }
            it = stk.top(); stk.pop();
            
            // 中序遍历访问过程
            if (prev == p) return it;
            prev = it;
            
            it = it->right;
        }
        return nullptr;
    }
};
```