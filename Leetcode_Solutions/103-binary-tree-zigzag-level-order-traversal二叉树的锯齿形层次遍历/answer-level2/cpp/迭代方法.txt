//看了powcai大佬的模仿写了c++解法
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
		if(root==NULL)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		int depth=0;
		while(!q.empty()){
			vector<int> tmp;
			int length=q.size();
			for(int i=0;i<length;i++){
				TreeNode* node=q.front();
				q.pop();
				if(depth%2==0) tmp.push_back(node->val);
                else tmp.insert(tmp.begin(),node->val);
				if(node->left!=NULL) q.push(node->left);
				if(node->right!=NULL) q.push(node->right);
			}
			res.push_back(tmp);
			depth++;
		}
		return res;
    }
};
