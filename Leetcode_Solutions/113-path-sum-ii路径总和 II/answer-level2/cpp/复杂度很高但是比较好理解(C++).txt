[]()一.  挺像回溯法, 给定tmp,满足条件添加进入res,否则通过回溯进行查找.
```
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		//如果空树,直接返回res.
		if (root == NULL) return res;
		//如果是叶子节点,并且节点值等于sum,满足情况.
		if (root->val == sum&&root->left == NULL&&root->right == NULL){
			//加入sum.
            tmp.push_back(sum);
            res.push_back(tmp);
			//别忘了回溯.
			tmp.pop_back();
			//找到即可返回res.
			return res;
        }
		tmp.push_back(root->val);
		//递归左右子树.
		res = pathSum(root->left, sum - root->val);
		res = pathSum(root->right, sum - root->val);
		//返回之前别忘了回溯.
        tmp.pop_back();
		return res;
	}
};
```

二. 复杂度比较高,大家见笑了.因为初学,所以注释分析代码都会比较详细,欢迎大家关注我的博客,
[我的博客地址链接](https://blog.csdn.net/qieyuan4083)
大家一起学习,共同进步,如果能指出我的不足就更好啦.