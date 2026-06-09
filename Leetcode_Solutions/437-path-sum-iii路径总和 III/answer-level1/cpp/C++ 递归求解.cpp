### 解题思路
两次递归，可以发现，对以root为根的树进行查找路径数量和对以root的左右子树查找路径的思路一样，因此可以采用递归，在统计路径数量函数上，采用的DFS

### 代码

```cpp
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		int count = 0;//统计出现的数量
		FindPath(root, sum, count);//由于FindPath对root==nullptr进行了判断，因此此处无需写特判代码
		return count;
	}
	//对以root为根的树及其左右子树都进行统计
	void FindPath(TreeNode* root, int sum, int& count)
		//sum：目标值
		//count: 出现的数量（类型为引用）
	{
		if (root == nullptr) return;
		//从以root为根的树统计该路径的数量
		CountPath(root, 0, sum, count);
		//左右子树分别寻找
		FindPath(root->left, sum, count);
		FindPath(root->right, sum, count);
	}
	//统计从以root为根的树该路径的数量
	void CountPath(TreeNode* root, int currentSum, int sum, int& count)
		//currentSum:当前路径和
		//sum:目标值
		//count:路径数量
	{
		//根节点处理
		currentSum += root->val;
		if (currentSum == sum) {
			count++;//相等
		}
		//遍历左右子树
		if (root->left != nullptr) CountPath(root->left, currentSum, sum, count);//左子树不为空，则向左子树寻找
		if (root->right != nullptr) CountPath(root->right, currentSum, sum, count);//右子树不为空，则向右子树寻找
		//在返回父节点之前，先删除当前结点值
		currentSum -= root->val;
	}
};
```