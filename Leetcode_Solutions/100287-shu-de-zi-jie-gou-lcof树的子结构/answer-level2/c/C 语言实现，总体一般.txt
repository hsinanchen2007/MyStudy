![图片.png](https://pic.leetcode-cn.com/5df60ac6d332e3169c51394c6f4d7705d8ed955792ed0166c5586b53f6a5113e-%E5%9B%BE%E7%89%87.png)

提示一个很重要的点：**二叉树**不是**二叉搜索树**，也就不存在二叉树的性质。我由于想当然，在这里栽了不少跟头。

如果有同学存在疑问的话，请在下面提出，我尽量解答。

```
typedef struct TreeNode *BTree;

bool
isMatch( BTree A, BTree B )
{
	if ( B == NULL )
		return true;
	else
	if ( A == NULL )
		return false;
	else
	if ( A->val == B->val )
		return isMatch( A->left, B->left ) &&
			isMatch( A->right, B->right );

	return false;
}

void
findNode( bool *mat, BTree A, BTree B ) 
{
	if ( A == NULL )
		return;
	else
	{
		if ( A->val == B->val )
			*mat = *mat || ( isMatch( A->left, B->left ) && 
				isMatch( A->right, B->right ) );
		
		findNode( mat, A->left, B );
		findNode( mat, A->right, B );
	}
}

bool
isSubStructure( BTree A, BTree B )
{
	bool match = false;

	if ( A == NULL || B == NULL )
		return false;
	else
		findNode( &match, A, B );

	return match;
}
```
