## 方法一：递归

```cpp
class Solution {
public:
	TreeNode* RebuildBinaryTree (vector<int>& pre, vector<int>& in) {
	    if (pre.size() == 0 || in.size() == 0)
	        return NULL;

	    TreeNode *root = new TreeNode(pre[0]);  // 「前序」遍历首元素作为根节点

		vector<int> pre_left, pre_right;  // 前序遍历左段、右段
		vector<int> in_left, in_right;  // 中序遍历左段、右段

	    size_t count_left = 0;
	    for (size_t i = 0; i < in.size(); i++) {
	        if (in[i] == pre[0])  // 在中序遍历序列中定位 i 的位置
	            break;
	        count_left++;
	    }

	    for (size_t i = 1; i < pre.size(); i++) {
	        if (i <= count_left)
	            pre_left.push_back(pre[i]);  // pre 左段加入 pre_left
	        else
	            pre_right.push_back(pre[i]);  // pre 右段加入 pre_right
	    }

	    for (size_t i = 0; i < in.size(); i++) {
	        if (i < count_left)
	            in_left.push_back(in[i]);  // in 左段加入 in_left
	        else if (i > count_left)
	            in_right.push_back(in[i]);  // in 右段加入 in_right
	    }
		// 递归
	    root->left  = RebuildBinaryTree(pre_left, in_left);
	    root->right = RebuildBinaryTree(pre_right, in_right);

	    return root;
	}
};

```

## 方法二：DFS
```cpp
class Solution {
public:
    // int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if ( preorder.empty() || inorder.empty() )
            return nullptr;
        int idx = 0;
        return dfs( preorder, inorder, 0, preorder.size()-1, idx );
    }

    TreeNode* dfs( vector<int>& preorder, vector<int>& inorder, int left, int right, int& idx ) {
        int pivot = 0; 
        while ( pivot <= right ) {
            if ( preorder[idx] == inorder[pivot] )
                break;
            ++pivot;
        }

        TreeNode* cur = new TreeNode( inorder[pivot] );
        if ( left <= pivot-1 ) {
            ++idx;
            cur->left = dfs( preorder, inorder, left, pivot-1, idx );
        }
        if ( pivot+1 <= right ) {
            ++idx;
            cur->right = dfs( preorder, inorder, pivot+1, right, idx );
        }

        return cur;
    }
};
```