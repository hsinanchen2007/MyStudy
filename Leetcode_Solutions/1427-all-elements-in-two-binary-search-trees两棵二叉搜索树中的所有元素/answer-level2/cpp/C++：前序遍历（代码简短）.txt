**题解：**
利用[树的前序遍历](https://blog.csdn.net/qq_43152052/article/details/99746812)将两课树的所有节点值存放在一个数组中，然后将数组排序输出就好了。

**代码如下：**
```cpp
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        helper(root1,res);
        helper(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
    
    void helper(TreeNode* root,vector<int>& result)
	{
    	if(root==nullptr)return;
    	result.push_back(root->val);
    	helper(root->left,result);
    	helper(root->right,result);
	}
};
```
