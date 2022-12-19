### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p==NULL&&q==NULL) {
			return true;
		}
		if ((p != NULL && q == NULL)|| (p == NULL && q != NULL)||(p->val!=q->val)) {
			return false;
		}

		bool t1=isSameTree(p->left,q->left);
		if (t1 == false) return false;
		bool t2=isSameTree(p->right, q->right);
		if (t2 == false) return false;
		return true;
	}
};
```