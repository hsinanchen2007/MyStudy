话不多说 直接上代码 结合注释 简单易懂
```
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (root == nullptr) return res;
	//队列中保存了两个元素 第一个是节点指针 第二个是该节点指针的层数
	queue<pair<TreeNode*,int>> que;	
	//推入首节点 并且设置节点层数为1
	int i = 1;													
	que.push(make_pair(root,i));
	while (!que.empty()) {
		pair<TreeNode*, int> bufs = que.front();			
		que.pop();		
		//弹出一个节点的pair 判断下当前节点深度和数组数量
		//原则上 res的数量和树的深度（层数也就是pair的第二个值）是一样的 
		//如果不一样 那么证明这个元素是下一层的 需要c开辟一个新的vector存入这新一层的元素
		if (bufs.second > res.size()) {					
			res.push_back(vector<int>());
			++i;
		}
		//假如当前层数和res中的数组数量相同 那就证明这个元素继续添加就好了 
		res.back().push_back(bufs.first->val);
		//把当前节点的数值输出后 弹入左节点和右节点 如果说节点为空 队列中也就没有必要保存空数值了
		if(bufs.first->left!=nullptr)
			que.push(make_pair(bufs.first->left, i));
		
		if (bufs.first->right != nullptr)
			que.push(make_pair(bufs.first->right, i));
	}
	return res;
}
```
