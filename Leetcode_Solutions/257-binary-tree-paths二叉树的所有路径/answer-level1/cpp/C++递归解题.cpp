```
 /*本题采用递归思路是毋庸置疑的，
 难点在于如何将当前字符串传递给下一次递归调用
 其实也不难
 在递归函数的参数列表多加一个形参string tem,即可将当前路径传递下去啦
 这是我起初没想到的，😭
 */
class Solution {
public:
	   void dps(TreeNode* root,string tem,vector<string>&s){//tem用来存储当前所经过的路径
		    //if(!root->left&&!root->right) {string tem;tem+=root->val;s.push_back(tem);++i;};//i表示s的下标
		   if(!root) return;
		   if(root) {tem+=(to_string(root->val) );tem+="->";}//to_string为C++11标准增加
		   if(!root->left&&!root->right) {tem.pop_back();tem.pop_back();s.push_back(tem);return;}
		   dps(root->left,tem,s);
		   dps(root->right,tem,s);//借助tem可以保持中间变量被传入
	        
	   }
    vector<string> binaryTreePaths(TreeNode* root) {
        string tem;vector<string> s;//定义输入变量
		dps(root,tem,s);
		return s;
        

    }
};

```
