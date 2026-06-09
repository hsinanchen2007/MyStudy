### 解题思路
先序遍历（DFS）
此题难点感觉在于字符串的操作
通过先序遍历获得每一条路径，对于每一条路径使用vector<string>进行存储；如果它为叶子结点，则将路径中的值转换为一个串并连接起来，再压入到res（保存结果）中

### 代码

```cpp
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root == nullptr) return res;
		vector<string> vs;//存储每个结点转换为字符串后的值
		FindPath(root, res, vs);
		return res;
	}
	void FindPath(TreeNode* root, vector<string>& res, vector<string>& vs)
	{
		vs.push_back(to_string(root->val));//该值加入到
		bool isLeaf = root->left == NULL && root->right == NULL;
		if (isLeaf)
		{
			string s;//进行连接
			for (vector<string>::iterator it=vs.begin();it!=vs.end();it++)//遍历路径，将路径中的值先连成串
			{
				s += *it;
				if (it+1!=vs.end()) s += "->";
			}
			res.push_back(s);//压入到结果中
		}
		if (root->left != nullptr) FindPath(root->left, res, vs);
		if (root->right != nullptr) FindPath(root->right, res, vs);
		//在返回到父节点前，先在路径中删除当前结点
		vs.pop_back();
	}
};
```