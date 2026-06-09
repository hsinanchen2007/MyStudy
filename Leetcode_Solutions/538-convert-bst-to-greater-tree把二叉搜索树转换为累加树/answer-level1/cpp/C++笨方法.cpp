没有用到搜索树的特性，好处时对任何树都能用。
void dfs每次调用遍历整个二叉树，找出大于传入结点值int preval，并累加到int* prept上面；
void search遍历树的结点一遍，调用void dfs函数计算出当前结点累加值，并将结果压入vector<int> sum
void search_in函数将vector<int> sum对应位置的值赋值给对应结点，至此完成操作
得到正确答案
```
class Solution {
public:vector<int> sum;
    void dfs(TreeNode* root,int* prept,int preval){//每次传入根结点，当前结点值指针，当前结点值,遍历一次搜索树，获取对应结点的修改值
    if(root==NULL)return ;
	if(root->val>preval&&prept!=&(root->val)  ){*prept+=root->val;}
    dfs(root->left,prept,preval);
    dfs(root->right,prept,preval);
	return;
    }

    void search(TreeNode* root,TreeNode* ROOT,int nodeval){//遍历一次，搜索数的各个结点值指针以及结点值
        if(root==NULL) return;
		dfs(ROOT,&(root->val),root->val);
        sum.push_back(root->val);
        root->val = nodeval;
		if(root->left)search(root->left,ROOT,root->left->val);
		if(root->right)search(root->right,ROOT,root->right->val);
		return;
    }
    
    void search_in(TreeNode* root,vector<int> &sum){//将修改后的结点值逐一赋值给原结点值
        if(root==NULL) return;
        root->val = sum[0];sum.erase(sum.begin()+0);
		if(root->left)search_in(root->left,sum);
		if(root->right)search_in(root->right,sum);
		return;
    }

    TreeNode* convertBST(TreeNode* root) {
       if(!root) return root;
	   search(root,root,root->val);
       search_in(root,sum);
	   return root;
    }
};
```
