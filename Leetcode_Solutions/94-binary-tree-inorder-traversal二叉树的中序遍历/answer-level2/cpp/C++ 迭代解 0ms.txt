用了两个bool值作为标记，来标识已经去过的节点
系统显示0ms跑完了，不知道是不是bug
`class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            if(root == NULL) return result;
			stack<TreeNode*> processStack;
			processStack.push(root);			
			TreeNode* pt = root;
			bool goDeeperL = true, goDeeperR = true;
			while (!processStack.empty())
			{
				while (processStack.top()->left != NULL && goDeeperL)
				{
					processStack.push(processStack.top()->left);
				}
				pt = processStack.top();
				result.push_back(processStack.top()->val);
				processStack.pop();
				goDeeperL = false;
				goDeeperR = true;
				if (pt->right != NULL && goDeeperR) {
					goDeeperL = true;
					goDeeperR = false;
					processStack.push(pt->right);
				}				
				
				
			}
			return result;
		}
};`