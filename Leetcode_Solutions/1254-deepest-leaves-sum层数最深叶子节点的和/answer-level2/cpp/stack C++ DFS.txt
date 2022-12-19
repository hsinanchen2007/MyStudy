### 解题思路
用栈进行DFS，同时记录深度，为了方便，用来 C++ `pair<int, TreeNode*>`，前面$int$记录深度。

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

typedef pair<int, TreeNode*> DNode;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
		if( root == NULL )
			return 0;
		
		stack<DNode> st;
		int depth(0); // 深度，初始化为0
		int ans(0);   // 将返回的结果
		
		st.push(make_pair(depth, root)); // 压入根节点
		while( !st.empty()) {
			DNode no = st.top();
			st.pop();
			
			if(no.first > depth) { // no.first 就是深度，如果更深
				depth = no.first;  // 更新深度
				ans = no.second->val;// 更新和
			}
			else if(no.first == depth) // 如果等于最大深度
				ans += no.second->val; // 累加和
			
			if(no.second->left != NULL) // 压入左节点
				st.push(make_pair(no.first+1, no.second->left));
			if(no.second->right != NULL) // 压入右节点
				st.push(make_pair(no.first+1, no.second->right));
		}
		
		return ans;
    }
};


```