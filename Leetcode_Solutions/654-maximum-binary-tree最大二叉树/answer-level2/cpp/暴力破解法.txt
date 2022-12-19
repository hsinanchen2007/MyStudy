暴力解题，先找最大值，然后分组，按规则给最大节点分配左右子树，再在每组找最大值重复前步

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
	{
		int i,max =nums[0],indx = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
				indx = i;
			}
		}
		TreeNode* temp = new TreeNode(max);
		if (nums.size() == 1)
		{
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		vector <int> temp1(nums.begin(), nums.begin() + indx);
		vector <int> temp2(nums.begin() + indx + 1, nums.end());
		
		if(temp1.size()!=0)
		{
			temp->left = constructMaximumBinaryTree(temp1);
		}
		else
		{
			temp->left = NULL;
		}
		if (temp2.size() != 0)
		{
			temp->right = constructMaximumBinaryTree(temp2);
		}
		else
		{
			temp->right = NULL;
		}
		return temp;
		
		//return 0;
	}