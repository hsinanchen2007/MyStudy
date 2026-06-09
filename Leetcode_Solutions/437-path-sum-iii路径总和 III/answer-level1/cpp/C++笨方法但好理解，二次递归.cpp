// 我用的比较笨的方法，但代码容易理解:
// void root_in(TreeNode* root,int sum)函数的作用是中序遍历每个结点，
// void dfs(TreeNode* root,int count,int sum)函数的作用是以传入结点为根结点
// 中序遍历该结点余下二叉树。
// 这样就能找到所有满足要求的路径啦。
// 很笨，但是比较难的方法以后再慢慢理解吧，😭

// ```
class Solution {
public:int paths;
	   void dfs(TreeNode* root,int count,int sum){
	   if(root==NULL) return;
	   if(root) count+=root->val;
	   //sum-=root->val;
	   if(sum==count) paths+=1;
	   dfs(root->left,count,sum);dfs(root->right,count,sum);
	   return;
	   }
	   void root_in(TreeNode* root,int sum){
	   if(root==NULL)return;
       else dfs(root,0,sum);
	   if(root->left) root_in(root->left,sum);
	   if(root->right) root_in(root->right,sum);
	   return;
	   
	   }
    int pathSum(TreeNode* root, int sum) {
        paths=0;
		root_in(root,sum);
		return paths;

    }
};
// ```
