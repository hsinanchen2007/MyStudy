**双层递归法**

双层递归的思想，其实之前做矩阵中搜索路径的题也用到过，只不过矩阵是通过循环来遍历，而树是用递归遍历

核心是，不在初始点就去试图搜索整个矩阵/树的所有可能路径，而是只搜索以自己为起始点的路径，这样可以避免很多的重复搜索

或者说，任何一个符合条件的解，其一定是以矩阵/树中的某个点为起始点的，而这个起始点是我们可以遍历到的
```cpp
class Solution 
{
private:
	int res = 0;
	/*这一层递归用来搜索*/
	void DFS(TreeNode* root, int sum)
	{
		if (!root)
		{
			return;
		}
		if (sum == root->val)
		{
			res++;
		}
		DFS(root->left, sum - root->val);
		DFS(root->right, sum - root->val);
	}
public:
	/*这一层递归用来遍历*/
	int pathSum(TreeNode* root, int sum) 
	{
		if (!root)
		{
			return 0;
		}
		DFS(root, sum);
		pathSum(root->left, sum);
		pathSum(root->right, sum);
		return res;
	}
};
```
**前缀和方法**

这里有两个要注意的点：
1. multiset初始要插入一个0，否则从根节点开始的路径是无法判断进去的
2. multiset删除节点时，要用迭代器删除，这样只会删除重复值的一个；如果用值删除，会删除所有重复的

```cpp
class Solution 
{
private:
	int res = 0;
	unordered_multiset<int> dic;
	void pathSearch(TreeNode* root, int sum, int cnt)
	{
		if (!root)
		{
			return;
		}
		cnt += root->val;
		if (dic.find(cnt - sum) != dic.end())
		{
			res += dic.count(cnt - sum);
		}
		dic.insert(cnt);
		pathSearch(root->left, sum, cnt);
		pathSearch(root->right, sum, cnt);
		/*必须用iter删除，这样只删除一个*/
		auto iter = dic.find(cnt);
		dic.erase(iter);
	}
public:
	int pathSum(TreeNode* root, int sum) 
	{
		/*必须初始插入一个0*/
		dic.insert(0);
		pathSearch(root, sum, 0);
		return res;
	}
};
```