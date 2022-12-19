这题是二叉搜索树删除稍作改动，不用考虑左右子树都存在的情况，思路如下：
1. 节点值在区间内，递归左右子树
2. 节点值小于区间下限，左子树直接删掉，右子树赋值给根节点，此时根节点可能还是不在区间内，再递归
3. 节点值大于区间上限，同上
上代码：
```
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return nullptr;
        if (root->val <=R && root->val>=L)//在区间内
        {
            root->left=trimBST(root->left,L,R);
            root->right=trimBST(root->right,L,R);
        }
        else//不在区间内
        {
            if (root->val<L)//根节点小于下限
            {
                if (root->right ||root->left)
                {
                    root->left=NULL;
                    root=root->right;
                    if (root)
                        root=trimBST(root,L,R);//注意这里，首先root不能是NULL，编译不过，其次赋值完节点值可能还是不在区间内，再次递归。
                }
                else
                    root=nullptr;
            }
            else if (root->val>R)//根节点大于上限
            {
                if (root->right ||root->left)
                {
                    root->right=NULL;
                    root=root->left;
                    if (root)
                        root=trimBST(root,L,R);
                }
                else
                    root=nullptr;
            }
        }
        return root;//最后从这里结束，返回根节点
    }
};
```

