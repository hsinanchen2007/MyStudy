### 解题思路
方法一：参考自剑指offer
1、通过先序遍历，获取根节点到目标节点的路径
2、再通过获取的路径，求的公共节点

方法二：参考自
[@yuanninesuns](/u/yuanninesuns/)
思路：

1、如果p和q分别是root的左右节点，那么root就是我们要找的最近公共祖先
2、如果p和q都是root的左节点，那么返回lowestCommonAncestor(root->left, p, q)
3、如果pheq都是root的右节点，那么返回lowestCommonAncestor(root->right, p, q)
边界条件讨论：
1、如果是null表示已经找到最低了，返回null表示没找到
2、如果root与p相等或者q相等，则返回root
3、如果左子树没找到，递归函数返回null，证明p和q在root的右侧，那么最终的公共祖先就是右子树找到的结点
4、如果右子树没找到，递归函数返回null，证明p和q在root的左侧，那么最终的公共祖先就是左子树找到的结点

### 代码

#### 方法一：

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

#### 方法2：

```cpp
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//如果root===NULL，则返回NULL（此处写返回root一样的）；
		//如果root==p，返回p
		//如果root==q，返回q
		if (root == NULL || root == p || root == q) return root;
		//检查左子树是否含有p或q
		TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);
		//检查右子树是否含有p或q
		TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);
		if (leftTree == NULL) return rightTree;//左子树中没有，说明在右子树
		if (rightTree == NULL) return leftTree;//右子树中没有，说明在左子树
		//如果在root的左右子树中都找到了
		return root;
		 
	}
};
```