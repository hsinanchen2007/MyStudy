用二维vector ans存储指针。用c记录当前层数，奇数层逆序访问上一层的指针，先插入左指针，再插入右指针。偶数层也是逆序访问上一层的指针，但先插入右指针，再插入左指针。
```
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<TreeNode*>> ans;
    if(root==nullptr)return vector<vector<int>>();
    ans.push_back(vector<TreeNode*>());
	ans[0].push_back(root);
    int c=0,flag=1;
	while(flag){
		c++;
		flag=0;
		int n=ans[c-1].size();
		ans.push_back(vector<TreeNode*>());
        if(c%2==0){
		     for(int i=n-1;i>=0;i--){
			    if(ans[c-1][i]->left!=nullptr){
				    flag=1;
			     	ans[c].push_back(ans[c-1][i]->left);
		    	}
			    if(ans[c-1][i]->right!=nullptr){
				    flag=1;
				    ans[c].push_back(ans[c-1][i]->right);
			    }
		    }
        }else{
            for(int i=n-1;i>=0;i--){
			    if(ans[c-1][i]->right!=nullptr){
				    flag=1;
			     	ans[c].push_back(ans[c-1][i]->right);
		    	}
			    if(ans[c-1][i]->left!=nullptr){
				    flag=1;
				    ans[c].push_back(ans[c-1][i]->left);
			    }
		    }


        }
		
	}
	vector<vector<int>> res(c);cout<<c;
	for(int i=0;i<c;i++){
		for(int j=0;j<ans[i].size();j++){
			res[i].push_back(ans[i][j]->val);
		}
	}
    return res;
}

```
