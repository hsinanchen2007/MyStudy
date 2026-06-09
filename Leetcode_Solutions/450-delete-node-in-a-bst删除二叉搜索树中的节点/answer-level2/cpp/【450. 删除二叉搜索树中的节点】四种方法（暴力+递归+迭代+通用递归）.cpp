## 思路一：暴力法
比较复杂（可以略过），自己对着测试案例一次次修改的...后面几种思路参考大佬[grandyang](https://www.cnblogs.com/grandyang/p/6228252.html)的。
### 代码
```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;        
        TreeNode *pre = new TreeNode(0);
        pre->left = root;
        while (root) {
            if (root->val == key) {
                if (!root->left && root->right) {//左空 右不空
                    if (pre->left == root) {
                        if (dummy->left == root) dummy->left = root->right;
                        pre->left = root->right;
                    } else if (pre->right = root) {
                        pre->right = root->right;
                    }
                    break;
                } else if (!root->right && root->left) {//右空 左不空
                    if (pre->left == root) {
                        if (dummy->left == root) dummy->left = root->left;
                        pre->left = root->left;
                    } else if (pre->right == root) {
                        pre->right = root->left;
                    }
                    break;
                } else if (!root->left && !root->right) {//左右都空
                     if (pre->left == root) {
                         if (dummy->left == root) dummy->left = nullptr;
                        pre->left = nullptr;
                        root = nullptr;
                        delete root;
                    } else if (pre->right == root) {
                        pre->right = nullptr;
                    }
                    break;
                } else {//左右都不空
                    TreeNode *p = root->right;
                    TreeNode *prep = nullptr;
                    TreeNode *left = root->left;
                    TreeNode *right = root->right;
                    while (p->left) {
                        prep = p;
                        p = p->left;
                    }
                    TreeNode *ppright = p->right;
                    if (pre->left == root) {
                        if (dummy->left == root) dummy->left = p;
                        pre->left = p;
                    } else if (pre->right == root) {
                        pre->right = p;
                    }
                    p->left = left;                    
                    //p->right = root->right;
                    if (prep) {
                        prep->left = ppright;                    
                        p->right = right;
                    } 
                    break;
                }                
            } else if (root->val > key) {
                pre = root;
                root = root->left;
            } else if (root->val < key) {
                pre = root;
                root = root->right;
            }
        }
        return dummy->left;
    }
};
```

## 思路二：递归（击败99.52%）
### 代码
```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->right || !root->left) {
                root = root->left ? root->left : root->right;
            } else {
                TreeNode *cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                root->val = cur->val;//值替换，很巧妙
                root->right = deleteNode(root->right, cur->val);
            }
        }
        return root;
    }
};
```

## 思路三：迭代
### 代码
```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode *cur = root, *pre =  nullptr;
        //1. 寻找值相等节点，找到就退出
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        //2. 判断删除节点位置，然后删除节点
        if (!pre) return del(cur);
        if (pre->left && pre->left->val == key) pre->left = del(cur);
        else pre->right = del(cur);
        return root;
    }
    //删除节点为头节点
    TreeNode* del(TreeNode *node) {
        if (!node) return node;
        if (!node->right) return node->left;
        //在当前节点右子树中寻找最小节点，即最左节点
        TreeNode *t = node->right;
        while (t->left) {
            t = t->left;
        }
        t->left = node->left;//将删除节点左子树挂到最小节点的左侧
        return node->right;
    }
};
```

## 思路四：通用递归
没有利用BST性质，遍历所有节点，删除与key相同节点。
### 代码
```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->right) {
                return root->left;
            }
            TreeNode *cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
```


