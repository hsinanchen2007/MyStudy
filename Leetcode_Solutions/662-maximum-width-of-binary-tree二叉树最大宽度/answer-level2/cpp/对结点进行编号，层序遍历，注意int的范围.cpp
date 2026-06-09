[@ekulelu](/u/ekulelu/)，在楼主的启发下，遇见了同样问题的我，终于可以做出解答。[楼主的思路](https://leetcode-cn.com/problems/maximum-width-of-binary-tree/solution/yi-ceng-ceng-bian-ma-hou-bian-li-zhu-yi-bian-hao-y/) 我照着实现了一下。
```
typedef pair<TreeNode*, int> MyNode;
int widthOfBinaryTree(TreeNode* root) {
	int width = 0;
	if (!root) return width;
	queue<MyNode> que;
	que.push(make_pair(root, 1));
	while (!que.empty()) {
		int size = que.size(); //取得当前层非空结点数
		int pos = que.front().second; //首个非空结点编号
		for (int i = 0; i < size; ++i) {
			MyNode curr = que.front(); que.pop();
			if (curr.first->left) que.push(make_pair(curr.first->left, 2 * curr.second - pos));
			if (curr.first->right) que.push(make_pair(curr.first->right, 2 * curr.second + 1 - pos));
			width = (curr.second - pos + 1 > width) ? (curr.second - pos + 1) : width;
		}
	}
	return width;
}
```
![image.png](https://pic.leetcode-cn.com/48a9f4f92dc1809ea5c66d23407836a940635c4a0e186efa21eb004c6d4de1c8-image.png)