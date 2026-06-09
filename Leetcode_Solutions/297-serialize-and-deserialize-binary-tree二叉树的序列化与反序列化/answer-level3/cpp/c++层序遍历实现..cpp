```
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == nullptr)return "";
		string res = ""; res.push_back('[');

		queue<TreeNode*>qu; qu.push(root);

		while (!qu.empty()) {//层序遍历,将树转化为字符串
			if (qu.front() == nullptr)res += "null";
			else {
				res += to_string(qu.front()->val);
				qu.push(qu.front()->left);
				qu.push(qu.front()->right);
			}
			qu.pop();
			res.push_back(',');
		}

		while (1) {//遍历到最后一层的时候会有多余的 null ,删除就行
			char c = res.back();
			if (c == ',' || c == 'n' || c == 'u' || c == 'l')
				res.pop_back();
			else break;
		}
		res.push_back(']');
		return res;
	}
	/*Upperlevel*/
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "")return nullptr;
		//删除左右2个'['  ']'
		data.pop_back();
		data.erase(data.begin());

		stringstream ss(data);

		vector<string>temp;//temp 中储存的是 val 和 null 

		string init;
		while (getline(ss, init, ','))temp.push_back(init);//过滤 ','

		vector<TreeNode*>Upperlevel;//存储的是上一层的节点

		int i = 0;
		TreeNode* root = new struct TreeNode(atoi(temp[i++].data()));
		Upperlevel.push_back(root);

		while (i < temp.size()) {
			vector<TreeNode*>second;//存储下一层的节点

			for (auto& vi : Upperlevel) {//每个节点都需要考虑左右子节点,分类考虑就行了
				if (i < temp.size() && temp[i] == "null")++i;
				else if (i < temp.size()) {
					vi->left = new struct TreeNode(atoi(temp[i++].data()));
					second.push_back(vi->left);
				}
				if (i < temp.size() && temp[i] == "null") ++i;
				else if (i < temp.size()) {
					vi->right = new struct TreeNode(atoi(temp[i++].data()));
					second.push_back(vi->right);
				}
			}
			Upperlevel = second;
		}
		return root;
	}
};
```