![QQ截图20191108162738.png](https://pic.leetcode-cn.com/862919ebaceadc49543a52a62098fdb16e424169e02b798520935ae64d4039d1-QQ%E6%88%AA%E5%9B%BE20191108162738.png)
```
vector<int> inorderTraversal(TreeNode* root) {
    	/*
        	用cur指向当前遍历到的节点 对每个节点执行相同的操作
			if(有左子树) 
			{ 一直向左深下去知道没有左子树，并将路径上的节点一依次加入栈}
			else(没有左子树)
			{
				1.访问当前节点(将当前节点的值加入到vector中) 
				2.将cur指向右子树执行相同的操作 
			} 
			 
		*/
        vector<int> vec;
        stack<TreeNode *> sta;
        
        TreeNode *cur=root;
        while(cur || !sta.empty())
        {
        	while(cur)
        	{
        		sta.push(cur);
        		cur=cur->left;
			}
			
			cur=sta.top();
			sta.pop();
			vec.push_back(cur->val);
			cur=cur->right;
		}
		
		return vec;
    }
```
