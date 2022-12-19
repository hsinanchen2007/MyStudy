- 用队列实现遍历
- 设置bool变量实现每行的左右插入顺序
- stack对一行节点进行反转

```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        	return {};
        queue<TreeNode*> q;
        TreeNode *tp;
        q.push(root);
        stack<TreeNode*> s;
        int size;
        vector<int> lv;
        vector<vector<int>> ans;
        bool flag = false;
        while(!q.empty())
        {
        	size = q.size();
        	flag = !flag;//每行反转一下
        	while(size--)
        	{
        		tp = q.front();
        		q.pop();
        		lv.push_back(tp->val);
        		if(flag)//偶数行
        		{	//先左后右
        			if(tp->left)  s.push(tp->left);
        			if(tp->right) s.push(tp->right);
        		}
        		else//奇数行
        		{	//先右后左
        			if(tp->right) s.push(tp->right);
        			if(tp->left)  s.push(tp->left);	
        		}
        	}
        	
    		while(!s.empty())
    		{	//反转加入队列
    			q.push(s.top());
    			s.pop();
    		}
        	ans.push_back(lv);
        	lv.clear();
        }
        return ans;
    }
};

```

[https://michael.blog.csdn.net/article/details/100577842](https://michael.blog.csdn.net/article/details/100577842)
