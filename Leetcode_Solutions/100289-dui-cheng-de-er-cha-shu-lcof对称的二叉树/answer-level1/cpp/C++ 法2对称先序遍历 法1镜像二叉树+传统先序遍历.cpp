### 解题思路
方法一：
先转换为镜像二叉树，再通过先序遍历（null结点时的值用-1代替）获得两个二叉树的遍历结果，再比较是否相等

方法二：
通过递归的形式进行判断
对于对称的二叉树可以发现先访问根结点，再访问右子树，再访问左子树，两者序列相等；
因此对于其有对称先序遍历法。
我们只需要对两棵子树同时进行先序遍历（A树采用传统先序遍历，B树采用对称先序遍历）
先比较根节点是否相等，再比较A树的左子树和B树的右子树是否相等，再比较A树的右子树和B树的左子树是否相等，如果均相等，返回true
递归边界：
	-	A和B均为null，则递归结束，说明两者均相等，返回true
	- 	A或B为null，则说明两者不会相等，返回false，对于其中的A==null和B==null同时出现，上一句话已经对其特判




### 代码

#### 方法1代码
```cpp

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		vector<int> t1, t2;
		preorder(root, t1);
		preorder(mirrorTree(root), t2);
		for (auto it = t1.begin(); it != t1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		for (auto it = t2.begin(); it != t2.end(); it++)
		{
			cout << *it << " ";
		}
		if (t1 == t2) return true;
		return false;
	}
	//镜像
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL) return NULL;
		else if (root->left != NULL || root->right != NULL)
		{
			swap(root->left, root->right);
			mirrorTree(root->left);
			mirrorTree(root->right);
		}
		return root;
	}
	//先序遍历
	void preorder(TreeNode* root, vector<int>& t)
	{
		if (root == NULL)
		{
			t.push_back(-1);//对于null的值，用-1插入代替
			return;
		}
		t.push_back(root->val);
		preorder(root->left, t);
		preorder(root->right, t);
	}
};
```


#### 方法2代码
```cpp
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
public:
	bool isSymmetric(TreeNode* root) {
		return isMirror(root, root);
	}
	bool isMirror(TreeNode* A, TreeNode* B) {
		if (A == NULL && B == NULL) return true;
		if (A == NULL || B == NULL) return false;
		return (A->val == B->val) && isMirror(A->left, B->right) && isMirror(A->right, B->left);//两者值相同且左右子树相等，则为真，如果有一者不满足，则为假
	}
};
```