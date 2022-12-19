1、叶节点的判断：左右子树全为null
   非叶结点的处理：如果左右子树均非空，结果取决于左子树 || 右子树
		   如果左子树为空，结果取决于右子树
		   如果右子树为空，结果取决于左子树
```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        int add = 0;
        return hasPathSumHelp(root, sum, add);
    }

    bool hasPathSumHelp(TreeNode* root, int sum, int& add)
    {
        if(!(root->left) && !(root->right))
        {
            add += root->val;
            return sum == add;
        }

        add += root->val;
        int left = add;
        int right = add;
        int leftbool, rightbool;
        if(root->left)  leftbool = hasPathSumHelp(root->left, sum, left);
        if(root->right) rightbool = hasPathSumHelp(root->right, sum, right);
        if(root->left && root->right) return leftbool || rightbool;
        else if(root->left) return leftbool;
        else  return rightbool;
    }
};
```
2、改进：
   非叶节点的判断：如果是非叶结点，结果取决于左子树 || 右子树
   注意：hasPathSumHelp函数开头要加入判断
	if(root == null) return false;
   原因：如树：[1,2]，sum:1；结点2的右结点不是叶节点；
```
    bool hasPathSumHelp(TreeNode* root, int sum, int& add)
    {
        if(!root) return false;
        if(!(root->left) && !(root->right))
        {
            add += root->val;
            return sum == add;
        }

        add += root->val;
        int left = add;
        int right = add;
        int leftbool, rightbool;
        if(root->left)  leftbool = hasPathSumHelp(root->left, sum, left);
        if(root->right) rightbool = hasPathSumHelp(root->right, sum, right);
        if(root->left && root->right) return leftbool || rightbool;
        else if(root->left) return leftbool;
        else  return rightbool;
    }
```

3、改进：
   在sum上直接操作，sum减去当前结点的值，若sum等于0，且当前结点是叶节点
则返回true；否则结果取决于左子树 || 右子树。
sum与1中add的区别，int sum,sum的值不会被函数改变，int& add，add的值会被
函数改变
```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!(root->left) && !(root->right))
        {
            sum -= root->val;
            return sum == 0;
        }

        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
```


