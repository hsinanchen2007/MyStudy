### 思路
1. 突发奇想想用二分查找来找完全二叉树
2. 先找到左子树最下层，确定 h
3. 然后根据公式就能确定 lo 和 hi
4. 使用二分查找验证对应的值是否有节点
5. 对于查询的值，要规划一条从根节点左右左右走下来的路径
6. 需要把查询值一路 /2 到底，再一路走上来

### 答题
```C++
bool checkNode(TreeNode* root, int target)
{
	if (target == 1) return (root != nullptr);
	vector<int> path;
	path.push_back(target);
	while (path.back() != 2 && path.back() != 3)
	{
		path.push_back(path.back() / 2);
	}

	TreeNode *pNode = root;
	int cur = 1;
	while (!path.empty() && pNode != nullptr)
	{
		pNode = (cur * 2 == path.back()) ? pNode->left : pNode->right;
		cur = path.back();
		path.pop_back();
	}
	return (pNode != nullptr);
}

int countNodes(TreeNode* root)
{
	if (root == nullptr) return 0;
	int h = 0;
	TreeNode *pNode = root;
	while (pNode->left != nullptr)
	{
		h++;
		pNode = pNode->left;
	}

	int lo = pow(2, h);
	int hi = pow(2, h + 1);
	while (lo < hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (checkNode(root, mid))
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	return lo - 1;
}
```




### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

