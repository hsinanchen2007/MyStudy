
见代码，栈里添加了一个状态变量

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		if (root == nullptr)return res;
		struct Params {
			TreeNode* node;
			int stage;
			Params(TreeNode* n, int s = 0) :node(n), stage(s) {};
		};

		stack<Params> stk;
		stk.push(Params(root));
		while (!stk.empty())
		{
			switch (stk.top().stage)
			{
			case 0:
				stk.top().stage = 1;
				if (stk.top().node->left != nullptr) {
					stk.push(Params(stk.top().node->left));
				}
				break;
			case 1:
				stk.top().stage = 2;
				if (stk.top().node->right != nullptr) {
					stk.push(Params(stk.top().node->right));
				}
				break;
			case 2:
				res.push_back(stk.top().node->val);
				stk.pop();
				break;
			}
		}
		return res;
    }

