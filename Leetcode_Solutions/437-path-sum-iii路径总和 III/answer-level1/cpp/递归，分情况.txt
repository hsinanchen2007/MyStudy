估计是由于自己水平菜，还直接做的第三题的缘故，花了好长时间才发现自己写的东西哪里不对。
问题一：
一开始以为路径总数是根节点不加入时左右子树路径总数的和，加上根节点加入时左右子树路径总数的和。
好不容易才发现，根节点加入路径时，左右子树路径中必须把子树的根节点也加入，因为路径中间不能断开。
因此必须再构造一个函数，这个函数应该返回根节点必须加入的路径总数。
问题二：
计算路径数时，当根节点值和sum相等时计算结果就应该+1，然后再加上前面四种情况的路径数的和。
一开始写成
```
int count=0;
if(sum==0)
    count++;
if(!root)
    return count;
```
这样写在判断某棵树路径和为0的路径数时，对到它根节点的父节点的路径做了个计数。这样存在一个问题，当根节点的左右子树为空时，若存在一条路径到该根节点结束，则调用的两个子问题函数各返回了1，而实际上这两个1表示的是同一条路径。

```C++ []
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		int count = 0;
		if (!root)
			return 0;
		if (sum == root->val)
			count++;	
		count += pathSum(root->left, sum) + pathSum(root->right, sum);
		count += headJoin_pathSum(root->left, sum - root->val) + headJoin_pathSum(root->right, sum - root->val);
		return count;
	}
	int headJoin_pathSum(TreeNode* root, int sum) {
		int count = 0;
		if (!root)
			return 0;
		if (sum == root->val)
			count++;		
		count += headJoin_pathSum(root->left, sum - root->val) + headJoin_pathSum(root->right, sum - root->val);
		return count;
	}
};
```
