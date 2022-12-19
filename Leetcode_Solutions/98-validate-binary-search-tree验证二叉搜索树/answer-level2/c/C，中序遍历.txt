```
bool isValidBST(struct TreeNode* root){
	
    
	int min = INT_MIN;// 初值不能随便赋值，
    int count = 0; // 如果INT_MIN是中序遍历的第一个元素，会出现问题。所以用count标记元素个数
	
	struct TreeNode *cur = root, *pre = root;
	
	while(cur != NULL) //中序，向右时输出
	{
		if(cur->left == NULL)
		{
			if(cur->val <= min && count != 0)
			{
				return false;
			}
			count++;
			min = cur->val;
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur)
			{
				pre = pre->right;
			}
			if(pre->right == cur)
			{
				pre->right = NULL;

                if(cur->val <= min && count != 0)
				{
					return false;
				}
                count++;				
				min = cur->val;
				cur = cur->right;
			}
			else
			{
				pre->right = cur;
				cur = cur->left;
			}
		}
	}
	
	return true;
}
```
