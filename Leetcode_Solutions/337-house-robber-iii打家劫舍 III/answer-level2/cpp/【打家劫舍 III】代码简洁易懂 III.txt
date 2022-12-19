### 题目
二叉树结构的小区，相邻的房子不能同时偷。  

### 方法一：暴力递归

例子1：  
```
        a
       / \
      b   c
     / \ / \
    d  e f  g
```
看明白题，也就是说选 a 不能选 bc。  
那么，  
如果选择 a，那么 bc 不能选择，还要加上 defg 递归的结果，作为 sum1。  
如果不选择 a，那么就可以对 bc 进行递归求解，作为 sum2。  
递归的结束条件为传入的指针为 NULL。  

最后 `max(sum1, sum2)` 得到最优解。  

注意需要使用 cache 来记录中间结果，不然会超时。  

#### 答题
``` C++
vector<TreeNode *>getAllChild(vector<TreeNode *>pNode)
{
	vector<TreeNode *> pChild;
	if (pNode.empty()) return pChild;
	for (auto p : pNode)
	{
		if (p == NULL) continue;
		if (p->left != NULL) pChild.push_back(p->left);
		if (p->right != NULL) pChild.push_back(p->right);
	}
	return pChild;
}

unordered_map<TreeNode *, int> robMemo;
int rob(TreeNode* pNode)
{
	if (pNode == NULL) return 0;
	if (robMemo.count(pNode)) return robMemo[pNode];
	int sum = 0;

	// rob this house and prepare rob "child-child" houses
	sum = pNode->val;
	vector<TreeNode *> pChild = getAllChild({ pNode });
	pChild = getAllChild({ pChild });
	for (auto p : pChild) sum += rob(p);

	// rob "child" houses
	sum = max(sum, rob(pNode->left) + rob(pNode->right));

	// Memo
	robMemo[pNode] = sum;
	return sum;
}
```

### 方法二：动态规划，通过后序遍历，自下向上逐步求解

相比 打家劫舍 12 来说，这道题无法**简单的**一条直线的思考下去，从上向下每次都要分支。  
但是，如果从下往上来处理问题，每次将分支合成一处，就可以使用以前题目相似的思路来解决了。  
通过后序遍历，就可以做到自下向上了。  
所以写个后序遍历先。  


例子1：  
```
        a
       / \
      b   c
     / \ / \
    d  e f  g
```
1. 如这个例子，后序遍历最先处理的将会是 defg 结点。  
这些结点没有子结点，很容易得出他们的值是自身。  

2. 再下来会处理 bc。我们只看 bde 这颗子树。  
选择只有两种，b 或者 de。而最优解则是他们两个取 max。  

3. 然后处理 a。  
先看 abc 这颗子树，跟第 2 点似乎一样，a 或者 bc。  
但区别是，整体来看，我的选择可以有 adefg 和 bc 两种（这里先简化只考虑这两种情况）。  
选 bc 可以说就是自身的值，不取 bc 时，defg 的值需要传递上来。  

4. 这里我使用两个变量来记录一个结点的两个值。========让我瞎起个名字吧 ：）  
一个是明值（包含自己的值，以及所有子结点的暗值的和。代码中 `index = 0`）  
一个是暗值（不包含自己的值，包含所有子结点的最优解。代码中 `index = 1`）  

5. 处理结点时，通过计算得到初始的明值（p->val + p->left 暗值 + p->right暗值），  
初始的暗值（p->left明值 + p->right明值）。  
最后如果这个结点的明值没有暗值大，那么明值将更新成暗值的值，即更新成最优解，明值 = max(明值, 暗值)。  


例子2：  
```
        a
       / \
    b=3   c
     / \ / \
    d  e f  g
    2  2
```
6. 通过这样的处理。  
看一下 bde 这个子树，处理 b 结点时，b的明值会等于自己（3），b 的暗值会等于 de 的明值（2 + 2）。  
然后更新最优解，b的明值等于（2 + 2），暗值也是（2 + 2）。  
再处理 a 结点时，选择 a，那么a  的明值 = a + b 的暗值 + c 的暗值。  
选择 bc，那么 a 的暗值 = b 的明值 + c 的明值。  
无论怎么选择，de 的最优解都会传递上去。  

7. 持续不断向上处理，将最优解积累和传递上去。  

8. 当一切结束的时候，返回根结点的明值。  


#### 答题  
```C++
void PostOrder(TreeNode *root, vector<TreeNode *>&pNodeList)
{
	if (root == NULL) return;
	if (root->left != NULL) PostOrder(root->left, pNodeList);
	if (root->right != NULL) PostOrder(root->right, pNodeList);
	pNodeList.push_back(root);
}

unordered_map<TreeNode *, int> robMemo[2];
int rob(TreeNode* pNode)
{
	if (pNode == NULL) return 0;
	vector<TreeNode *> pNodeList;
	PostOrder(pNode, pNodeList);

	for (auto p : pNodeList)
	{
		int s[2] = { 0,0 };	// 0 == include node val, 1 == not include node val

		s[0] = p->val;
		if (p->left != NULL) s[0] += robMemo[1][p->left];
		if (p->right != NULL) s[0] += robMemo[1][p->right];

		if (p->left != NULL) s[1] += robMemo[0][p->left];
		if (p->right != NULL) s[1] += robMemo[0][p->right];

		s[0] = max(s[0], s[1]);	// copy best val

		robMemo[0][p] = s[0];
		robMemo[1][p] = s[1];
	}
	return robMemo[0][pNode];
}
```

### 其它
[【打家劫舍】 代码简洁易懂](https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-ikaruga/)  
[【打家劫舍 II】代码简洁易懂 II](https://leetcode-cn.com/problems/house-robber-ii/solution/da-jia-jie-she-ii-dai-ma-jian-ji-yi-dong-ii-by-ika/)  


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)