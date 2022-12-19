### 解题思路
此处撰写解题思路



### 代码

```cpp
原版代码
vector<int> inorderTraversal(TreeNode* root) {
	if(!root) return res;
	stack<TreeNode*> stn;
	TreeNode* cnode = root;
	while(cnode || !stn.empty()){
		while(cnode){			//一直向左遍历并保存节点
			stn.push(cnode);	// 直到不存在左节点为止
			cnode = cnode->left;
		}
		cnode = stn.top(); stn.pop();
		res.push_back(cnode->val);
		cnode = cnode->right;		//如果右节点为空则下一个循环将会直接出栈下一个栈中元素
	}								//如果右节点不空 将右节点作为新的子树
	return res;
}

改进版
vector<int> res;
vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return res;
    stack<TreeNode*> stn;
    TreeNode* cnode = root;
    for(; cnode || !stn.empty(); cnode=cnode->right){   //将两个while都改成for 就双100了
        for(; cnode; cnode=cnode->left) stn.push(cnode);//
        cnode = stn.top(); 
        stn.pop();
        res.push_back(cnode->val);
    }
    return res;
}

```