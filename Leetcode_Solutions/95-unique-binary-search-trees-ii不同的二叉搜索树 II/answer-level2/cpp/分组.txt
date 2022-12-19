### 解题思路
如果要生成从1到n这n个树所构成的所有BST，按照其根节点的数值可以分为n种类型：即根节点的值为从1...n。假设我们要生成根节点为k (1 <= k <= n)的所有BST，那么首先需要生成范围为1到k-1的所有BST作为左子树，以及范围为k+1到n的所有BST作为右子树，然后两两组合就可以形成根节点为k的所有BST

三重循环时间复杂度有点高。

### 代码

```cpp
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n < 1)
        {
            return res;
        }
        res = creatTree(1,n);
        return res;
    }


    vector<TreeNode*> creatTree(int start,int end)
    {
        vector<TreeNode*> res;
        if(start > end)//空节点
        {
            res.push_back(NULL);
            return res;
        }
        if(start == end)//1个节点
        {
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            return res;
        }
        //如果start < end
        for(int i = start;i <= end;i++)//第一层循环是根节点的值
        {
            //左子树[start,i -1]   右子树[i+1,end]
            vector<TreeNode*> left  = creatTree(start,i-1);
            vector<TreeNode*> right = creatTree(i+1,end);

            for(int j = 0;j < left.size();j++)//第二层循环是左子树节点的下标
            {
                for(int k = 0;k < right.size();k++)//第三层循环是右子树节点的下标
                {
                    TreeNode *node = new TreeNode(i);//创建根节点
                    node->left  = left[j];//链接左节点
                    node->right = right[k];//链接右节点
                    res.push_back(node);
                }
            }
        }
        return res;
    }

};
```