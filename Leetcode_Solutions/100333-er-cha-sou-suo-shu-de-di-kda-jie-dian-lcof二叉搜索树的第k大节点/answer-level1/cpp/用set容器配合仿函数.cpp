### 解题思路
二叉搜索树本身无重复，可以用set容器，自定义仿函数进行排序。

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

class f1
{
public:
	bool operator() (const TreeNode *p1, const TreeNode *p2) const{
		return p1->val > p2->val;
	}
};
class Solution {
public:
    int kthLargest(TreeNode* pRoot, int k) {
        //priority_queue，map，set
		if (pRoot == NULL) {
			return 0;
		}
		//左<根<右
		set<TreeNode*, f1> res;
		pre(pRoot, res);
		set<TreeNode*, f1>::iterator it = res.begin();
		if (k == 1) {
			return (*it)->val;
		}
		for (int i = 2; i <= k; ++i) {
			++it;
		}
		return (*it)->val;
	}

    void pre(TreeNode *p, set<TreeNode*, f1> &res){
        if(p == NULL){
            return;
        }
        res.insert(p);
        pre(p->left, res);
        pre(p->right, res);
    }
};
```