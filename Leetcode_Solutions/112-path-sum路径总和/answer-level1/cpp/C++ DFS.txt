### 解题思路
DFS

### 代码

```cpp
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		vector<int> path;//模拟栈
		bool flag = false;//是否已经找到
		FindPath(root, path, sum, 0, flag);
		return flag;
	}
	void FindPath(TreeNode* root,vector<int> path, int expectSum, int currentSum,bool& flag)
	{
		currentSum += root->val;
		path.push_back(root->val);
		bool isLeaf = root->left == nullptr && root->right == nullptr;
		if (currentSum==expectSum&&isLeaf)
		{
			flag = true;
            cout<<flag<<" ";
            
		}
		if (root->left != nullptr&&!flag) FindPath(root->left, path, expectSum, currentSum, flag);//左子树存在且还没有找到，把左子树加入
		if (root->right != nullptr&&!flag) FindPath(root->right, path, expectSum, currentSum, flag);//右子树存在且还没有找到，把右子树加入
		//返回父节点之前，在路径上删除当前结点
		path.pop_back();
	}
};
```