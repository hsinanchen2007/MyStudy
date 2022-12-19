### 解题思路
+ 首先的想法是结合LeetCode102题，直接取每一层的最后一个元素拼接成ans
+ 但是这样比较浪费空间，毕竟得开一个二维数组把每一层存下来
+ 可不可以在每次层数跳变的时候将树节点的val记录下来呢？
+ 可以。那么每层从左往右遍历时，已知跳变的时候其实已经是对下一层的第一个节点的访问了，这个时候将上一层末尾节点push到答案数组中似乎比较麻烦（也不是不行）
+ 显然这样更容易记录从左往右看去的side view，那么为了记录从右往左看去的side view，直接每层从右往左遍历即可

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
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		if(!root)	return ans;
		queue<pair<int, TreeNode*>> Q;
		Q.push(make_pair(0, root));
		int pre = -1, now;
		TreeNode* node;
		while(!Q.empty()) {
			now = Q.front().first;
			node = Q.front().second;
			Q.pop();
			if(node) {
				Q.push(make_pair(now + 1, node->right));
				Q.push(make_pair(now + 1, node->left));
			}
			if(now == pre + 1 && node){
				ans.push_back(node->val);
				pre = now;		// 注意只有层数发生跳变的时候更新pre
			}
		}
		return ans;
	}
};



```

![图片.png](https://pic.leetcode-cn.com/850eb5ce1515d23e6eef4c896de868c1a32b8d6dbee32525dd7b9640903e0959-%E5%9B%BE%E7%89%87.png)
