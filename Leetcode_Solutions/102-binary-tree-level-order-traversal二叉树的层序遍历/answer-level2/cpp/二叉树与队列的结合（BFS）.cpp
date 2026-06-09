从之前一个大佬那里得到的灵感，我感觉很好理解，发来跟大家一起分享，感谢这位大佬，侵删
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
    queue<TreeNode*> empty;
    vector<vector<int>> levelOrder(TreeNode* root) 
    {   
        queue<TreeNode*> currentNode, nextNode;
        currentNode.push(root);
        vector<vector<int>> result;
        if(root == NULL) return result;
        while (!currentNode.empty())
        {
            bfs(currentNode, nextNode, result);
        }
        return result;        
    }
private:
    void bfs(queue<TreeNode*>&currentN, queue<TreeNode*>& nextN, vector<vector<int>>& result)
    {
        vector<int> layerNum;
        while (!currentN.empty())
        {
            TreeNode* tmp = currentN.front();
            if(tmp->left)  {nextN.push(tmp->left);}
            if(tmp->right) {nextN.push(tmp->right);}
            layerNum.push_back(tmp->val);
            currentN.pop();
        }
        result.push_back(layerNum);
        swap(currentN, nextN);
        swap(nextN, empty);
    }
};
```

