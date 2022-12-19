```
class Solution {
public:vector<int>num;
    void dfs(TreeNode* root){
        if(root==NULL) return;
		else num.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
        cout<<"root->val=="<<root->val<<endl;
    }

    vector<int> findMode(TreeNode* root) {
       dfs(root);//获取各个结点值
	   sort(num.begin(),num.end());
	   vector<int>vec;
	   vector<vector<int>> vecs;

	   while(num.size()){cout<<"num[0]="<<num[0]<<endl;
		   if(!vec.size()){vec.push_back(num[0]);num.erase(num.begin()+0);}//cout<<"num.size()="<<num.size()<<endl;
		   if(num.size()!=0&&vec[0]==num[0]) {vec.push_back(num[0]);num.erase(num.begin()+0);}
		   if(num.size()==0||vec[0]!=num[0]) {vecs.push_back(vec);vec.clear();}
	   }
       vec.clear();
	   if(vecs.size()){
		   int max = vecs[0].size();
	   for (int i=1;i<vecs.size();++i){
		   if(vecs[i].size()>max) max=vecs[i].size();
	   }
	   for (int i=0;i<vecs.size();++i){
		   if(vecs[i].size()==max){vec.push_back(vecs[i][0]);}
	   }
	   }
	    return vec;
    }
	  
};
```
