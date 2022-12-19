### 思路
首先，找到要删除的节点，这个简单。  
然后，删除操作需要考虑 3 种情况？  
怎么那么麻烦，算了，写个方法 `funDelete` 负责删除吧。  
> **这段故意犯蠢可以不看**  
> ```C++
> TreeNode* deleteNode(TreeNode* root, int key)
> {
> 	TreeNode *pNode = root;
> 	while (pNode != nullptr)
> 	{
> 		if (key == pNode->val) funDelete(pNode); 
> 		else if (key < pNode->val) pNode = pNode->left;
> 		else pNode = pNode->right;
> 	}
> 	return root;
> }
> ```
> 好，完成！  
> ：P  
> 
> 不闹了，回来看一下，
   

删除操作需要考虑 3 种情况：  
1. 左右都空。  
2. 左边空或者右边空。  
3. 左右都有。  

  
#### 情况 2
![例子2](https://pic.leetcode-cn.com/84dc76008c38a27f46f5e7229e548046a8a4e39544015df66791d92485077e97.png)  
先分析一下第二种情况，具体要怎么操作。  
> **这段故意犯蠢可以不看**
> 1. 记录父节点。  
> 2. 判断是父节点的左孩子还是右孩子。
> 3. 判断要删除的节点是左边有孩子还是右边有孩子。
> 4. 父节点的左孩子赋值成删除节点的左孩子。
> 5. 或者，父节点的左孩子赋值成删除节点的右孩子。
> 6. 或者，父节点的右孩子赋值成删除节点的左孩子。
> 7. 或者，父节点的右孩子赋值成删除节点的右孩子。
> 5. 删除这个节点。  
> 累死了。。。  
> 
> 不能这么搞，想个更好的办法吧。  

可以使用指向指针的指针，`TreeNode**`。  
如上面 **例子2** ，如果我要删除 **节点6** ，那么我只需要存 **节点5** 的 `right` 的地址，加一个*就是要删除的 **节点6** 。  
1. 拿到指向删除节点的指针地址 `**p`。
2. 用一个临时变量保存要删除的节点的孩子。
3. 删除 `*p`。
4. `*p` 赋值成临时变量。

#### 情况 1
![例子1](https://pic.leetcode-cn.com/c86c275c89d84db199d766f3c389caadcb0606c3f12316dc7dd05d31794f6ce8.png)  
为啥上来跳过 **情况 1** ，直接分析 **情况 2** ？  
因为这么操作下来，其实已经覆盖了 **情况 1** ，所以代码里只有 2 种处理。  

**情况 2** 里要删除的节点有一边是空的，用临时变量保存另一边，然后接上。    
**情况 1** 的区别就是另一边也是空的，那临时变量保存的也是空，然后接上。  
没啥影响嘛，代码复用。  

#### 情况 3
![例子3](https://pic.leetcode-cn.com/d376921c5f208b3f59b71bdbe16cc3b02556e443648aaad7f19b5f58e9244f25.png)  
第三种情况的核心思想就是说，既然左右都有孩子，我又不想大动干戈旋转节点之类的。  
那我就从左右子树里找到一个值，这个值大于所有左子树，小于所有右子树。  
所以光看上面的 **例子3** ，太随意了，根本不能好好的表现出我们到底要找的是谁。  

我补个图：  
```
          5
   /              \
  1                9
   \              /
    2            8
     \          /
      3        7
       \      /
        4    6
```
相信看了这个图，大家看了一定就懂了！  
  
如果要删除的是 **节点5** ，  
那你要找的替代值一定就是 `->left` 的 `->right->right->right` …………  
如果 `left` 不行，那就找 `->right` 的 `->left->left->left` …………  
这是由二叉搜索树的特点保证的。  


那假设现在找到 **节点4** 了，要怎么操作。  
1. 把 **节点5** 的 `val` 赋值成 **节点4** 的 `val`。
2. 用 `funDelete()` 把 **节点4** 删了。

> 给我们的删除方法加个返回值，返回删除节点的值val，那操作就更加顺畅了。  


接下来还有一个问题，  
如果 `left` 没有 `->right` ， `right` 没有 `->left` ，两边都不行呢？  
```
          5
   /              \
  1                9
```  
既然这样， **节点1** 和 **节点9** 不就是 **情况 2** （左边空或者右边空）了嘛。  
走一样的套路处理，代码都复用。  
1. 把 **节点5** 的 `val` 赋值成 **节点1** 的 `val` 。
2. 用 `funDelete()` 把 **节点1** 删了。

这样 **情况 3** 就全部处理完了。


### 答题
```C++
int funDelete(TreeNode **ppNode)
{
	int res = (*ppNode)->val;
	if ((*ppNode)->left == nullptr || (*ppNode)->right == nullptr)
	{
		TreeNode *pChild = ((*ppNode)->left != nullptr) ? (*ppNode)->left : (*ppNode)->right;
		delete (*ppNode);
		*ppNode = pChild;
	}
	else
	{
		TreeNode **ppChild = &((*ppNode)->left->right);
		while ((*ppChild) != nullptr && (*ppChild)->right != nullptr) ppChild = &((*ppChild)->right);
		
		if ((*ppChild) == nullptr)
		{
			ppChild = &((*ppNode)->right->left);
			while ((*ppChild) != nullptr && (*ppChild)->left != nullptr) ppChild = &((*ppChild)->left);
		}

		if ((*ppChild) == nullptr) ppChild = &((*ppNode)->right);

		(*ppNode)->val = funDelete(ppChild);
	}
	return res;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
	TreeNode **ppNode = &root;
	while ((*ppNode) != nullptr)
	{
		if (key == (*ppNode)->val)
		{
			funDelete(ppNode);
			return root;
		}
		if (key < (*ppNode)->val)
		{
			ppNode = &((*ppNode)->left);
		}
		else
		{
			ppNode = &((*ppNode)->right);
		}
	}
	return root;
}
```

执行用时：28 ms，打败了100%，感觉很开心！   


### 调试
```
[1,0,15,null,null,4,35,3,8,25,49,2,null,5,12,21,27,47,null,null,null,null,7,11,13,19,24,26,31,40,48,6,null,9,null,null,14,17,20,23,null,null,null,30,33,39,42,null,null,null,null,null,10,null,null,16,18,null,null,null,null,28,null,32,34,36,null,41,44,null,null,null,null,null,null,null,29,null,null,null,null,null,37,null,null,43,46,null,null,null,38,null,null,45]  
```
当用例报错，给你返回了这么一传字符串的时候，头大怎么办。  

不要慌！  
先使用 **[二叉树的序列化与反序列化](https://github.com/AhJo53589/leetcode-cn/blob/master/problems/297.serialize-and-deserialize-binary-tree/README.md)** 把字符串转成二叉树，  
然后使用 **[二叉树的中序遍历](https://github.com/AhJo53589/leetcode-cn/blob/master/problems/94.binary-tree-inorder-traversal/README.md)** 把二叉树转换成数组，  
根据二叉搜索树特点，返回的数组应该是升序排列，  
如果其中哪个值逆序了，那就是它错了。  

> **别问我是怎么知道的**


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)