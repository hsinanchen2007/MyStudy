### 思路
1. 层序遍历用queue。
2. 一开始想遍历完存到vector中，然后再逆序一下。
3. 然后想了下，直接递归也能实现逆序。
4. 只需要在递归之后再放入vector。

### 答题
```C++
void levelOrderBottom(queue<TreeNode *> que, vector<vector<int>> &ans)
{
	if (que.empty()) return;
	queue<TreeNode *> queNext;
	vector<int> vec;
	while (!que.empty())
	{
		TreeNode *pNode = que.front();
		que.pop();
		vec.push_back(pNode->val);
		if (pNode->left != nullptr) queNext.push(pNode->left);	
		if (pNode->right != nullptr) queNext.push(pNode->right);
	}
	levelOrderBottom(queNext, ans);
	ans.push_back(vec);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
	vector<vector<int>> ans;
	queue<TreeNode *> q;
	if (root != nullptr) q.push(root);
	levelOrderBottom(q, ans);
	return ans;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)
