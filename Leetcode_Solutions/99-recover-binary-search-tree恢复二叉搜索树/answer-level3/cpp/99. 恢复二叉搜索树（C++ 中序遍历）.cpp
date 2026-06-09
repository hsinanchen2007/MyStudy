# 99. 恢复二叉搜索树
**思路：**

- 题目给出了一颗二叉搜索树，并且只改变了其中**两个**节点的相对位置，使得该二叉搜索树不规范。我们需要找到俩两个点的位置，恢复该二叉搜索树。
- 根据二叉搜索树的定义，如果对一个二叉搜索树进行中序遍历，可以得到一个升序的序列。根据这个规则如果对两个节点发生错误的二叉搜索树进行中序遍历，**所得到的序列中应该有两个不符合中序的值**。

**所以：**
- 我们需要做的就是遍历这颗发生错误的二叉搜索树，找到两个错误的点。将两节点值进行替换。
- 在遍历过程中，不需要知道这个整个中序遍历序列，只需要每个节点的值与前一个序列节点值进行比较。
- 这样只需每次记录该序列中当前结点前一个结点，并把两值进行比较。所以需要创建三个全局变量结点指针，用于指向第一个异常点、第二个异常点、以及遍历到结点的前一个结点：
```
	TreeNode* first = nullptr;		//用于记录第一个错值结点
	TreeNode* second = nullptr;		//用于记录第二个错值结点
	TreeNode* preNode = nullptr;	        //用于记录中序遍历前一个结点
```

- 然后遵循以下逻辑：
    1. 当preNode不空，first为空的情况下，如果preNode结点值大于该节点值，则赋值first点为preNode
    2. 当preNode不空，first不空的情况下，如果preNode值大于该节点值，则赋值second点为当前节点

```
                //第一个错值节点为空的情况下，如果中序遍历前一个结点值大于该节点值，则赋值第一个错值节
		if(	first == nullptr && 	
			preNode != nullptr &&
			preNode->val >= root->val )
			first = preNode;
		//第一个错值节点不为空的情况下，如果中序遍历前一个结点值大于该节点值，则赋值第二个错值节
		if( first != nullptr && 
			preNode != nullptr &&
			preNode->val >= root->val )
			second = root;
```
# 这里需要注意一点，由于判断顺序的原因，只要发生错值就会同时连续赋值两个错值点。这样是为了处理两个错值点在中序序列中恰好连续的特殊情况。换句话说second保存的将是最后一个可能的错值点，first保存的是第一次出现的错值点。
- 完成整个中序遍历后吧两点值交换即可。
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
	TreeNode* first = nullptr;		//用于记录第一个错值结点
	TreeNode* second = nullptr;		//用于记录第二个错值结点
	TreeNode* preNode = nullptr;	//用于记录中序遍历前一个结点
public:
	void recrusion(TreeNode* root) {
		if(	root == nullptr )		//递归到空节点直接返回
			return;
		
		recrusion(root->left);		//递归左子树
		
		//第一个错值节点为空的情况下，如果中序遍历前一个结点值大于该节点值，则赋值第一个错值节
		if(	first == nullptr && 	
			preNode != nullptr &&
			preNode->val >= root->val )
			first = preNode;
		//第一个错值节点不为空的情况下，如果中序遍历前一个结点值大于该节点值，则赋值第二个错值节
		if( first != nullptr && 
			preNode != nullptr &&
			preNode->val >= root->val )
			second = root;
		preNode = root;		//中序遍历前一个结点赋值
		
		recrusion(root->right);		//递归右子树
	}
	
    void recoverTree(TreeNode* root) {
        recrusion(root);
		if(first != nullptr && second != nullptr){
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
    }
	
};
```
