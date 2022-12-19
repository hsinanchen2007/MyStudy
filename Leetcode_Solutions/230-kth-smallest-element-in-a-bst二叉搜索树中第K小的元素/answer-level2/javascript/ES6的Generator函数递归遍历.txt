二叉搜索树 又称 二叉排序树，每个节点左子树的所有节点必定小于这个节点。因此想要获取倒数第k小的，只需要中序遍历即可。
```
var kthSmallest = function(root, k) {
	function* inOrderTraverse(t) {
		if(t){
			yield* inOrderTraverse(t.left)
			yield  t.val
			yield* inOrderTraverse(t.right)
		}
	}
	let result = []
	for(let node of inOrderTraverse(root)){
		result.push(node)
	}
	return result[k - 1]
};

```