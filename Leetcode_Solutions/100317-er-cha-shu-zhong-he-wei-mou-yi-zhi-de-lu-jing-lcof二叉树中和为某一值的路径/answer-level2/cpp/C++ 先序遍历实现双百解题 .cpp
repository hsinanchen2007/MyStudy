### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/df3853080d918701b084db08aebf5e94cfd334fdb046ac4455add7dadc3ae7e2-image.png)
二叉树的先序遍历的变形，也可以说是DFS

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
        if(root==NULL) return res;
		vector<int> path;//使用vector作栈，使用它作栈来实现后进能够先出
		FindPath(root, res, path, sum, 0);
		return res;
	}
	void FindPath(TreeNode* root, vector<vector<int>>& res,vector<int>& path,int expectedSum, int currentSum)
	{
        
		currentSum += root->val;
		path.push_back(root->val);
        bool isLeaf=(root->left == NULL&&root->right==NULL);
		if (currentSum==expectedSum&&isLeaf)//如果当前值与给出的值相等，且该结点为叶子节点，则
		{
			res.push_back(path);//该路径入栈
		}
		if (root->left != NULL) FindPath(root->left, res, path, expectedSum, currentSum);
		if (root->right != NULL) FindPath(root->right, res, path, expectedSum, currentSum);
		//返回父节点之前，在路径上删除当前结点
		path.pop_back();
	}
};
```