后序遍历，moneyneed函数返回的是这个节点需要从上面那个节点借多少钱或者拿多少钱，所有节点借和拿的abs总和就是答案
主要思路：做的时候从最上边的根节点开始很难，因为要考虑同时平衡两边，这时从只有一个相连节点的节点（就是最左边的这个节点）开始就可以一次只考虑一边
class Solution {
public:
	int distributeCoins(TreeNode* root) {
		int moves = 0;
		moneyneed(root, moves);

		return moves;
	}
	int moneyneed(TreeNode* root, int &moves) {
		if (!root->left && !root->right) {
			return root->val - 1;//钱少了就是负数 钱多了就是正数
		}
		int left = 0, right = 0;
		if (root->left) {
			left = moneyneed(root->left, moves);
		}
		if (root->right) {
			right = moneyneed(root->right, moves);
		}

		int res = left + right+ root->val-1;
		moves += abs(left)+abs(right);

		return res;
	}
};