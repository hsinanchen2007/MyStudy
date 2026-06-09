```
 /** 337.打家劫舍III
  *  思路：对于每个node，有两种情况，1:打劫当前node；2:不打劫当前node
  *  状态转移方程：rob(root) = max{root->val + rob(root的孙子节点）、rob(root->left) + rob(root->right)};
  *  另外，由于有重复计算，因此需要有备忘录记录之前已经被计算过的节点。
  **/
 unordered_map<TreeNode*, int>m_rob; //备忘录
 int rob(TreeNode* root) {
	 int res = 0;
	 if (root == nullptr)
		 return 0; //root为空返回0
	 if (root->left == nullptr && root->right == nullptr)
		 return root->val; //root为叶子节点返回root的val
	 if (m_rob.count(root) > 0)
		 return m_rob[root]; //如果备忘录中存在root就不在重复计算

	 int left_val = 0, right_val = 0; //子节点
	 int left_left_val = 0, left_right_val = 0, right_left_val = 0, right_right_val = 0; //孙子节点
	 if (root->left != nullptr)
	 {
		 left_val = rob(root->left);
		 left_left_val = rob(root->left->left);
		 left_right_val = rob(root->left->right);
	 }
	 if (root->right != nullptr)
	 {
		 right_val = rob(root->right);
		 right_left_val = rob(root->right->left);
		 right_right_val = rob(root->right->right);
	 }
	 int a = root->val + left_left_val + left_right_val + right_left_val + right_right_val; //打劫当前root的情况
	 int b = left_val + right_val; //不打劫当前root的情况

	 res = a > b ? a : b;
	 m_rob[root] = res;
	 return res;
## }
```
