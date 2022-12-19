- 递归思路：
    - 对称二叉树，顾名思义，判断路径为（一个结点向左，另一结点向右）或者（一个结点向右，另一结点向左）。于是，递归函数传入两个结点，首先判断是否为NULL。是都为NULL，还是一个为NULL，对应不同的情况。
    - 判断这两个结点的val是否相等；
    - 不相等，则结束递归，返回false；
    - 相等，则按照上面的判断路径，递归判断。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isEqual(TreeNode* a, TreeNode* b){
        if(!a && !b)
            return true;
        if(a && b)
            return (a->val==b->val) && isEqual(a->left, b->right) && isEqual(a->right, b->left);
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root){
            return isEqual(root->left, root->right);
        }else
            return true;
    }
};
```
- 迭代思路
    - 根据上面写的递归的代码，用栈模拟递归的调用即可。
    - 注意事项：
    - 入栈的顺序；
    - 即使是NULL也要push进去。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        stack<TreeNode*> stk;
        TreeNode *a, *b;
        if(root)
        {
            stk.push(root->left);
            stk.push(root->right);
        }
        while(!stk.empty())
        {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            if(!a && !b)
                continue;
            if(a && b)
            {
                if(a->val != b->val)
                {
                    return false;
                }
                else
                {
                    stk.push(a->left);
                    stk.push(b->right);
                    stk.push(a->right);
                    stk.push(b->left);
                }
            }
            else
                return false;
        }
        return true;
    }
};
```

