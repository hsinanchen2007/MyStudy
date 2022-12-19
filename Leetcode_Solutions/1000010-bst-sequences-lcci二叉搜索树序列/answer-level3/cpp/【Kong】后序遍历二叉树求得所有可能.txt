由遍历数组插入生成的二叉搜索树，数组的第一个元素为树的根节点，第二个元素为左子节点或右子节点。即对于同一节点而言，左右子树上的节点的插入是互不影响的；而纵向来看，必须先插入根节点，后插入左右子树的节点。

因此，通过递归后序遍历二叉树，自下向上构建二叉树找出所有可能，由所遍历的当前节点与其左右子树所返回的多个数组组合为所有可能生成当前子树的数组。组合方法为生成左子树的数组之一与生成右子树的数组之一进行组合，两数组组合为新数组后原两生成左右子树的各自数组的元素相对顺序不变。

时间复杂度 O((nlogn)^2)，空间复杂度 O(n^2)。

* 示例 :

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
    void BuildArray(vector<vector<int>>& MergeArray, vector<int>& Array, vector<int>& LeftArray, int LeftIndex, vector<int>& RightArray, int RightIndex)
    {
        if (LeftIndex < LeftArray.size() || RightIndex < RightArray.size())
        {
            if (LeftIndex < LeftArray.size())
            {
                Array.push_back(LeftArray[LeftIndex]);
                BuildArray(MergeArray, Array, LeftArray, LeftIndex + 1, RightArray, RightIndex);
                Array.pop_back();
            }
            if (RightIndex < RightArray.size())
            {
                Array.push_back(RightArray[RightIndex]);
                BuildArray(MergeArray, Array, LeftArray, LeftIndex, RightArray, RightIndex + 1);
                Array.pop_back();
            }
        }
        else
        {
            MergeArray.push_back(Array);
        }
    }

    vector<vector<int>> BSTSequences(TreeNode* root) 
    {
        if (root == NULL)
        {
            return {{}};
        }

        vector<vector<int>> rst;
        vector<vector<int>> LeftTree = BSTSequences(root->left);    
        vector<vector<int>> RigthTree = BSTSequences(root->right);

        for (int i = 0; i < LeftTree.size(); i++)
        {
            for (int j = 0; j < RigthTree.size(); j++)
            {
                vector<vector<int>> MergeArray;
                vector<int> tmp;
                tmp.push_back(root->val);
                BuildArray(MergeArray, tmp, LeftTree[i], 0, RigthTree[j], 0);
                for (int k = 0; k < MergeArray.size(); k++)
                {
                    rst.push_back(MergeArray[k]);
                }
            }
        }

        return rst;
    }
};
```
