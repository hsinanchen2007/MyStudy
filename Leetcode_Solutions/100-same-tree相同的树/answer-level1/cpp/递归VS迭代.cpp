# ***递归VS迭代***

**话不多说，直接上代码！**
1. **递归**
```
class Solution {
            public:
            bool isSameTree(TreeNode* p, TreeNode* q) {
                if(p == NULL && q == NULL) return true;
                else if(p == NULL || q == NULL) return false;
                return (p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
            }
};
```
**提交通过！**
                         
![QQ图片20191213012908.png](https://pic.leetcode-cn.com/c665e3ed8306f90eaff8f1b3c51fde15e97302ac74c983dc6259c3d6ed688c16-QQ%E5%9B%BE%E7%89%8720191213012908.png)

2.**迭代** 
迭代需要借助辅助工具，这里用stack
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q== NULL) return false;
        stack<TreeNode *>st;
        TreeNode *tem1;
        TreeNode *tem2;
        st.push(p);
        st.push(q);
        while(!st.empty())
        {
            tem1 = st.top();
            st.pop();
            tem2 = st.top();
            st.pop();
            if(tem1 == NULL && tem2 == NULL) continue;
            if(tem1 == NULL || tem2 == NULL) return false;
            if(tem1->val != tem2->val) return false;
            st.push(tem1->left);
            st.push(tem2->left);
            st.push(tem1->right);
            st.push(tem2->right);
        }
        return true;
    }
};
```
**提交通过！**
![QQ图片20191213012935.png](https://pic.leetcode-cn.com/c2dece1ad70583563fb6cb7b015ca9fdc253215ed7224e93f2cc2dba13d9b147-QQ%E5%9B%BE%E7%89%8720191213012935.png)

