![截屏2020-03-26下午1.59.14.png](https://pic.leetcode-cn.com/f5f81da55636a5513bca1a38feae227485ff5fb37fae22f6234f2ff10658700d-%E6%88%AA%E5%B1%8F2020-03-26%E4%B8%8B%E5%8D%881.59.14.png)

```
class Solution {
public:
    vector<vector<string> > printTree(TreeNode* root) {
    	int depth = treeDepth(root);
    	int width = pow(2, depth) - 1;
    	vector<vector<string> > res(depth, vector<string>(width, ""));
    	leftFirst(root, res, 0, width - 1, 0);
    	return res;
    }

    //树的前序遍历
    void leftFirst(TreeNode* root, vector<vector<string> >& res, int left, int right, int depth)
    {
    	if(root == NULL) return;
    	int insert = left + (right - left) / 2;
    	res[depth][insert] = to_string(root->val);
    	
    	leftFirst(root->left, res, left, insert - 1, depth + 1);
    	leftFirst(root->right, res, insert + 1, right, depth + 1);
    }

    int treeDepth(TreeNode* root)
    {
    	if(root == NULL) return 0;
    	return max(treeDepth(root->left) + 1, treeDepth(root->right) + 1);
    }
};
```
