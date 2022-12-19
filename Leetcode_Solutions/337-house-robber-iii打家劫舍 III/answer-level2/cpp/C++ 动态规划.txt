思路参考自[王小二的题解](https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/)

以下面的这棵树来说明
&nbsp;&nbsp;a
&nbsp;b&nbsp;&nbsp;c&nbsp;
d&nbsp;&nbsp;e f&nbsp;&nbsp;g
对于这棵树，我们用爷爷-两个孩子-四个孙子来说明
问题的状态：
爷爷节点获取到最大的偷钱数是多少呢？
1、首先要明确相邻的节点不能偷，也就是爷爷选择偷，儿子就不能偷了，但是孙子可以偷
2、二叉树只有左右两个孩子，一个爷爷最多2个儿子，4个孙子
根据以上条件，可以得出单个节点的钱该怎么算：
**4个孙子的偷的钱+爷爷的钱VS两个儿子偷的钱**
哪个组合钱多，就能成为当前节点能偷的最大钱数，这就是动态规划里的**最优子结构**
由于是二叉树，这里可以选择计算所有子节点
4个孙子投的钱加上爷爷的钱如下
int method1=root.val+rob(root.left.left)+rob(root.left.right)+rob(root.right.left)+rob(root.right.right)
两个儿子偷的钱如下
int method2=rob(root.left)+rob(root.right);
挑选一个钱数多的方案则
int result=Math.max(method1,method2)
编写代码如下
```cpp

class Solution {
public:
	int rob(TreeNode* root) {
		if (root == nullptr) return 0;
		int money = root->val;
		if (root->left != nullptr) {//左孩子不为空，把孙子的钱抢了
			money += rob(root->left->left) + rob(root->left->right);
		}
		if (root->right!=nullptr)//右孩子不为空，把孙子的钱抢了
		{
			money + rob(root->right->left) + rob(root->right->right);
		}
		return max(money, rob(root->left) + rob(root->right));//抢孙子及爷爷的钱和抢两个儿子的钱进行比较
	}
};
```



**记忆化优化**
本题记忆化需要拿哈希表来当缓存，也是自己第一次遇到这种情况，大开眼界
对于上述思想进行编码，无法通过案例，因此，采用记忆化的方式，减少中间的计算量。**由于二叉树不适合拿数组当缓存，需要使用哈希表来存储结果，TreeNode当做key，能偷的钱当做value**

优化后的代码如下：
```cpp
class Solution {
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode*, int> dp;
		return robMemory(root, dp);
	}
	int robMemory(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
		if (root == nullptr) return 0;
		if (dp.find(root) != dp.end()) return dp[root];//已存在
		int money = root->val;
		if (root->left != nullptr) {
			money += robMemory(root->left->left, dp) + robMemory(root->left->right, dp);
		}
		if (root->right != nullptr)
		{
			money += robMemory(root->right->left, dp) + robMemory(root->right->right, dp);
		}
		money = max(money, robMemory(root->left, dp) + robMemory(root->right, dp));
		dp.insert({ root,money });//更新未存储过的dp键值对
		return dp[root];
	}
};
```