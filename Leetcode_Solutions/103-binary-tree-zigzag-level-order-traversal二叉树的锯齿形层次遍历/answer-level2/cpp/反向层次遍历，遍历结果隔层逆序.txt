稍微修改一下层次遍历，每次先将右子树入队，后将左子树入队，就能得到反向层次遍历的结果。
对相应深度的结果reverse一下即可。
![NB8}(C41G@F@91Q1A)_1ZXG.jpg](https://pic.leetcode-cn.com/a315ac7831274c27120ca85a19d646287066929a2938ecf8eb40100200980118-NB8%7D\(C41G@F@91Q1A\)_1ZXG.jpg)

```
vector<vector<int>> res;
	queue<pair<TreeNode*,int>> myQueue;
	myQueue.push({root,1});
	int lastDepth = 0;

	while (!myQueue.empty())
	{
		TreeNode*pos = myQueue.front().first; 
		int depth = myQueue.front().second;//当前结点深度
		myQueue.pop();	
		if (pos == NULL)
			continue;

		if (depth > lastDepth) //如果出现更深的结点，建立一个vector存储本层的结点值
		{
			res.push_back(vector<int>());
			lastDepth = depth;
		}
		res[depth - 1].push_back(pos->val); //存储

		/*先右后左*/
		if (pos->right != NULL)
			myQueue.push({ pos->right,depth + 1 });
		if (pos->left != NULL)
			myQueue.push({ pos->left,depth + 1 });
		
	}
	for (int i = 0; i < res.size(); i++)
		if (i % 2 == 0)  //按题目要求隔层对结果反序
			reverse(res.at(i).begin(), res.at(i).end());
	return res;
```


