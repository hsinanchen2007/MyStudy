从叶节点开始往上找，叶节点的父节点放置摄像头收益最大，摄像头的爷爷节点等同于一个新的叶节点，循环。

需要特别处理，根节点为叶节点的情况，那就要直接放置一个摄像头了


我们可以设置3种状态
1 //摄像头的子节点，父节点是2
2 //摄像头节点，父节点是0
0 //摄像头的父节点，父节点是一个新的循环的1

首先遍历整个树，把叶节点状态设置为1，并把每个节点压入一个栈中。由于需要完全处理完一层才能处理上一层，因此遍历树时需要使用一个fifo队列。

接着将栈中元素挨个弹出，根据子节点的状态做处理：
子节点的状态为1，则摄像头数量+1，将自己设置为状态2；
子节点状态为2，将自己设置为状态0；
子节点为状态0，将自己设置为状态1，如果自己是根节点，则摄像头数量+1。

```
 class Solution {
 public:
#define BE_WATCHED 1
#define WATCHER 2
#define UNDEAL 0
	 int minCameraCover(TreeNode* root) {
		 queue<TreeNode*> visit;
		 stack<TreeNode*> deal;
		 visit.push(root);
		 while (!visit.empty()) {
			 auto cur = visit.front();
			 visit.pop();
			 if ((!cur->left) && (!cur->right)) {
				 cur->val = BE_WATCHED;
				 if (cur == root)
					 return 1;   //只有根节点的情况直接返回1
			 }
			 else
			 {
				 if (cur->left)
					 visit.push(cur->left);
				 if (cur->right)
					 visit.push(cur->right);
			 }
			 deal.push(cur);
		 }
		 int camCount = 0;
		 while (!deal.empty()) {
			 auto cur = deal.top();
			 deal.pop();
			 if ((cur->left&&cur->left->val == BE_WATCHED) || (cur->right&&cur->right->val == BE_WATCHED)) {
				 cur->val = WATCHER;
				 camCount++;
			 }
			 else if ((cur->left&&cur->left->val == WATCHER) || (cur->right&&cur->right->val == WATCHER)) {
				 cur->val = UNDEAL;
			 }
			 else if ((cur->left&&cur->left->val == UNDEAL) || (cur->right&&cur->right->val == UNDEAL)) {
				 if (cur == root) {
					 cur->val == WATCHER;
					 camCount++;
				 }
				 cur->val = BE_WATCHED;
			 }
		 }
		 return camCount;
	 }
 };
```
