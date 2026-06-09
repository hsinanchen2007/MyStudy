# 230. 二叉搜索树中第K小的元素
**思路：**

- 由于传入的是一颗二叉搜索树，其每个节点中左子树的值都小于根节点值、右子树值都大于根节点值。如果按照中序遍历（左->根->右）的次序遍历每个节点，刚好可以升序的遍历这个二叉搜索树。
- 我们需要找到二叉搜索树第k小的元素就是中序遍历到二叉搜索树第k个非空节点。可以采用中序遍历的递归模板。
- 由于当我们找到最小节点后就无须在递归遍历儿二叉搜索树，所以我们进行判断，当k为0时立即返回。第一次使k为0的节点就是答案节点。

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
	int rst;
public:
	void recursion(TreeNode* temp, int &k) {
		if(temp != NULL) {
			recursion(temp->left,k);
			if(k == 0)
				return;
			else if((--k) == 0)
				rst = temp->val;
			else
				recursion(temp->right,k);
		}
	}
	
    int kthSmallest(TreeNode* root, int k) {
		if(root != NULL)
			recursion(root,k);
        return rst;
    }
};
```
