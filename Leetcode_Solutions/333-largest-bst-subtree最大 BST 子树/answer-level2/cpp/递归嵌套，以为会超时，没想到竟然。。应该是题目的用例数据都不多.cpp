![image.png](https://pic.leetcode-cn.com/c3f35dc9a90c437f2c4dff46e5850bd02bea2dfb03c33b0cdcd74ec41bba5766-image.png)

从上至下，利用中序遍历判断每个子树是否为二叉搜索树
是则返回树的大小，不是则继续往下找
这里set的作用是防止树的节点有重复的值
```
class Solution {
public:
    void fun(TreeNode* root, vector<int> &vec)
    {
        if(root==NULL) return;
        fun(root->left, vec);
        vec.push_back(root->val);
        fun(root->right, vec);
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        vector<int> vec, sortVec;
        fun(root, vec);
        sortVec = vec;
        sort(sortVec.begin(), sortVec.end());
        set<int> s(sortVec.begin(),sortVec.end());
        if(vec == sortVec && s.size() == vec.size()) return vec.size();
        else return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
```

