### 解题思路
中序遍历BST，序列是从小到大排列的，而逆中序遍历，结果是从大到小排列的，在遍历过程中记录该结点属于第几个并和k比较，如果是则保持结果，最后返回的结果即为答案

### 代码

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
/*逆中序遍历*/
class Solution {
public:
	//使用成员变量记录代替使用引用的方式
	int n=0;
	int res = 0;
	int kthLargest(TreeNode* root, int k) {
		if (root == NULL || k < 1) return 0;
		//先访问右子树
		kthLargest(root->right, k);
		//访问根结点
		n++;
		if (n == k) res=root->val;//n==k，res保存该节点的值
		//访问右子树
		kthLargest(root->left, k);
		return res;
	}

};
```