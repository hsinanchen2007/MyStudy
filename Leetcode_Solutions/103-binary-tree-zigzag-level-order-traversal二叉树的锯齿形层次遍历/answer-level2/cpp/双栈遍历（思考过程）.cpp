### 解题思路
很奇特的一道BFS题目，居然使用的是栈。这里记录一下我的思考过程。
+ 首先想到的是能不能还是利用``queue``，希望通过改变入队顺序来实现zig-zag，但很容易发现反例。比如``[3, 9, 20, 6, 10, 15, 7]``，如果入队顺序是3, 20, 9, 15, 7, 6, 10……显然理论上需要9先出队才对。
+ 由以上“后入先出”原理知道应该使用栈，且一个栈搞不定(否则两行的数会混在一起去)。想了一下用一个双端队列也可行，但是每次还得判断一下从哪边出，哪边入，太麻烦且容易出错。 
+ 循环在两个栈都为空时退出。循环体内只需要判断s1和s2哪个不为空（每次新进入循环必定一个为空一个不为空），选择相应的分支进行下一层的遍历。这里我们约定：s1针对0,2,4,...层，s2针对1,3,5,...层
+ 注意奇偶层数的入栈顺序相反

![图片.png](https://pic.leetcode-cn.com/06e4cda4bdc87a2f2baea99cec5af7cc9ff048d83c1d12ebaa61c3aefc78c953-%E5%9B%BE%E7%89%87.png)

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(!root)	return ans;
		stack<TreeNode*> s1, s2;
		s1.push(root);
		TreeNode* t;
		int cur;
		while(!s1.empty() || !s2.empty()) {
			if(!s1.empty()) {
				cur = ans.size();
				ans.push_back(vector<int>());
				while(!s1.empty()) {
					t = s1.top();
					s1.pop();
					if(t) {
						ans[cur].push_back(t->val);
						s2.push(t->left);
						s2.push(t->right);
					}
				}
			}
			else if(!s2.empty()) {
				cur = ans.size();
				ans.push_back(vector<int>());
				while(!s2.empty()) {
					t = s2.top();
					s2.pop();
					if(t) {
						ans[cur].push_back(t->val);
						s1.push(t->right);
						s1.push(t->left);
					}
				}
			}
		}
		ans.pop_back();		// 由于最后的栈中一定全是nullptr所以ans的最后一个元素一定是[]，需要去掉
		return ans;
	}
};


```
