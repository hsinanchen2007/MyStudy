参考了别人的思路后，形成了如下思路：
1 前序遍历可用于寻找根结点
2 中序遍历可用于划分左右子树
3 一个结点的左右孩子可以通过中序遍历获取到某些参数后在前序遍历中找出

举个例子：
前序遍历 preorder = [6,5,1,3,2,8]
中序遍历 inorder = [1,5,3,6,2,8]

  显然，根节点为6，然后根据中序遍历，1,5,3是6的左子树 12,8是6的右子树。
在左子树中，一个节点的左孩子就是前序遍历中该节点的下一个节点。因此6的左孩子为5.
6的右孩子也可以在前序遍历中找出，由中序遍历可知，6的左子树节点数为3,因此6的右孩子应该为前序遍历中6的索引+6的左子树结点数量+1，因为前序遍历要把左子树遍历完以后才开始遍历右子树。这样得到右孩子为2.分别以左右孩子作为新的根节点，左右子树作为新的子树进行递归。
```
class Solution {
public:
    map<int,int> inorderdic;
	
	TreeNode* getans(int prenode, int left,int right,vector<int>&preorder){
		if(left>right)return nullptr;
		TreeNode* root=new TreeNode(preorder[prenode]);
		int i=inorderdic[preorder[prenode]];
		root->left=getans(prenode+1,left,i-1,preorder);
		root->right=getans(prenode+i-left+1,i+1,right,preorder);
		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
			inorderdic[inorder[i]]=i;
		}
		return getans(0,0,inorder.size()-1,preorder);
    }
	
      
};
```

