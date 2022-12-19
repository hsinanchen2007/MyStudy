先根遍历, 需要标记父节点 , 当发生不同的时候, 依据Y的父节点进行交换, 交换完毕继续从两个父节点
开始的左子树的遍历, 交换完毕还是不能相等, 则为false, 否则一直遍历下去。

```
执行用时 : 4 ms, 在Flip Equivalent Binary Trees的C++提交中击败了98.03% 的用户
内存消耗 : 11.7 MB, 在Flip Equivalent Binary Trees的C++提交中击败了75.41% 的用户
```
```
class Solution 
{
public:
    bool ans;
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        ans = true;
        preorder(root1, NULL, root2, NULL, false);
        return ans;
    }
    
    void preorder(TreeNode *X, TreeNode *fx ,TreeNode *Y, TreeNode *fy, bool flip)
    {
        if(!ans) 
        {
            cout << "triger   " << boolalpha << ans << endl;
            ans = false;
            return;
        }
        if(!X && !Y) return;
        if(X && Y && X->val == Y->val)
        {
            preorder(X->left, X, Y->left, Y, false);
            preorder(X->right, X, Y->right, Y, false);
        }
        else
        {
            //当根节点不相同, 或者交换一次后仍然不相同的情况的时候
            if(!fx || !fy || flip)
            {
                ans = false;
                return;
            }
            swap(fy->left, fy->right);
            preorder(fx->left, fx, fy->left, fy, true);
        }
    }
};
```