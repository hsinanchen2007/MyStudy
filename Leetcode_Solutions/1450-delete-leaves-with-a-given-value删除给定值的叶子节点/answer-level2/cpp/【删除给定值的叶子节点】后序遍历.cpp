### 思路
1. 只能删叶子节点
2. 如果叶子节点都删完了，其父节点会变成新的叶子节点
3. 根据特点，使用后序遍历
4. 找到叶子节点，判断是否删除
   41. C++ 注意删除时，不能 delete 传入的参数，指针置空就好
5. 递归

### 答题
```C++
TreeNode* removeLeafNodes(TreeNode* root, int target) 
{
	if (root == nullptr) return nullptr;

	root->left = removeLeafNodes(root->left, target);
	root->right = removeLeafNodes(root->right, target);

	return (root->left == nullptr && root->right == nullptr && root->val == target) ? nullptr : root;
}
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

