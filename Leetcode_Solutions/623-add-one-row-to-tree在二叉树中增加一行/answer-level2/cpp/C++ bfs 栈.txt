### 解题思路
找到第 d - 1 的节点，修改指针。

### 代码

```cpp
typedef pair<TreeNode*, int> P;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* node = new TreeNode(v);
			node->left = root;
			return node;
		}
		
		queue<P> qu;
		qu.push({root, 1});
		
		while (!qu.empty()) {
			P cur = qu.front();
			qu.pop();
			
			if (cur.second == d-1) { // 修改该层的指针
				TreeNode* L = new TreeNode(v); // 新左节点
				L->left = (cur.first)->left; // right 指针已经初始化为NULL
				(cur.first)->left = L;
				
				TreeNode* R = new TreeNode(v);// 新右节点
				R->right = (cur.first)->right;
				(cur.first)->right = R;
			}
			
			if (cur.second >= d) // 如果已经超过 d-1 层，终止
				break;
			
			if ((cur.first)->left != NULL)
				qu.push({(cur.first)->left, cur.second + 1});
			if ((cur.first)->right != NULL)
				qu.push({(cur.first)->right, cur.second + 1});
		}
		return root;
    }
};
```