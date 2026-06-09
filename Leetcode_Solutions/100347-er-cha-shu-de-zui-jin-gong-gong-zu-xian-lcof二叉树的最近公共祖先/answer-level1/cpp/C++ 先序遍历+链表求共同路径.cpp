### 解题思路
1、使用先序遍历，求出从根节点到目标节点的路径
2、对两条路径，求共同节点

### 代码

```cpp
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL) return NULL;
		list<TreeNode*> path1, path2;
		GetNodePath(root, p, path1);
		GetNodePath(root, q, path2);
		return GetLastCommonNode(path1, path2);
	}
	//获取从根节点到目标节点的路径
	bool GetNodePath(TreeNode* root, TreeNode* node, list<TreeNode*>& path)
	{
        //先把root节点加入到list中
		path.push_back(root);
		//找到目标节点
		if (root == node)  return true;
		//标志符found
		bool found = false;
		if (!found && root->left != NULL) found = GetNodePath(root->left, node, path);
		if (!found && root->right != NULL) found = GetNodePath(root->right, node, path);
		//如果没有找到，则返回头节点时，删除当前节点
		if (!found)
		{
			path.pop_back();
		}
		return found;
	}
	//获取共同节点
	TreeNode* GetLastCommonNode(list<TreeNode*> path1, list<TreeNode*> path2)
	{
		TreeNode* pLast = nullptr;
		list<TreeNode*>::iterator it1 = path1.begin();
		list<TreeNode*>::iterator it2 = path2.begin();
		while (it1!=path1.end()&&it2!=path2.end())
		{
			if (*it1 == *it2) pLast = *it1;
			it1++;
			it2++;
		}
		return pLast;
	}
};
```