# 257. 二叉树的所有路径
**思路：**
采用深度优先遍历（先序遍历）的递归方式，
如果该节点不是叶子节点，则：
	1. 将`（该节点值+"->"）`加入字符串尾部，然后继续递归；
	2.如果该节点是叶子结点，只把`（该节点值）`加入字符串尾部，把结果添加到结果vector中，递归返回。

**注意：递归string参数使用形参的方式，可以省去恢复现场操作。**

**完整代码：**
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	vector<string> rst;
public:
	void binaryTreePathsCicle( TreeNode* &root,string rst_item ){
		if( !(root->left) && !(root->right) ){
			rst.push_back(rst_item+to_string(root->val));
			return;
		}else{
			rst_item += ( to_string(root->val) + "->" );
			if(root->left)
				binaryTreePathsCicle(root->left,rst_item);
			if(root->right)
				binaryTreePathsCicle(root->right,rst_item);
		}
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root){
            binaryTreePathsCicle(root,"");
        }
		return rst;
    }
};
```

