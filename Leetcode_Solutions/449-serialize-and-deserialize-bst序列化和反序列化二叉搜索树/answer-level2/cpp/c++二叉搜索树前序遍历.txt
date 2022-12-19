
class Codec {
public:
	// Encodes a tree to a single string.
	//将树转换为字符串
	string serialize(TreeNode* root) {
		string data;
		BST_preorder(root,data);//前序遍历树
		return data;
	}

	// Decodes your encoded data to tree.
	//将字符串转化为树
	TreeNode* deserialize(string data) {
		if (data.length()==0)//判空
		{
			return NULL;
		}
		vector<TreeNode*> valVec;
		int val = 0;
		for (int i = 0; i < data.length();i++)
		{
			if (data[i]=='#')//将数字push进vector
			{
				valVec.push_back(new TreeNode(val));
				val = 0;
			}
			else//将字符串转化为数字，计算一个点的数字
			{
				val =val*10+ data[i] - '0';
			}
		}
		//将vector中的数值逐个插入树中
		for (int i = 1; i < valVec.size();i++)
		{
			BST_insert(valVec[0], valVec[i]);
		}
		return valVec[0];
	}
private:

	//前序遍历，将树转化为字符串
	void BST_preorder(TreeNode* node,string& data)
	{
		if (node==NULL)
		{
			return;
		}
		string str_val;
		change_into_string(node->val,str_val);//将数值转化为字符串
		data += str_val;
		BST_preorder(node->left, data);
		BST_preorder(node->right, data);
	}

	//将数字转化为字符串，并在尾部加上“#”
	void change_into_string(int val,string& str_val)
	{
		string tmp;
		while (val)//数字不一定是个位数，可能单个数字很长
		{
			tmp += val % 10 + '0';
			val = val / 10;
		}
		for (int i = tmp.length()-1; i>=0;i--)
		{
			str_val += tmp[i];
		}
		str_val += '#';
	}

	//将数字插入树中
	void BST_insert(TreeNode* node, TreeNode* insertNode)
	{
		if (insertNode->val<node->val)//插左边
		{
			if (node->left==NULL)
			{
				node->left =insertNode;
			}
			else
			{
				BST_insert(node->left, insertNode);
			}
		}
		else//插右边
		{
			if (node->right==NULL)
			{
				node->right =insertNode;
			}
			else
			{
				BST_insert(node->right, insertNode);
			}
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));测试的调用顺序