**递归**
判断每一层时，使用一个标记表明是哪一层；
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
	void LevelOrder(TreeNode* root, int level, vector<vector<int>>& res)
	{
		if (root == nullptr)
			return;
		if (level + 1>res.size())
			res.push_back(vector<int>());
		res[level].push_back(root->val);
		LevelOrder(root->left, level + 1, res);
		LevelOrder(root->right, level + 1, res);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		LevelOrder(root, 0, res);
		return res;
	}
};
```


**迭代**
使用队列的特点
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            TreeNode* node;
            for(int i = 0;i <size;++i) //确保本层节点全部收集完；
            {
                node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(temp); //将该层结果存入结果集；
        }
        return res;
    }
};
```