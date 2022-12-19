1 统计k点为根的子树下最近的叶节点；
2 从k值节点前一个父节点开始往根节点遍历，针对每个节点计算非K值节点所在分支的另一个分支的最近叶节点。由于叶节点和k值节点的深度相对于根节点，所以计算相对距离的时候可以用公式:  叶节点深度 + k值节点 - 2 X 叶节点和k值节点共同祖先深度

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
    unordered_map<TreeNode*, int> depthMap;
    vector<TreeNode*> targetPath;
    
    void calculateDepth(TreeNode* root, int depth)
    {
        depthMap[root] = depth;
        
        if (root->left)
            calculateDepth(root->left, depth+1);
        if (root->right)
            calculateDepth(root->right, depth+1);
    }
    
    TreeNode* findTarget(TreeNode* root, int k)
    {
        if (root->val == k)
        {
            return root;
        }
        
        TreeNode* child = NULL;
        if (root->left)
        {
            child = findTarget(root->left, k);
            if (child)
                targetPath.push_back(root);
        }
        if (!child && root->right)
        {
            child = findTarget(root->right, k);
            if (child)
                targetPath.push_back(root);
        }
        return child;
    }
    
    void findMinEdgesToLeafUnderTarget(TreeNode* root, int depth, int& min, int& minVal)
    {
        //int min = INT_MAX;
        if (!root->left && !root->right)
        {
            if (min > depth)
            {
                min = depth;
                minVal = root->val;
            }
            return;
        }
        
        if (root->left)
        {
            findMinEdgesToLeafUnderTarget(root->left, depth+1, min, minVal);
        }
        if (root->right)
        {
            findMinEdgesToLeafUnderTarget(root->right, depth+1, min, minVal);
        }
    }
    
    void getAllLeafExceptTargetLeaf(TreeNode* root, TreeNode* target, vector<TreeNode*>& leafs)
    {
        if (!root || root == target)
        {
            return;
        }
        
        if (!root->left && !root->right)
        {
            leafs.push_back(root);
            return;
        }
        
        if (root->left)
        {
            getAllLeafExceptTargetLeaf(root->left, target, leafs);
        }
        
        if (root->right)
        {
            getAllLeafExceptTargetLeaf(root->right, target, leafs);
        }
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
        TreeNode* target = findTarget(root, k);
        
        if (!target->left && !target->right)
            return target->val;
        
        calculateDepth(root, 0);
        
        int min = INT_MAX;
        int minVal = INT_MAX;
        findMinEdgesToLeafUnderTarget(target, 0, min, minVal);
        
        TreeNode* start = target;
        for (int i =0; i < targetPath.size(); ++i)
        {
            TreeNode* search = NULL;
            if (targetPath[i]->left && targetPath[i]->left != start)
            {
                search = targetPath[i]->left;
            }
            else if (targetPath[i]->right && targetPath[i]->right != start)
            {
                search = targetPath[i]->right;
            }
                
            vector<TreeNode*> otherLeafs;
            getAllLeafExceptTargetLeaf(search, target, otherLeafs);
                
            for (int j = 0; j < otherLeafs.size(); ++j)
            {
                int temp = depthMap[otherLeafs[j]] + depthMap[target] - 2*depthMap[targetPath[i]];
                if (temp < min)
                {
                    min = temp;
                    minVal = otherLeafs[j]->val;
                }
            }
            
            start = targetPath[i];
            
        }  
        return minVal;
    }
};