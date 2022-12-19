## 思路一：递归
中序遍历，然后递减k值，直到k为0时终止，则找到的元素就是第k小元素。
1. 首先遍历左子树，如果找到k值为0，则返回找到的元素；
2. 否则，对于当前节点，递减k值，如果k值为0，则返回当前节点；
3. 否则，遍历右子树。
## 代码
```c++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
    int find(TreeNode *root, int &k) {
        if (root) {
            int x = find(root->left, k);      
            if (k == 0) {
                return x;
            }
            --k;
            return k == 0 ? root->val : find(root->right, k);            
        }        
        return -1;
    }
};
```

## 思路二：非递归
## 代码
```c++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if (--k == 0) {
                return p->val;                
            }
            st.pop();
            p = p->right;
        }
        return -1;
    }
};
```
