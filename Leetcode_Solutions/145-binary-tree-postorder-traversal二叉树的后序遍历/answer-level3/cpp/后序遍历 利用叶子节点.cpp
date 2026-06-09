和前序和中序差别有两点，一是入栈的时候只要该节点有子节点压栈，保证栈顶元素是一个叶子节点；二是引入临时节点preNode表示上一个访问的节点。具体步骤如下：
1、如果当前节点不为空，将当前节点入栈，如果当前节点左节点不为空，将左节点入栈，否则的话如果右节点不为空，将右节点入栈。
```
while (currNode != NULL)
{
    rootStack.push(currNode);
    if (currNode->left != NULL)
        currNode = currNode->left;
    else
        currNode = currNode->right;
}
// 退出循环时，栈顶元素一定是叶子节点
```
所以退出循环时栈顶元素一定是叶子节点
2、对栈顶元素出栈，并存入输出列表
```
currNode = rootStack.top();
rootStack.pop();
ans.push_back(currNode->val);
```
3、记录当前遍历的节点为preNode，对下一个栈顶元素出栈
 * 如果前一个遍历的节点是当前节点的左节点，将当前节点的左节点赋空（因为已经遍历过了，为了防止在第一步中重新入栈）；
 * 如果前一个遍历的节点是当前节点的右节点，将当前节点的右节点赋空（因为已经遍历过了，为了防止在第一步中重新入栈）。
4、更新当前节点为该节点的右节点（一定要更新，否则就会陷入反复push-pop的死循环）。（因为先左后右，该节点的左节点在这之前一定已经遍历完了）

完整代码
```
vector<int> ans;
vector<int> postorderTraversal(TreeNode* root) {
	TreeNode* currNode = root,*preNode = root;
	stack<TreeNode*> rootStack;
	while (currNode != NULL || !rootStack.empty())
	{
		while (currNode != NULL)
		{
			rootStack.push(currNode);
			if (currNode->left != NULL)
				currNode = currNode->left;
			else
				currNode = currNode->right;
		}
		// 退出循环的这个点为NULL，且栈顶元素为叶子节点
		if (!rootStack.empty())
		{
			currNode = rootStack.top();
			rootStack.pop();
			ans.push_back(currNode->val);  // 对栈顶叶子节点出栈
			if (!rootStack.empty())
			{
				preNode = currNode;
				currNode = rootStack.top();
				// 制造新的叶子节点，删除已经遍历的节点
				if (preNode == currNode->left)  
					currNode->left = NULL;
				else if (preNode == currNode->right)
					currNode->right = NULL;
				
			}
			currNode = currNode->right;  // 更新节点

		}
			
	}	   	 
	return ans;
}
```

请多多指教^_^