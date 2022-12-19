**方法一：递归**
前序遍历 
```
class Solution {
	TreeNode* merge(TreeNode* t1, TreeNode*t2){
		TreeNode* cur = t1;
		if (t2 == NULL) return t1;
		if (t1 == NULL) return t2;
		cur->val = t1->val + t2->val;
		cur->left = merge(t1->left, t2->left);
		cur->right = merge(t1->right, t2->right);
		return cur;
	}

public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		return merge(t1, t2);
	}
};

```
**方法二：迭代**
和判断是否为镜像二叉树题的迭代方法类似。对于两棵树t1,t1，对于t1节点为NULL的情况，将其指向对应位置的t2上的节点，若t1，t2对应节点都不为NULL，将两个节点压栈，更新t1节点上的val。
```
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) return t2;
		if (t2 == NULL) return t1;
		stack<TreeNode*>s;
		s.push(t1);
		s.push(t2);
		while (!s.empty()){
			TreeNode* s2 = s.top();
			s.pop();
			TreeNode* s1 = s.top();
			s.pop();
			s1->val = s1->val + s2->val;
			if (s1->left == NULL) s1->left = s2->left;
			else if (s1->left != NULL && s2->left != NULL){
				s.push(s1->left);
				s.push(s2->left);
			}
			if (s1->right == NULL) s1->right = s2->right;
			else if (s1->right != NULL && s2->right != NULL){
				s.push(s1->right);
				s.push(s2->right);
			}
		}
		return t1;
	}
};
```
