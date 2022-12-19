### 思路
利用`TreeNode** pnode`，也就是指向数指针的指针
可以简化代码逻辑，避免对树根结点是否为空的判断，
按照**linus**的说法，这样做更符合 **good taste**

### 递归法
```cpp
class Solution1 {
public:
    void insert(TreeNode** pnode, int val) {
        if (*pnode == NULL) {
            *pnode = new TreeNode(val);
            return;
        }
        int t = (*pnode)->val;
        if (t < val) {
            insert(&(*pnode)->right, val);
        } else if (t > val) {
            insert(&(*pnode)->left, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(&root, val);
        return root;
    }
};
```

### 迭代法
```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** pnode = &root;
        while (*pnode != NULL) {
            int t = (*pnode)->val;
            if (t == val) return root;
            if (t < val) {
                pnode = &(*pnode)->right;
            } else {
                pnode = &(*pnode)->left;
            }
        }
        *pnode = new TreeNode(val);
        return root;
    }
};
```

![image.png](https://pic.leetcode-cn.com/7068cc46986c3c6eb1ba831f4ca68e0365509ccfe0144916bdbed9dd7c225ee8-image.png)
