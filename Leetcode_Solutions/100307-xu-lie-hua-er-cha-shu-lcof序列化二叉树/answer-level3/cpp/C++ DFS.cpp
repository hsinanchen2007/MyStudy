### 解题思路
改写先序遍历完成序列化
改写先序遍历完成反序列化

### 代码

```cpp
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		if (root == nullptr) return res;
		serializeTree(root, res);
		return res;
	}
	//序列化
	void serializeTree(TreeNode* root, string& s)
	{
		//边界条件
		if (root==NULL)
		{
			s += "$,";
			return;
		}
		s += to_string(root->val) +",";
		serializeTree(root->left, s);//左子树序列化
		serializeTree(root->right, s);//右子树序列化
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int p = 0;
        if(data.size()==0) return NULL;
		return deserializeTree(p, data);
	}
	//反序列化
	TreeNode* deserializeTree(int& p,const string& data)
	{
		//对空的判断
		if (data[p]=='$')
		{
			p += 2;
			return NULL;
		}
		//对出现负号时的处理
		bool isN = false;
		if (data[p]=='-')
		{
			p++;
			isN = true;
		}
        int num = 0;
		while (data[p]!=',')
		{
            //转换成整数
			num = num * 10 + (data[p] - '0');
			p++;
		}
		p++;//由于p此时的字符为','，因此需要自增1
		//如果是负数
		if (isN)
		{
			num = -num;
		}
		TreeNode* root = new TreeNode(num);
		root->left = deserializeTree(p, data);
		root->right = deserializeTree(p, data);
		return root;
	}
};
```