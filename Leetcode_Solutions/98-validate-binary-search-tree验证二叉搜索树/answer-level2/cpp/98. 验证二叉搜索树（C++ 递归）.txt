# 98. 验证二叉搜索树
**思路：**
# 1.首先要清楚什么是二叉搜索树
**二叉搜索树的要求：**
    1. 其每个节点的左子树节点的值都小于该节点值；
    2. 其每个节点的右子树节点的值都大于该节点值。

**通过上述可以看出，二叉搜索树判断问题可以归结到每个节点中，所可以一采用深度优先遍历的方式递归查询每个节点。在做判断。**

# 2.递归策略

1. 由于结果是返回是不是二叉搜索树，所以返回值是bool类型。
同时，在比较中，只要有一节点不符和二叉搜索树，整体就不是二叉搜索树，即产生false后，就不需要在递归了。
1. 具体到每个节点中，我们不能只把该节点的值和下一层相比较，而是需要和整个左子树节点值还有右子树节点值相比较。
这样我们每次递归中，就需要记录四个值：

      - **左子树节点中的最小值**--用于返回以该节点为根节点，树节点的最小值。
      - **左子树节点中的最大值**--用于返回以该节点左子树为根节点，树节点的最大值。（用于与该节点值比较）。
      - **右子树节点中的最大值**--用于返回以该节点为根节点，树节点的最大值。
      - **右子树节点中的最小值**--用于返回以该节点右子树为根节点，树节点的最小值。（用于与该节点值比较）。


1. 得到这些值后我们需要和该节点值进行比较，如果:

    - `（左子树节点中的最大值 >= 该节点值） //左节点错误，递归返回false`
    - `（右子树节点中的最小值 <= 该节点值） //右节点错误，递归返回false`


1. 正确的话就复制该节点的最大最小值到上层，继续比较。
2. **底层判断：**
如果该节点没有左子树的话，就认为该点值就是最小的；
同理，如果该节点没有右子树的话，就认为该点值就是最大的；

# 3.代码实现

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
public:
	bool isValidBSTCicle(TreeNode* root,int &num_min,int &num_max){
		bool rst = true;
		int min_left;
		int max_left;
		int min_right;
		int max_right;
		
		if( root->left ){
			rst = isValidBSTCicle(root->left,min_left,max_left);
			if(rst)
				if( root->val <= max_left )
					return false;
				else
					num_min = min_left;
		}else
			num_min = root->val;
		
		if(rst)
			if( root->right ){
				rst = isValidBSTCicle(root->right,min_right,max_right);
				if(rst)
					if( root->val >= min_right )
						return false;
					else
						num_max = max_right;
			}else
				num_max = root->val;
		return rst;
	}
	
    bool isValidBST(TreeNode* root) {
		bool rst = true;
                if( root ){
			int max,min;
			rst = isValidBSTCicle(root,max,min);
		}
		return rst;	
    }
};
```
